/**
==================================================

	main.cpp
	
Version: $Rev$
Last Modification: $Id$

Module: 
Created: 13.05.2007
Author: ig

Copyright 2007 by iSysBus

==================================================
*/
#include <string>
#include <iostream>
#include <signal.h>

#include "const.h"
#include "main.h"
//#include "server_layer.h"
#include "Settings.h"
#include "BusDevice.h"
#include "md5.h"
#include "tools.h"
#include "Connection.h"
#include "server.h"

#include <log4cxx/logger.h>
#include "log4cxx/basicconfigurator.h"
#include "log4cxx/propertyconfigurator.h"

#include <boost/program_options.hpp>
namespace po = boost::program_options;



 /**
  * Global variables
  */
BusDevice busDevice;
Settings settings;
log4cxx::LoggerPtr logger(log4cxx::Logger::getLogger("isbd"));

FILE *fp;
bool stop;

extern connection_list connections;

using namespace std; 


/**
 * Main method.
 * First, it looks for any parameters, if there were no found
 * it looks in /etc/ (Linux) or the current dir (Windows) for
 * a configuration file
 * Afterwards it listens for any incoming connections and 
 * starts a new thread for each new connection
 */
int main(int argc, char *argv[]) {


	/**
	 * read parameters from commandline AND config
	 */
	settings.parseOptions(argc,argv);
	
	settings.setProgramVersion("1.0.01");

	string loggerCfg = settings.getLoggerConfig();

	if ( loggerCfg.length() >0 ) {
		
		log4cxx::PropertyConfigurator::configure(loggerCfg);
	} 

	bool initialized = log4cxx::Logger::getRootLogger()->getAllAppenders().size() ? true : false;

	if( ! initialized ) {
		// config did not work i.e. no logging properties configured or file could not be read ...
		cout << "Logging not configured: using basic configurator" <<endl;
  		log4cxx::BasicConfigurator::configure();
	}

	LOG4CXX_INFO(logger,"Starting isb daemon...");
	

//	signal(SIGCHLD, waitforchild);
	signal(SIGINT, handle_sigint);
	
	/**
	 * Parse the given parameters
	 * Overwrites values provided by configfile
	 */

	//TODO:parse_parameters();
	
	/**
	 * Look if all required parameters are available
	 */
	//TODO:	check_required_params();
	
	/**
	 * Daemonize process if option is set
	 */
	if (settings.isDaemon()) {
		daemonize();
	}

	
	boost::thread busDeviceThread(boost::bind(&BusDevice::start,&busDevice));
//	busDeviceThread = boost::thread(busDevice);
	
	/**
	 * Open socket to listen for incoming connections
	 */

	 boost::asio::io_service tcp_io_service;
    	server server(tcp_io_service,"noip",settings.getTcpPort());
	tcp_io_service.run();

	// boost::thread serverThread( &server_start);
 	LOG4CXX_INFO(logger,"Post server_start");	
	
	
	/**
	 * Main loop
	 */
 	 while (!stop) {
 	 	#ifdef _WIN32
 			Sleep(500);
 		#else
 			usleep(500000);
 		#endif
 	}
 	
 	//busDeviceThread.join();
 	for (connection_list::iterator iter = connections.begin(); iter != connections.end(); iter++) {
		if (iter->second->isActive() == true) {
			iter->second->stop();
		}
 	}
 	
 	LOG4CXX_INFO(logger,"Exit program");	
 	return 0;
 }

