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
#include "server_layer.h"
#include "Settings.h"
#include "DbLogger.h"
#include "BusDevice.h"
#include "tools_old.h"
#include "Connection.h"
#include "server.h"

#include <log4cxx/logger.h>
#include "log4cxx/basicconfigurator.h"
#include "log4cxx/propertyconfigurator.h"

#include <boost/program_options.hpp>
namespace po = boost::program_options;


log4cxx::LoggerPtr mainLogger(log4cxx::Logger::getLogger("isbd"));

 /**
  * Global variables
  */

FILE *fp;
bool stop;

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

	Settings settings;

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

	LOG4CXX_INFO(mainLogger,"Starting isb daemon...");
	

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

	
    boost::asio::io_service io_service;
	DbLogger dbLogger(settings);
	BusDevice dev(io_service,settings,dbLogger);

	boost::thread t(boost::bind(&boost::asio::io_service::run, &io_service)); 
	
//	busDeviceThread = boost::thread(busDevice);
	
	/**
	 * Open socket to listen for incoming connections
	 */

	 boost::asio::io_service tcp_io_service;
    	Server server(tcp_io_service,"noip",settings.getTcpPort(),settings,dev);
	tcp_io_service.run();

	// boost::thread serverThread( &server_start);
 	LOG4CXX_INFO(mainLogger,"Post server_start");	
	
	
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
	server.checkConnections();
	
 	LOG4CXX_INFO(mainLogger,"Exit program");	
 	return 0;
 }

