/**
==================================================

	BusDevice.cpp
	
Version: $Rev$
Last Modification: $Id$

Module: 
Created: 01.07.2007
Author: ig

Copyright 2007 by iSysBus

==================================================
*/
#include <string>
#ifdef _WIN32
#include <windows.h>
#endif

#include "Settings.h"
#include "DbLogger.h"
#include "BusDevice.h"
#include "Tools.h"
#include "Connection.h"
#include "frameparser.h"
#include <iomanip>

#include <log4cxx/logger.h>
#include <boost/bind.hpp>

#include "server.h"


using namespace std;
using namespace boost::asio;

BusDevice::BusDevice(io_service &io,Settings &s,DbLogger &dbLogger) : 
	active(true),
	io_(io), 
	serial(io),
	settings(s),
	m_dbLogger(dbLogger),
	fp(s.isRegenerate()),
	frameAvailable(false) {
	frameData="";
	logger = log4cxx::Logger::getLogger("org.isysbus.BusDevice");
	LOG4CXX_DEBUG(logger,"BusDevice thread started");
	open();
	startRead();
}


void BusDevice::doClose(boost::system::error_code error ) {
	if (error == boost::asio::error::operation_aborted) {
		return; // ignore it because the connection cancelled the timer
	}

	if (error) {
		LOG4CXX_ERROR(logger, "Error: " << error.message());
	} else {
		LOG4CXX_ERROR(logger, "Error: Connection failure");
		serial.close();
		active = false; 
	}
}

void BusDevice::startRead() {
	LOG4CXX_TRACE(logger,"startRead called");
	// async read till we receive a complete frame...
	serial.async_read_some(boost::asio::buffer(rcvBuffer, BUFSIZE), 
	                       boost::bind(&BusDevice::readHandler,
                           this,
               		       boost::asio::placeholders::error,
                           boost::asio::placeholders::bytes_transferred));
}

void BusDevice::open() {
	string portname;

	portname = settings.getCOMPort();
	serial.open(portname);

	// baudrate from settings TODO: check for WRONG baudrates 	
	int baudrate = settings.getBaudrate();
	serial_port_base::baud_rate baud(baudrate);

	// 8N1 
	serial_port_base::character_size databits( 8 );
	serial_port_base::parity parity(serial_port_base::parity::none);
	serial_port_base::stop_bits stopbits(serial_port_base::stop_bits::one);
	
	// no flow control
	serial_port_base::flow_control flow(serial_port_base::flow_control::none);
        serial.set_option(flow);

	serial.set_option( baud );
        serial.set_option( databits);
        serial.set_option( parity);
        serial.set_option( stopbits );
	
	if (not serial.is_open()) {
         LOG4CXX_ERROR(logger, "Failed to open serial port" << portname);
         return;
    } 
	LOG4CXX_INFO(logger,"Opened Port " + portname); 
}

void BusDevice::readHandler( const boost::system::error_code& error, std::size_t bytes_transferred ) {
	LOG4CXX_TRACE(logger, "readHandler called");

	if ( ! error ) {
			frameSize +=bytes_transferred;	
			
			LOG4CXX_DEBUG(logger,"Received data from bus: " << Tools::hexDump((unsigned char *) rcvBuffer,bytes_transferred) << " size:" <<bytes_transferred);	
			LOG4CXX_DEBUG(logger,"Frame buffer: " << Tools::hexDump(frameData) << " size:" << frameData.length());	
			
			// copy the temporary data to the framedata 
			frameData.append((const char *)  rcvBuffer,bytes_transferred);

			vector<Packet> packets = fp.parse(frameData,settings.getProtocol());
			
			if ( packets.size()>0) {
				LOG4CXX_DEBUG(logger,"Received " << packets.size() << " packets, notifying about read");
				
				for (std::vector<Packet>::iterator it = packets.begin();it != packets.end(); ++it) {
					m_dbLogger.logPacket(*it);
					rcvSignal(*it); // srv->notifyRead(*it);
				}
				frameAvailable =true;
			}
	
			if ( isActive()) {
				startRead();
			}
	} else {
		LOG4CXX_ERROR(logger,"Error during async receive" << error);
		doClose(error);
	}
}

bool BusDevice::isFrameAvailable() {
	return frameAvailable;
}

/**
 * Send a message
 * Returns the number of characters that could not be sent
 * or -1 if the queue is full
 * 
 * @param Data to send
 * @returns -1 in case of error, 0 if all data could be added to the queue
 */
int BusDevice::send(Packet pkt) {
	if (pkt.isValid()) {
		m_dbLogger.logPacket(pkt);
		io_.post(boost::bind(&BusDevice::write, this, pkt)); 
		LOG4CXX_DEBUG(logger,"Enqueued send: " <<  pkt.hexDump());
		return 0;
	} else {
		LOG4CXX_WARN(logger,"Invalid frame data - crc mismatch: " << pkt.hexDump());
		return 1;
	}
//	fflush(stdout);
	return 0;
}

void BusDevice::write(Packet p) {
	LOG4CXX_TRACE(logger,"write called");
	bool write_in_progress = ! sendQueue.empty();

	sendQueue.push_back(p);
	
	if ( ! write_in_progress) {
		startWrite();
	}
} 

void BusDevice::startWrite() {
	LOG4CXX_TRACE(logger,"startWrite called");
	Packet packet = sendQueue.front();
	std::string frame = packet.toBinary();
	
	boost::asio::async_write(
		serial, 
		boost::asio::buffer(frame.c_str(),frame.length()),
		boost::bind(&BusDevice::writeHandler,
		this,
		boost::asio::placeholders::error));
}

void BusDevice::writeHandler(const boost::system::error_code&  error) {
	// the asynchronous read operation has now completed or failed and returned an error
	
	if (!error) {
		LOG4CXX_DEBUG(logger,"Write completed.");
		sendQueue.pop_front(); 
			if (!sendQueue.empty()) {
				startWrite(); 
			}
    } else {
		doClose(error);
	}
}

int BusDevice::sendString(string hexData) {
	std::string result = "";
	string token;
	stringstream ss(hexData);
	vector<string> tokens;
	while (ss >> token ) {
		int i = strtol(token.c_str(),NULL,16);
		result += i;
	}
	Packet p = fp.parsePacket(result,settings.getProtocol());
	return send(p);
}

