/**
==================================================

	BusDevice.h
	
Version: $Rev$
Last Modification: $Id$

Module: 
Created: 01.07.2007
Author: ig

Copyright 2007 by iSysBus

==================================================
*/
#ifndef BUSDEVICE_H_
#define BUSDEVICE_H_

#include <boost/asio.hpp>
#include <boost/signal.hpp>
#include "concurrent_queue.hpp"
#include <vector>
#include <deque>
#include <log4cxx/logger.h>
#include "Settings.h"
#include "frameparser.h"
#include "packet.h"


//#define BUFSIZE 1024

class Server;
class DbLogger;

class BusDevice {
	
	typedef boost::signal<void (Packet &p)> rcvSignal_t;
	typedef boost::signals::connection  connection_t;

	private:
		rcvSignal_t rcvSignal;
		log4cxx::LoggerPtr logger;
		bool active;
		const static unsigned int BUFSIZE=1024;
		boost::asio::io_service &io_;
		boost::asio::serial_port serial;
		Settings &settings;
		DbLogger &m_dbLogger;
		std::string frameData;
		FrameParser fp;

		char rcvBuffer[BUFSIZE];
		deque<Packet> sendQueue;
		deque<Packet> rcvQueue;
		
		bool frameAvailable;
		int frameSize;
		
		void write(Packet);
		void startRead();
		void startWrite();
		
		
	public:	
		BusDevice(boost::asio::io_service &io,Settings &s,DbLogger &dbLogger); // Constructor
		//BusDevice(const &BusDevice);		
		void stop(void) { active = false; };
		bool isActive(void) { return active; };
		void open();
		void readHandler( const boost::system::error_code& error, std::size_t bytes_transferred );
		void writeHandler( const boost::system::error_code& error);
		void doClose(boost::system::error_code);
		void close();
		int  send(Packet);
		int  sendString(std::string);
		void queueFlush(void);
		bool isFrameAvailable();

  		connection_t connectReceiver(rcvSignal_t::slot_function_type subscriber) {
			return rcvSignal.connect(subscriber);
		}

		void disconnectReceiver(connection_t subscriber) {
			subscriber.disconnect();
		}

};
#endif /*BUSDEVICE_H_*/
