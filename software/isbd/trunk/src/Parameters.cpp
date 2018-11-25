/**
==================================================

	parameters.cpp
	
Version: $Rev$
Last Modification: $Id$

Module: 
Created: 01.07.2007
Author: ig

Copyright 2007 by iSysBus

==================================================
*/
#include <string>
#include <iostream>
#include "main.h"
#include "ParamContainer.h"
#include "Settings.h"
#include "Parameters.h"
#include "Logger.h"

#ifndef _WIN32
#include <stdlib.h>
#endif 
 
extern ParamContainer params;
extern Settings settings;
extern Logger logger;

/**
 * Define the name of possible parameters
 */
void define_parameters(int argc, char *argv[]) {
 	
 	params.addParam("configfile", 'c', ParamContainer::filename, "Path to config-file");
	params.addParam("daemonize", 'd', ParamContainer::novalue, "Start program as daemon");
 	params.addParam("help", 'h', ParamContainer::novalue, "Print help and exit");
	params.addParam("interface", 'i', ParamContainer::regular, "Interface to the bus. Valid names are (usb|serial|modem)"); 
	params.addParam("logfile", 'l', ParamContainer::filename, "Log output to file");
 	params.addParam("loglevel", 0, ParamContainer::regular, "Loglevel (0-5)");
	params.addParam("port", 'p', ParamContainer::regular, "Port for the daemon to listen on");
 	params.addParam("password", 'P', ParamContainer::regular, "Password");
 	params.addParam("timeout", 't', ParamContainer::regular, "Timeout");
 	params.addParam("username", 'U', ParamContainer::regular, "Username");
 	params.addParam("verbose", 'v', ParamContainer::novalue, "Increase verbosity level");
	params.addParam("version", 0, ParamContainer::novalue, "Print version number and exit");

 	if(params.parseCommandLine(argc, argv) != params.errOk) {
		fprintf(stderr, "Error in arguments!\nEnter %s -h for help\n", argv[0]);
	}
 		
 } // end define_parameters()

/**
 * Write the parameter values into the settings
 */
void parse_parameters(void) {

	// Print help and exit
	if (params["help"] != "") {
		// TODO: print help
		exit(0);
	}

	// Print version and exit
	if (params["version"] != "") {
		print_version();
		return;
	}
	
	if (params["daemonize"] != "") settings.setDaemon(true);

	if (params["interface"] != "") {
		if (params["interface"] == "serial") settings.setDeviceType(Settings::SERIAL);
		else if (params["interface"] == "modem") settings.setDeviceType(Settings::MODEM);
		else if (params["interface"] == "usb") settings.setDeviceType(Settings::USB);
		else logger.error("No valid interface was specified");
	}
	if (params["password"] != "") settings.setPassword(params["password"].c_str());
	if (params["port"] != "") settings.setTcpPort(atoi(params["port"].c_str()));
	if (params["username"] != "") settings.setUsername(params["username"].c_str());
	if (params["verbose"] != "") settings.setVerbosity(true);
	
	logger.debug("Added values of commandline parameters to settings object");
}
 
 /**
  * Prints the version number and the copyright
  */
 void print_version(void) {

 	cout << "isbd Version " << settings.getProgramVersion() << "\n";
 	cout << "Copyright 2007 by iSysBus.org" << "\n";
 	cout << "Visit http://www.iSysBus.org for further information, updates, etc.\n";
 	exit(0);
 	
 } // end display_version()
