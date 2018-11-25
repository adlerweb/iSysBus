/**
==================================================

	connection.cpp
	
Version: $Rev$
Last Modification: $Id$

Module: 
Created: 01.07.2007
Author: ig

Copyright 2007 by iSysBus

==================================================
*/
#include <time.h>
#include <string>
#include <algorithm>
#include <cctype>

#include <sys/time.h>
#include <unistd.h>

#include "Settings.h"
#include "Tools.h"
#include "frameparser.h"
#include <log4cxx/logger.h>

#include <ios>
#include <sstream>
#include <iostream>

#include "Connection.h"
#include "server_layer.h"
#include "openssl/md5.h"
#include "BusDevice.h"
#include "ResponseMessages.h"

#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>

#include "server.h"

log4cxx::LoggerPtr Connection::logger(log4cxx::Logger::getLogger("org.isysbus.Connection"));


using namespace std;

//warum global?
//char *buffer = (char*) malloc(BUFSIZE);

/**
 * Start authorization process
 */
void Connection::start(void) {
	sessionState = auth;
	LOG4CXX_DEBUG(Connection::logger,"Starting login sequence");	
	setActive(true);
	sendResponse(RESP_OK,200,OK_WELCOME);
	LOG4CXX_DEBUG(Connection::logger,"Response sent");	

	socket_.async_read_some(boost::asio::buffer(data_, MAX_LEN),
        boost::bind(&Connection::handle_read, shared_from_this(),
       		boost::asio::placeholders::error,
        		boost::asio::placeholders::bytes_transferred));
}

int Connection::checkMessageType(string data) {
	if (data_[0] == 0x01) {
		return MSG_ISB;
	} else if (data[0] == '+' || data_[0] == '-' || data_[0] == '*') {
		return MSG_CMD;
	} else if (data_[0] == 0x00 || data_[0] == '\r' || data_[0] == '\n') {
		return MSG_UNDEF; // Ignore newlines
	} else { 
		return MSG_UNDEF;
	}

}

void Connection::flow() {
	string name, value;
//	size_t byteCount = socket_.read_some(boost::asio::buffer(data_,MAX_LEN));
//	handle_data(byteCount);

	string data = rcvQueue.front();
	rcvQueue.pop();

	int msg_type = checkMessageType(data);

	// If an ISB Message is sent, is it correct
	if (msg_type == MSG_ISB) {

		vector<Packet> packets = fp.parse(data,settings.getProtocol());
		if ( packets.size()>0) {
              		//LOG4CXX_DEBUG(Connection::logger,"msg receivedm dlc: %d, framesize: %d\n", dlc, framesize);
              		LOG4CXX_DEBUG(Connection::logger,"Received message from net");
			for ( vector<Packet>::iterator it = packets.begin();it != packets.end();it++) {
				busDevice.send(*it);
			}
              		msg_type = MSG_UNDEF;
		} else { // Message seems to be not yet complete
			LOG4CXX_DEBUG(Connection::logger,"incomplete msg");
			LOG4CXX_TRACE(Connection::logger,"<<: " << Tools::hexDump(data));
		}
	} else {
		if ( isDataMode() ) {
			LOG4CXX_TRACE(Connection::logger,"<<: " << Tools::hexDump(data));
		} else {
			LOG4CXX_TRACE(Connection::logger,"<<: " << data);
		}

		msg_type = MSG_UNDEF;
		if (data != "") {
			if (data.substr(0, 3) == "+++") {
				if (isDataMode()) {
					LOG4CXX_DEBUG(Connection::logger,"escape sequence received - leaving data mode");
					setDataMode(false);
					setAcceptData(false);
					sendResponse(RESP_OK,205,OK_COMMAND_MODE);
				}
				data = "";
				return;
			} 
		}
	}

	if ( sessionState == auth ) {
		doAuth(data);

		if (!isActive()) {
			exitConnection();
			return;	
		}
	} else if ( sessionState == user ) {
		doUser(data);			
		if (!isActive()) {
			exitConnection();
			return;	
		}
	} else if  (sessionState == pass) {
		doPassword(data);
		if (!isActive()) {
			exitConnection();
			return;	
		}
	} else if ( sessionState == main ) {	
		if (isDataMode()) {
						
			if (data != "") {
				LOG4CXX_TRACE(Connection::logger,"<<: " <<  Tools::hexDump(data));
				Packet p = fp.parsePacket(data,settings.getProtocol());	
				// dispatch msg
				busDevice.send(p);
/* 				for (unsigned int i = 0; i < connections.size(); i++) {
				    if (this != &connections[i]) { // no local echo
						if (connections[i].isAcceptData()) {
							connections[i].queueAdd(data);
						}
					}
				}
*/
			}

			// Flush sending queue
			flushQueue();		
			
		} else {
			vector<string> validCmds;
			validCmds.push_back(CMD_DATA);
			validCmds.push_back(CMD_SEND);
			validCmds.push_back(CMD_SENDX);
			validCmds.push_back(CMD_SWITCH);
			validCmds.push_back(CMD_HELP);
			validCmds.push_back(CMD_EXIT);
			validCmds.push_back(CMD_QUIT);

			getCommand(data, &name, &value);
			if (name == CMD_DATA ) {
				sendln("* Entering DATA mode");
				setDataMode(true);
				setAcceptData(true);
				if (buf_char_count > 0) {
					if (buf_char_count > BUFSIZE) {
				 		buf_char_count = 0;
						sendResponse(RESP_ERR,414,ERR_BUFFER_OVERRUN);
						setAcceptData(true);
					} else {
						char cnt[6];
						sprintf(cnt, "%d", buf_char_count);
						sendResponse(RESP_OK,310, string(OK_FLUSHING)+" ("+string(cnt)+")");
						flushQueue();
				 	} 								
				} else {
					sendResponse(RESP_OK,204,OK_NO_DATA);
				}
			} else if (name == CMD_SEND) {
				Packet p = fp.parsePacket(value,settings.getProtocol());
				busDevice.send(p);
			} else if (name == CMD_SENDX) {
				busDevice.sendString(value);
			} else if (name == CMD_SWITCH) {
				vector<string> tokens;
				istringstream iss(value);
				copy(istream_iterator<string>(iss),
         				istream_iterator<string>(),
         				back_inserter<vector<string> >(tokens));
				if ( tokens.size()!=4) {
					sendResponse(RESP_ERR,413, ERR_INVALID_PARAMS);
					LOG4CXX_ERROR(Connection::logger, value);
				} else {
					unsigned int src,dest;
					std::string data;
					Packet p(src, dest, data, 0,0, settings.getProtocol());
					busDevice.send(p);
				}
			} else if (name == CMD_HELP) {
				sendHelp(validCmds);
			} else if (name == CMD_QUIT || name == CMD_EXIT ) {
				sendResponse(RESP_OK,203,OK_CLOSE_CONNECTION);
				LOG4CXX_INFO(Connection::logger,"Client closed connection");
				exitConnection();
			} else {
				sendResponse(RESP_ERR,413, ERR_INVALID_COMMAND);
				LOG4CXX_WARN(Connection::logger,"Unrecognized command: " + name + " " + value);
			}
		}
		flushQueue();
	}
	//sendResponse(RESP_OK,203,OK_GOING_DOWN);
	//LOG4CXX_INFO(Connection::logger,"Closing client hread");
}


void Connection::stop(void) {
	setActive(false);
	LOG4CXX_INFO(Connection::logger,"Stopping connection");
}

void Connection::send(string data) {
	if (isActive()) {
		boost::asio::async_write(socket_, boost::asio::buffer(data),
		boost::bind(&Connection::handle_write, shared_from_this(),
		  boost::asio::placeholders::error,
		  boost::asio::placeholders::bytes_transferred));
		
		if ( data.find("+OK") >=0 || data.find("+ERR")>=0) {
			//LOG4CXX_DEBUG(Connection::logger,">>: " << data);
			LOG4CXX_TRACE(Connection::logger,">>: " << Tools::hexDump( data));
		} else {
		}
			LOG4CXX_TRACE(Connection::logger,">>: " << Tools::hexDump( data));
	}
}

void Connection::sendln(string str) {
	//	char * cstr2;
	//	cstr2 = new char [5];
	//	cstr2[0] = 0x00;
	//	cstr2[1] = 0x01;
	//	cstr2[2] = '\r';
	//	cstr2[3] = '\n';
	//	cstr2[4] = '\0';
		//strcpy(cstr2, data.c_str());
	//	TCP_send((socket_t*)&socket, cstr2, 5);

	str += "\r\n";

	send(str);	
}

void Connection::handle_write(const boost::system::error_code& error, size_t bytes_transferred) {
	LOG4CXX_TRACE(Connection::logger,"transferred " << bytes_transferred << " bytes" );
}

void Connection::handle_read(const boost::system::error_code& error, size_t bytes_transferred) {
	if ( ! error) {
			if ( bytes_transferred > 0) {
				LOG4CXX_TRACE(Connection::logger,"received " << bytes_transferred << " bytes");
				handle_data(bytes_transferred);
				while ( ! rcvQueue.empty()) {
					flow();
				}
			} else {
				LOG4CXX_TRACE(Connection::logger,"nothing received");
			}
			if (  sessionState != finalize ) {
					socket_.async_read_some(boost::asio::buffer(data_, MAX_LEN),
						boost::bind(&Connection::handle_read, shared_from_this(),
							boost::asio::placeholders::error,
							boost::asio::placeholders::bytes_transferred));
			}
	} else {
		LOG4CXX_DEBUG(Connection::logger,"receive: errorcode: " << error.message() );
		setActive(false);
		socket_.close();
	}
}

void Connection::handle_data(size_t bytes_transferred) {
    for (unsigned int i = 0; i < bytes_transferred; i++) {
	//			LOG4CXX_DEBUG(Connection::logger,"Buffer NEW: %02x\n", (int)(data_[i] & 0xFF));
	//			fflush(stdout);
	
		// Empty data_ - check type of received message
		if (buffer_in.length() == 0) {
			msg_type = checkMessageType(data_);

		}
				
		// If it is NOT an ISB Message and the backspace char is received, delete 
		// the last inserted byte, otherwise add char
		if (msg_type != MSG_ISB && data_[i] == 0x08 && buffer_in.size() > 0) {
			buffer_in.erase(buffer_in.end()-1);
		} else {
			buffer_in += (int)(data_[i] & 0xFF);
		}

		if ( (data_[i] == '\n' || data_[i] == '\r')) {
			// the line is complete so push it to the rcv queue...
			if ( buffer_in.length()>0 && buffer_in[0] != '\n') {
				if ( msg_type != MSG_ISB || FrameParser::isFrameComplete((const unsigned char *) buffer_in.c_str(),buffer_in.length())) {
					LOG4CXX_TRACE(Connection::logger,"pushing complete line into rcvQueue (len:" << buffer_in.length() << ")");
					rcvQueue.push(string(buffer_in));
					buffer_in="";
				} else {
					LOG4CXX_TRACE(Connection::logger,"frame not yet complete :" << Tools::hexDump(buffer_in));
				}
			} else {
				buffer_in="";
			}
		}
	}

}

/**
 * Extracts a command and an optional value from the given string
 */
int Connection::getCommand(string cmd, string *name, string *value) {
	*name = "";
	*value = "";

	transform(cmd.begin(),cmd.end(),cmd.begin(), (int(*)(int))tolower);

	int separatorIndex = cmd.find_first_of(" \r\n",0);
	int endlIndex = cmd.find_first_of("\r\n",0);

	
	// if we cannot find a separator treat the entire string as the command - no value...
	if (separatorIndex < 0) {
		*value = cmd;
		return 0;
	}

	*name = cmd.substr(0,separatorIndex);
	*value = cmd.substr(separatorIndex+1,endlIndex-separatorIndex-1);

	return 0;
}

/**
 * Add data to the sending queue
 */
int Connection::write(Packet pkt) {
	sendQueue.push(pkt);
	LOG4CXX_TRACE(Connection::logger,"<<: " << pkt.hexDump()); 
	return 0;
}

/**
 * Send all data from the queue
 */
void Connection::flushQueue() {

	while ( ! sendQueue.empty()) {
		Packet pkt;
		sendQueue.wait_and_pop(pkt);
		if ( isDataMode()) {
			LOG4CXX_TRACE(Connection::logger,">>: " << pkt.hexDump());
			send(pkt.toBinary());
		} else {
			LOG4CXX_TRACE(Connection::logger,"No send (not data mode): " << pkt.hexDump());
		}
	}
}

/**
 * Get the current time as a string in the format hhmmss
 */
string Connection::getTime(void) {
	char timestr[10];
	time_t rawtime;
	struct tm * timeinfo;
	
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	
	strftime(timestr, 10, "%H%M%S", timeinfo);
	return timestr;
}

/**
 * Create a hash from the given time and the password from the settings
 */
string Connection::getMD5Hash(string time) {
	unsigned char sig[16];
	char c[32];
	string key, hash;
	key = settings.getPassword() + time;

	MD5_CTX md5;
	MD5_Init(&md5);
	MD5_Update(&md5, key.c_str(), key.length());
	MD5_Final(sig, &md5);

	for (int i = 0; i < 16; i++) {
		sprintf(c, "%02x", sig[i]);
		hash += c;
	}
	return hash;	
}

/**
 * Send a list of available commands to the client
 */
void Connection::sendHelp(vector<string> cmds) {
	sendln("* Usable commands in this context are:");
	string cmdList("* ");
	for (vector<string>::iterator it = cmds.begin(); it != cmds.end(); it++) {
		cmdList+=*it;
		cmdList+=" ";	
	}
	sendln(cmdList);

	sendln("* List of available commands:");
	sendln("* EXIT Close the connection");
	sendln("* HELP Print this help message");
	sendln("* USER <username> Connects to system using the specified username");
	sendln("* PASS <password> Sends an (encrypted) password. The type of encryption");
	sendln("*                 (plain/md5) has to be set before using the AUTH command");
	sendln("* 214 QUIT Close the connection");
	sendln("+OK 214 Help");
}

/**
 * Resets all connection data
 */
void Connection::exitConnection() {
	LOG4CXX_DEBUG(Connection::logger,"Connection closed.");
	setAcceptData(false);
	setDataMode(false);
	//if (socket != -1 && isDataMode()) setDataMode(false);
	setAuthorized(0);
	setActive(false);
	setUsername("");
	//close_socket((socket_t*)&socket);
	sessionState=finalize;
	socket_.close();
	//threadExit();
}

string Connection::StrToLower(string strToConvert) {//change each element of the string to lower case
   for(unsigned int i = 0; i < strToConvert.length(); i++) {
      strToConvert[i] = tolower(strToConvert[i]);
   }
   return strToConvert;//return the converted string
}



// private constructor 
Connection::Connection(boost::asio::io_service& io_service,Settings &s, BusDevice &dev) : 
		busDevice(dev),
		fp(s.isRegenerate()),
		settings(s),
		socket_(io_service), 
		active(false), 
		auth_type(0), 
		authorized(false), 
		data_mode(false) {

}



void Connection::sendResponse(string prefix, int code, string message) {
	stringstream buf; 

	buf << prefix << " " << code << " " << message << "\r\n";
	send(buf.str());
}

void Connection::doAuth(string data) {
	string name, value;
	/**
	 * Step 1: Start authentication
	 * Possible commands are: AUTH, HELP, QUIT, EXIT
	 */
	getCommand(data, &name, &value);
	vector<string> validCommands;
	validCommands.push_back(CMD_EXIT);
	validCommands.push_back(CMD_AUTH);
	validCommands.push_back(CMD_HELP);
	validCommands.push_back(CMD_QUIT);

	if (name == "help") {
		sendHelp(validCommands);
	} else if (name == CMD_QUIT || name == CMD_EXIT) {
		sendResponse(RESP_OK,203,OK_CLOSE_CONNECTION);
		LOG4CXX_INFO(Connection::logger,"Client closed connection");
		exitConnection();
		return;
	} else if (name == CMD_AUTH) {
		bool valid=false;
		if ( value == "plain") {
			setAuthType(AUTH_PLAIN);
			valid=true;
		} else if ( value == "md5") {
			setAuthType(AUTH_MD5);
			valid=true;
		} else { 
			valid=false;
		}

		if ( valid) {
			sessionState= user;
			auth_time = getTime();
			sendResponse(RESP_OK,202,auth_time+" "+OK_START_AUTH);
		} else {
			sendResponse(RESP_ERR,407,ERR_AUTH_TYPE_REQUIRED);
		}
	} else {
		sendResponse(RESP_ERR,407,ERR_AUTH_TYPE_REQUIRED);
	}
}

void Connection::doUser(string data) {
	string name, value;
	/**
	 * Step 2: Identify user
	 * Possible commands are: USER, HELP, QUIT, EXIT
	 */
	vector<string> validCmds;
	validCmds.push_back(CMD_EXIT);
	validCmds.push_back(CMD_HELP);
	validCmds.push_back(CMD_QUIT);
	validCmds.push_back(CMD_USER);

	getCommand(data, &name, &value);

	if (name == CMD_HELP) {
		sendln("* Usable commands in this context are:");
		sendln("* EXIT, HELP, QUIT, USER");
		sendHelp(validCmds);
	} else if (name == CMD_QUIT || name == CMD_EXIT) {
		sendResponse(RESP_OK,203,OK_CLOSE_CONNECTION);
		LOG4CXX_INFO(Connection::logger,"Client closed connection");
		exitConnection();
	} else if (name == CMD_USER && value != "") {
		setUsername(value);
		sessionState = pass;
		//if (settings.getUsername() != value) {
		//	LOG4CXX_WARN(Connection::logger,"The specified user name \"" + value + "\" does not exist!");
		//}
		sendResponse(RESP_OK,311,OK_USER_ACCEPTED);
	} else {
		sendResponse(RESP_ERR,332,ERR_USER_NEEDED);
	}
}

void Connection::doPassword(string data) {
	/**
	 * Step 3: Verify password
	 * Possible commands are: USER, HELP, QUIT, EXIT
	 */
	string name,value;
	vector<string> validCmds;
	validCmds.push_back(CMD_PASS);
	validCmds.push_back(CMD_EXIT);
	validCmds.push_back(CMD_HELP);
	validCmds.push_back(CMD_QUIT);

	int tries = 0;
	getCommand(data, &name, &value);
	if (name == CMD_HELP) {
		sendHelp(validCmds);
	} else if (name == CMD_QUIT || name == CMD_EXIT) {
		sendResponse(RESP_OK,203,OK_CLOSE_CONNECTION);
		LOG4CXX_INFO(Connection::logger,"Client closed connection");
		exitConnection();
	}  else if (name == CMD_PASS) {
		if (getAuthType() == AUTH_PLAIN) {
			if (value == settings.getPassword() && username == settings.getUsername()) {
				setAuthorized(true);
				sessionState = main;
				sendResponse(RESP_OK,230, string(OK_USER_LOGIN_SUCCESS)+" "+getUsername());
				LOG4CXX_INFO(Connection::logger,"Authorization successful, user " + settings.getUsername() + " logged in");
			}
		} else if (getAuthType() == AUTH_MD5) {
			LOG4CXX_DEBUG(Connection::logger,"MD5 Hash: " << getMD5Hash(auth_time));
			getMD5Hash(auth_time);
			fflush(stdout);
			if (value == getMD5Hash(auth_time)) {
				setAuthorized(true);
				sessionState=main;
				//send("* Authorization code 1234567");
				sendResponse(RESP_OK,230, string(OK_USER_LOGIN_SUCCESS)+" "+ getUsername());
				LOG4CXX_INFO(Connection::logger,"Authorization successful, user " + settings.getUsername() + " logged in");
					sessionState = main;
			} else if (name == CMD_PASS) {
					#ifdef _WIN32
						Sleep(1000);
					#else
						sleep(1);
					#endif				
					string auth_time = getTime();
					LOG4CXX_WARN(Connection::logger,"Authorization for user " + getUsername() + " failed");
					sendResponse(RESP_ERR,401, auth_time + " "+ERR_PASSWORD_INCORRECT);
			}
		} else {
			LOG4CXX_DEBUG(Connection::logger,"No auth method specified");
			fflush(stdout);
		}
		if ( ! isAuthorized()) {
			tries++;
			if (tries >= settings.getAuthMaxTries()) {
				LOG4CXX_ERROR(Connection::logger,"Maximum number of authentication tries exceeded");
				sendResponse(RESP_ERR,403, ERR_MAX_AUTH_TRIES);
				exitConnection();
				return;			
			} else {
				if (name == CMD_PASS) {
					sendResponse(RESP_ERR,401,ERR_PASSWORD_INCORRECT);
				}
			}
		}
	} else {
		sendResponse(RESP_ERR,413,ERR_INVALID_COMMAND);
		LOG4CXX_WARN(Connection::logger,"Unrecognized command: " + name + " " + value);
	}
}
