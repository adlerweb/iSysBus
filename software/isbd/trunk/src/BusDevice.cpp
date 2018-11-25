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
#include "BusDevice.h"
#include "Connection.h"
#include "frame_tools.h"

#include <log4cxx/logger.h>
#include <boost/bind.hpp>

extern Settings settings;
extern log4cxx::LoggerPtr logger;
extern connection_list connections;

using namespace std;
using namespace boost::asio;

BusDevice::BusDevice() : active(true),serial(io),frameAvailable(false) {
	frameData="";	
}



void BusDevice::start(void) {
	LOG4CXX_DEBUG(logger,"BusDevice thread started");
	open();

	string rcv;
	
	
	//if( ! isFrameAvailable() ) {
		        printf("serial port: starting async read\n");
			serial.async_read_some(boost::asio::buffer(rcvBuffer, BUFSIZE), 
			                       boost::bind(&BusDevice::readHandler,
		                                this,
                		                boost::asio::placeholders::error,
                                		boost::asio::placeholders::bytes_transferred));
	//}

	while (isActive()) {
		queueFlush();
		// async read till we receive a complete frame...
		io.run();
#if 0
		if( ! isFrameAvailable() ) {
		        printf("serial port: starting async read\n");
			serial.async_read_some(boost::asio::buffer(rcvBuffer, BUFSIZE), 
			                       boost::bind(&BusDevice::readHandler,
		                                this,
                		                boost::asio::placeholders::error,
                                		boost::asio::placeholders::bytes_transferred));
		}
#endif



#if 0
		/**
		 * Send data to clients
		 */
		std::string frameReceived;
		bool hasFrame=false;

		while ( rcvQueue.try_pop(frameReceived) == true ) {
				for (unsigned int i = 0; i < connections.size(); i++) {
					if (connections[i].isAcceptData()) {
						connections[i].queueAdd(frameData);
					}
				}
		}

		usleep(10000);
#endif
	}
	serial.close();
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

	LOG4CXX_INFO(logger,"Opened Port " + portname); 
	//LOG4CXX_FATAL(logger,"Couldn't open Port " + port);		
}

void BusDevice::send(string data) {
	
	serial.write_some(boost::asio::buffer(data.c_str(),data.length()));

	//LOG4CXX_DEBUG(logger,"BusDevice Data sent: " + data);
}

class scope_info {
public:
  scope_info(string name) : m_name(name) { cout << "************************ entering scope " << m_name << endl; };
  ~scope_info() { cout << "######################## leaving scope " << m_name << endl; };
  const string m_name;

};

void BusDevice::readHandler( const boost::system::error_code& error, std::size_t bytes_transferred ) {

        scope_info foo("BusDevice::readHandler");


        if (error) {
        
          throw std::runtime_error("error receiving data from serial port: " + error.message());
        }


        printf("serial port: received %d bytes\n", bytes_transferred);
	
	frameSize += bytes_transferred;	

	// copy the temporary data to the framedata 
	frameData.append((const char *)rcvBuffer, bytes_transferred);

	// search start of frame...
	bool frame_found = false;
	do {
	  //scope_info foo("BusDevice::readHandler do while frame found");
	  frame_found = false;
	  for (unsigned int i=0; i<frameData.length(); i++) {
		if ( frameData[i] == START_BYTE ) {
			// check if that is a valid frame...
			
			printf("serial receiver: found START_BYTE <%d>\n", i);
			
			cout << "received data <" << frameData.size() << ">: " << hexDump(frameData) << endl;
			
			const unsigned char dlc = frameData[i+1] & 0x0f;	
			printf("dlc: %d\n", dlc);
			// search for STOP_BYTE (framesize==8+dlc)
			const int stop_byte_pos = i+8+dlc;
			if ( (stop_byte_pos) <= frameSize ) {
				if (frameData[stop_byte_pos]==STOP_BYTE) {
					const int pos_soh=i;	
					const int length=9+dlc;
					
					printf("serial receiver: found STOP_BYTE <%d>\n", stop_byte_pos);

					std::string newFrame = frameData.substr(pos_soh, length);
					
					printf("frame length: %d, dlc: %d\n", length, dlc);
					
                                        if ( is_frame_complete((const unsigned char*)&frameData[pos_soh], length)) {
                                        
                                                if (!check_crc((const unsigned char *) newFrame.c_str(), length)) {
                                                        LOG4CXX_DEBUG(logger,"ignoring wrong crc on received message");
                                                } else {
                                                    LOG4CXX_DEBUG(logger,"checksum of received frame is fine");
                                                }
                                                
                                                printf("serial port reveicer: dispatching received frame\n");
                                                for (connection_list::iterator iter = connections.begin(); iter != connections.end(); ++iter) {
                                                    Connection::pointer c(*iter);
                                                    if (c->isAcceptData()) {
                                                      scope_info foo("queueAdd");
                                                        c->queueAdd(newFrame);
                                                    }
                                                }
                                                                                            
                                        } else {
                                          printf("serial receiver: incomplete frame\n");
                                        }
                                        
                                        frame_found = true;
                                        
                                        // verarbeitete daten loeschen
                                        frameData.erase(0, stop_byte_pos + 1);
                                        frameSize -= (stop_byte_pos + 1);
                                        
                                        break;
					
				} else {
				  printf("breaking loop (no stop byte) {0x%02d}\n", frameData[stop_byte_pos]);
				  throw std::runtime_error("protocol error - expected stop-byte");
			          cerr << "protocol error - expected stop-byte" << endl;
				}
				
			} else {
			  printf("breaking loop (incomplete frame)\n");
			  break; // schleife verlassen da frame nicht vollstaendig, neue daten lesen
			}
		}

          }
	} while (frame_found);

	
	printf("serial port: starting async read\n");
	serial.async_read_some(boost::asio::buffer(rcvBuffer, BUFSIZE), 
			                       boost::bind(&BusDevice::readHandler,
		                                this,
                		                boost::asio::placeholders::error,
                                		boost::asio::placeholders::bytes_transferred));
}

bool BusDevice::isFrameAvailable() {
	return frameAvailable;
}

/**
 * Adds data to the sending queue.
 * Returns the number of characters that could not be sent
 * or -1 if the queue is full
 * 
 * @param Data to send
 * @returns -1 in case of error, 0 if all data could be added to the queue
 */
int BusDevice::queueAdd(string data) {
	sendQueue.push(data);
	LOG4CXX_DEBUG(logger,"Added to serial queue: " <<  hexDump(data));
//	fflush(stdout);
	return 0;
}

/**
 * Send all data from the queue
 */
void BusDevice::queueFlush() {
	string frameToSend;

	bool hasData = sendQueue.try_pop(frameToSend);
	if (hasData) {
		LOG4CXX_DEBUG(logger,"Have a frame to send");
		serial.write_some(boost::asio::buffer(frameToSend.c_str(),frameToSend.length()));
	} 
/*
		string str = "";
		for (int i = 0; i < char_count; i++) {
			serial.writeChar(buf_send[buf_pos_get]);
			//if (buf_send[buf_pos_get] == '\n') {
			//	if (str != "") send(str);
		//	} else {
		//		str += buf_send[buf_pos_get];
		//	}
			if ((buf_pos_get + 1) >= BUFSIZE) buf_pos_get = 0;
				else buf_pos_get++;
			if (buf_char_count > 0) buf_char_count--;
		}
	}
*/
}

std::string BusDevice::hexDump(string data) {
        stringstream retval;

        for (unsigned int i=0;i<data.length();i++) {
                retval << "\\x"  << std::hex << (int)(data[i] & 0xff)  << " " ;
        }
        return retval.str();
}


