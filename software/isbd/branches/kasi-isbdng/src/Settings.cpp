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
#include "revision.h"

#ifndef _WIN32
#include <stdlib.h>
#endif

#include <log4cxx/logger.h>

using namespace std;

Settings::Settings() : cmdlineopts("Commandline options"), commonopts("Common options") {
	verbose = false;
	daemon = false;
	regenerate=false;
	setDeviceType(Settings::SERIAL);
	setCOMPort("COM1");
	setBaudrate(115200);
	dbLogPackets=0;
	dbEnable=0;

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

	if ( vm.count("version")) {
		cout << argv[0] << " V " << VERSION << " (Rev. " << REVISION << ", " << LAST_CHANGE << ")\n";
		exit(1);
	}

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
	("daemon,d", "Start program as daemon")
	("interface,i", po::value<string>(&interfaceStr), "Interface to the bus. Valid names are (usb|serial|modem)") 
	("logfile,l", po::value<string>(&logfile), "Log output to file")
 	("loglevel", po::value<int>(&loglevel)->default_value(0), "Loglevel (0-5)")
	("port,p", po::value<int>(&tcp_port)->default_value(4723), "Port for the daemon to listen on")
 	("password,P", po::value<string>(&password), "Password")
 	("idle_timeout,t", po::value<int>(&idle_timeout), "Timeout")
 	("username,U", po::value<string>(&username), "Username")

	("auth_max_tries",po::value<int>(&auth_max_tries)->default_value(3))
	("baudrate",po::value<int>(&baudrate)->default_value(115200))
	("comport",po::value<string>(&com_port)->default_value("COM1"))
	("device", po::value<string>(&deviceStr),"Device type")
	("uid",po::value<int>(&uid),"UID for the process")
	("gid",po::value<int>(&gid),"GID for the process")
	("protocol",po::value<int>(&protocol),"Protocol Version")
 	("loggercfg,L", po::value<string>(&loggercfg), "Logging config file")
 	("dbname", po::value<string>(&dbName), "Logging Database Name")
 	("dblogpackets", po::value<int>(&dbLogPackets), "Log Packets to DB (1/0)")
 	("dbenable", po::value<int>(&dbEnable), "Enable DB features (1/0)")
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
	} else if (name == "protocol") {
		setProtocol(atoi(value.c_str()));
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
