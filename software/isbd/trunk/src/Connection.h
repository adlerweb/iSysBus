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
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>
#include "concurrent_queue.hpp"


#ifdef _WIN32
	#include "win32_server.h"
#else
	#include "linux_server.h"
#endif

using boost::asio::ip::tcp;





#if 0
prevent namespace pollution...
//#define BUFSIZE 1024
#define BUFSIZE 65536
#endif
class Connection : public boost::enable_shared_from_this<Connection> {
	public:
		typedef boost::shared_ptr<Connection> pointer;


	  static pointer create(boost::asio::io_service& io_service) {
	    return pointer(new Connection(io_service));
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

  		Connection(boost::asio::io_service& io_service);
  		void handle_write(const boost::system::error_code& /*error*/, size_t /*bytes_transferred*/);
  		void handle_read(const boost::system::error_code& error, size_t bytes_transferred);
		void handle_data(size_t bytes_transferred); 
  		tcp::socket socket_;

		SessionState sessionState;
		int checkMessageType(std::string data);

		std::queue<std::string> rcvQueue;
		concurrent_queue<std::string> sendQueue;
		bool active;
		bool authorized;
		bool data_mode;
		bool accept_data;
		int buf_char_count;
		int msg_type;
		std::string auth_time;
		std::string username;
		int auth_type;
		static const int MAX_LEN = 80;
		static const int BUFSIZE = 65535;
		log4cxx::LoggerPtr logger;
		std::string buffer_in;
		fd_set fds;

		char data_[MAX_LEN];
		
		std::string getTime(void);
		void mainLoop(void);
		void send(std::string);
		void sendln(std::string);
		
	public:	
		
		static const int AUTH_PLAIN = 1;
		static const int AUTH_MD5 = 2;
		
		static const int MSG_UNDEF = 0;
		static const int MSG_ISB = 1;
		static const int MSG_CMD = 2;
		
		Connection(); // Constructor
		
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
		void sendHelp(void);
		void sendResponse(std::string prefix, int code,std::string message);
		void exitConnection(void);
		std::string StrToLower(std::string);
		int queueAdd(std::string);
		void queueFlush(void);
		std::string hexDump(std::string data);
	
}; // end class Connection


//typedef std::map<tcp::socket, Connection::pointer> connection_list;
typedef std::set<Connection::pointer> connection_list;



#endif /*CONNECTION_H_*/
