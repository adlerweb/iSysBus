/**
==================================================

	connection.h
	
Version: $Rev$
Last Modification: $Id$

Module: 
Created: 01.07.2007
Author: ig

Copyright 2007 by iSysBus

==================================================
*/
#ifndef CONNECTION_H_
#define CONNECTION_H_

#include <string>

#include <log4cxx/logger.h>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/signal.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>
#include "concurrent_queue.hpp"
#include "BusDevice.h"


#ifdef _WIN32
	#include "win32_server.h"
#else
	#include "linux_server.h"
#endif

using boost::asio::ip::tcp;

#define CMD_EXIT  "exit"
#define CMD_QUIT "quit"
#define CMD_HELP "help"
#define CMD_AUTH "auth"
#define CMD_USER "user"
#define CMD_PASS "pass"
#define CMD_SEND "send"
#define CMD_SENDX "sendx"
#define CMD_SWITCH "switch"
#define CMD_DATA  "data"


#if 0
prevent namespace pollution...
//#define BUFSIZE 1024
#define BUFSIZE 65536
#endif
class Connection : public boost::enable_shared_from_this<Connection> {
	public:
		typedef boost::shared_ptr<Connection> pointer;
		typedef boost::signal<void (Packet &p)> rcvSignal_t;
		typedef boost::signals::connection  connection_t;


	  static pointer create(boost::asio::io_service& io_service,Settings &s,BusDevice &dev) {
	    return pointer(new Connection(io_service,s,dev));
	  }

	  tcp::socket& socket() {
	    return socket_;
	  }

	  void handleLine(std::string);

	private:
		enum SessionState {
			init,
			auth,
			user,
			pass,
			main,
			finalize
		};

		rcvSignal_t rcvSignal;

		BusDevice &busDevice;
		FrameParser fp;	
		static log4cxx::LoggerPtr logger;
		SessionState sessionState;
		Settings &settings;


  		Connection(boost::asio::io_service& io_service, Settings &s,BusDevice &dev);
  		void handle_write(const boost::system::error_code& /*error*/, size_t /*bytes_transferred*/);
  		void handle_read(const boost::system::error_code& error, size_t bytes_transferred);
		void handle_data(size_t bytes_transferred); 

		static const int MAX_LEN = 80;
		static const int BUFSIZE = 65535;

  		tcp::socket socket_;


		std::queue<std::string> rcvQueue;
		concurrent_queue<Packet> sendQueue;

		bool accept_data;
		bool active;
		std::string auth_time;
		int auth_type;
		bool authorized;
		int buf_char_count;
		std::string buffer_in;
		bool data_mode;
		fd_set fds;
		int msg_type;
		std::string username;

		char data_[MAX_LEN];
	// Methods	
		int checkMessageType(std::string data);
		std::string getTime(void);
		void mainLoop(void);
		void send(std::string);
		void sendln(std::string);

		void doAuth(std::string data);
		void doUser(std::string data);
		void doPassword(std::string data);
		
	public:	
		
		static const int AUTH_PLAIN = 1;
		static const int AUTH_MD5 = 2;
		
		static const int MSG_UNDEF = 0;
		static const int MSG_ISB = 1;
		static const int MSG_CMD = 2;
		
		Connection(); // Constructor

  		connection_t connectReceiver(rcvSignal_t::slot_function_type subscriber) {
			return rcvSignal.connect(subscriber);
		}

		void disconnectReceiver(connection_t subscriber) {
			subscriber.disconnect();
		}

		void start(void);
		void stop(void);
		void flow(void);
		void setActive(bool act) { active = act; };
		bool isActive(void) { return active; };
		void setDataMode(bool dm) { data_mode = dm; accept_data = true; };
		bool isDataMode(void) { return data_mode; };
		void setAcceptData(bool accept) { accept_data = accept; };
		bool isAcceptData(void) { return accept_data; };
		void setUsername(std::string user) { username = user; }; 
		std::string getUsername(void) { return username; };
		bool isAuthorized(void) { return authorized; };
		void setAuthorized(bool auth) { authorized = auth; };
		void setAuthType(int type) { auth_type = type; };
		int getAuthType(void) { return auth_type; };
		int getCommand(std::string, std::string *, std::string *);
		std::string getMD5Hash(std::string);
		void sendHelp(std::vector<std::string> cmds);
		void sendResponse(std::string prefix, int code,std::string message);
		void exitConnection(void);
		std::string StrToLower(std::string);
		int write(Packet);
		void flushQueue(void);
	
}; // end class Connection
#endif /*CONNECTION_H_*/
