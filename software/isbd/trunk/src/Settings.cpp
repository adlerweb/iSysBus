/**
==================================================

	settings.cpp
	
Version: $Rev$
Last Modification: $Id$

Module: 
Created: 01.07.2007
Author: ig

Copyright 2007 by iSysBus

==================================================
*/
#include <ctype.h>
#include <iostream>
#include <fstream>
#include "Settings.h"

#ifndef _WIN32
#include <stdlib.h>
#endif

#include <log4cxx/logger.h>

using namespace std;

Settings::Settings() : cmdlineopts("Commandline options"), commonopts("Common options") {
	verbose = false;
	daemon = false;
	setDeviceType(Settings::SERIAL);
	setCOMPort("COM1");
	setBaudrate(115200);

	setupCmdLineOptions();
	setupCommonOptions();

}

void Settings::setupCmdLineOptions() {

	cmdlineopts.add_options()
 	("configfile,c", po::value<string>(), "Path to config-file")
 	("help,h", "Print help and exit")
	("version", "Print version number and exit")
 	("verbose,v", "Increase verbosity level")
	;
}

void Settings::parseOptions(int argc, char **argv) {
	po::options_description cmdline_options;
        cmdline_options.add(commonopts).add(cmdlineopts);

	po::store(po::parse_command_line(argc, argv, cmdline_options), vm);
	po::notify(vm);  

	string cfgfile;
	if ( vm.count("configfile")) {
		cfgfile =  vm["configfile"].as<string>();
	}

	if (cfgfile.length() == 0) {
		// No name for the config-file was provided by the user, so try to find it 
		#ifdef _WIN32
			cfgfile = string("isbd.conf");
		#else
			cfgfile = string("/etc/isbd.conf");
		#endif
	}

	po::options_description config_file_options;
	config_file_options.add(commonopts);

	ifstream ifs(cfgfile.c_str());
	po::store(parse_config_file(ifs, config_file_options), vm);
	po::notify(vm);
}	

void Settings::setupCommonOptions() {
	commonopts.add_options()
	("DAEMON,d", "Start program as daemon")
	("INTERFACE,i", po::value<string>(&interfaceStr), "Interface to the bus. Valid names are (usb|serial|modem)") 
	("LOGFILE,l", po::value<string>(&logfile), "Log output to file")
 	("LOGLEVEL", po::value<int>(&loglevel)->default_value(0), "Loglevel (0-5)")
	("PORT,p", po::value<int>(&tcp_port)->default_value(4723), "Port for the daemon to listen on")
 	("PASSWORD,P", po::value<string>(&password), "Password")
 	("IDLE_TIMEOUT,t", po::value<int>(&idle_timeout), "Timeout")
 	("USERNAME,U", po::value<string>(&username), "Username")

	("AUTH_MAX_TRIES",po::value<int>(&auth_max_tries)->default_value(3))
	("BAUDRATE",po::value<int>(&baudrate)->default_value(115200))
	("COMPORT",po::value<string>(&com_port)->default_value("COM1"))
	("DEVICE", po::value<string>(&deviceStr),"Device type")
	("UID",po::value<int>(&uid),"UID for the process")
	("GID",po::value<int>(&gid),"GID for the process")
 	("LOGGERCFG,L", po::value<string>(&loggercfg), "Logging config file")
;
	

}

void Settings::setDeviceType(int if_id) {
	if (if_id > 0 && if_id <= 3) device_type = if_id;
}

int Settings::getDeviceType() {
	return device_type;
}


/**
 * Assigns the values from the strings to variables
 */
void Settings::assignValues(string name, string value) {

	if (name == "auth_max_tries") {
		setAuthMaxTries(atoi(value.c_str()));
	} else if (name == "baudrate") {
		setBaudrate(atoi(value.c_str()));
	} else if (name == "comport") {	
		setCOMPort(value.c_str());
	} else if (name == "daemon") {
	} else if (name == "device") {
		//setDeviceType();
	} else if (name == "gid") {
		setGID(atoi(value.c_str()));
	} else if (name == "idle_timeout") {		
		setIdleTimeout(atoi(value.c_str()));
	} else if (name == "interface") {
		
	} else if (name == "logfile") {
		//setLogfile("isbd.log");
		setLogfile(value);
	} else if (name == "loglevel") {
		int level = atoi(value.c_str());
		if (level < 0 || level > 5) setLoglevel(5);
			else setLoglevel(level);
	} else if (name == "password") {
		setPassword(value);
	} else if (name == "port") {
		setTcpPort(atoi(value.c_str()));
	} else if (name == "uid") {
		setUID(atoi(value.c_str()));
	} else if (name == "username") {
		setUsername(value);
	}
	
}

/**
 * Transform the port number into a string
 */
string Settings::getTcpPortAsString(void) {
	char str[6];
	sprintf(str, "%d", tcp_port);
	return str;
}
