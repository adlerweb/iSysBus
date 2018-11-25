/**
==================================================

	settings.h
	
Version: $Rev$
Last Modification: $Id$

Module: 
Created: 01.07.2007
Author: ig

Copyright 2007 by iSysBus

==================================================
*/
#ifndef SETTINGS_H_
#define SETTINGS_H_

#include <string>

#define PIDFILE "/var/run/isbd.pid"

#include <boost/program_options.hpp>
namespace po = boost::program_options;


using namespace std;

class Settings {
	
	private:
		po::variables_map vm;
		po::options_description cmdlineopts;
		po::options_description commonopts;

		bool daemon;
		bool verbose;
		bool regenerate;
		int tcp_port;
		int device_type;
		int auth_max_tries;
		int baudrate;
		int uid;
		int gid;
		int idle_timeout;
		int loglevel;
		int protocol;
		std::string com_port;
		std::string logfile;
		std::string username;
		std::string password;		
		std::string program_version;
		std::string interfaceStr;
		std::string deviceStr;
		std::string configfile;
		std::string loggercfg;
		std::string dbName;
		int dbLogPackets;
		int dbEnable;
	private:
		void setupCmdLineOptions();
		void setupCommonOptions();
		
	public:	
	
		static const int SERIAL = 1;
		static const int MODEM = 2;
		static const int USB = 3;
	
		
		void setBaudrate(int baud) { baudrate = baud; };
		int getBaudrate(void) { return baudrate; };
		void setDaemon(bool daemonize) { daemon = daemonize; }
		bool isDaemon(void) { return daemon; }
		void setRegenerate(bool regen) { regenerate= regen; }
		bool isRegenerate(void) { return regenerate; }
		void setGID(int id) { gid = id; };
		int getGID(void) { return gid; };	
		void setTcpPort(int port) { tcp_port = port; }
		int getTcpPort() { return tcp_port; }
		void setCOMPort(std::string portname) { com_port = portname; };
		std::string getCOMPort(void) { return com_port; };
		void setIdleTimeout(int timeout) { idle_timeout = timeout; };
		int getIdleTimeout(void) { return idle_timeout; };
		void setLogfile(std::string file) { logfile = file; };
		std::string getLogfile(void) { return logfile; };
		void setLoglevel(int level) { loglevel = level; };
		int getLoglevel(void) { return loglevel; };	
		void setAuthMaxTries(int number) { auth_max_tries = number; };
		int getAuthMaxTries(void) { return auth_max_tries; };
		void setPassword(std::string pass) { password = pass; }
		std::string getPassword(void) { return password; } 
		void setProgramVersion(std::string version) { program_version = version; }
		std::string getProgramVersion() { return program_version; }
		void setUID(int id) { uid = id; };
		int getUID(void) { return uid; };		
		void setUsername(std::string user) { username = user; }
		std::string getUsername(void) { return username; }
		void setVerbosity(bool verb) { verbose = verb; }
		std::string getLoggerConfig() { return loggercfg; }
		void setLoggerCfg(std::string newcfg) { loggercfg = newcfg; }
		std::string getDbName() { return dbName; }
		void setDbName(std::string newDbName) { dbName = newDbName; }

		bool isLogPackets() { return dbLogPackets; }
		bool isEnableDb() { return dbEnable; }

		int getProtocol() { return protocol; }
		void setProtocol(int newproto) { protocol= newproto; }

		// prototypes
		void assignValues(std::string, std::string);
		void parseOptions(int argc, char ** argv);
		std::string getTcpPortAsString(void);
		void setDeviceType(int);
		int getDeviceType(void);
		Settings(); // Constructor
		
			
//	static int port = 0;
	
}; // end class Settings

#endif /*SETTINGS_H_*/
