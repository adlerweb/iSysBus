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
#include "concurrent_queue.hpp"
#include <vector>

using namespace std;

//#define BUFSIZE 1024

class BusDevice {
	
	private:
		const static unsigned int BUFSIZE=1024;
		bool active;
		string frameData;
		boost::asio::io_service io;

		char rcvBuffer[BUFSIZE];
		boost::asio::serial_port serial;
		concurrent_queue<string> sendQueue;
		concurrent_queue<string> rcvQueue;
		
		bool frameAvailable;
		int frameSize;
		
		
	public:	
		BusDevice(); // Constructor
		//BusDevice(const &BusDevice);		
		void start(void);
		void stop(void) { active = false; };
		bool isActive(void) { return active; };
		void open();
		void send(string);
		int queueAdd(string);
		void queueFlush(void);
		void readHandler( const boost::system::error_code& error, std::size_t bytes_transferred );
		bool isFrameAvailable();
		std::string hexDump(std::string);
};
#endif /*BUSDEVICE_H_*/
