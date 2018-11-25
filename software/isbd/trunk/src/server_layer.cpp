/**
==================================================

	server_layer.cpp
	
Version: $Rev$
Last Modification: $Id$

Module: 
Created: 01.07.2007
Author: ig

Copyright 2007 by iSysBus

==================================================
*/
#include <iostream>
#include <fcntl.h>
#include <sys/types.h>
//#include <sys/socket.h>

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>


#include <log4cxx/logger.h>
#include "Settings.h"
#include "Connection.h"
#include "tools.h"
#include "BusDevice.h"

#ifdef _WIN32
	#include "win32_server.h"
	#include <winbase.h>
#else
	#include "linux_server.h"
#endif

#define BUF 1024
#define MAX_CONNECTIONS 8

extern log4cxx::LoggerPtr logger;
extern Settings settings;
extern bool stop;

vector<Connection> connections;

extern BusDevice busDevice;

using namespace std;

/**
 * Start the server for incoming connections
 */
void server_start() {
	socket_t sock1, sock2;
	//int addrlen;
	unsigned int i, ready, sock_max, max=-1;
	//int client_sock[FD_SETSIZE];
	fd_set gesamt_sock, lese_sock;
	//char *buffer = (char*) malloc(BUF);
		
	sock_max = sock1 = create_socket(AF_INET, SOCK_STREAM, 0);
	atexit(cleanup);
	//@TODO Bind to specific address
	bind_socket(&sock1, INADDR_ANY, settings.getTcpPort());
	listen_socket(&sock1);
	LOG4CXX_INFO(logger,"Listening on port " + settings.getTcpPortAsString());
	
	for (i = 0; i < connections.size(); i++) {
		connections[i].setSocket(-1);
	}

	FD_ZERO(&gesamt_sock);
	FD_SET(sock1, &gesamt_sock);
	
	for (;;) {
		if (stop == true) break;
		
		lese_sock = gesamt_sock;
		/**
		 * Wait for incoming connections
		 */
		ready = select(sock_max + 1, &lese_sock, NULL, NULL, NULL);

		/**
		 * Incoming connection
		 */
		if (FD_ISSET(sock1, &lese_sock)) {
			accept_socket(&sock1, &sock2);
			/**
			 * Allocate free socket descriptor 
			 * and assign it
			 */
			Connection newConn;
			if ( connections.size()== FD_SETSIZE) {
				LOG4CXX_ERROR(logger,"Too many connections!");
			}
				
			if ( connections.size()==0) {
				connections.add(newConn);
				newConn.setSocket(sock2);
				 boost::thread connectionThread(boost::bind(&Connection::start,&newConn));
			} else {
				// there are already connections available - try to reuse them 
				for (i = 0; i < connections.size(); i++) {
			 		if ((int)connections[i].getSocket() < 0) {
			 		connections[i].setSocket(sock2);
			 		boost::thread connectionThread(boost::bind(&Connection::start,&connections[i]));
					//connectionThread.threadExit()
			 		break;
			 		}
				}
				if ( i== connections.size())
			}
		 	if (i == FD_SETSIZE) {

		 	/**
		 	 * Add current socket descriptor
		 	 */
		 	FD_SET(sock2, &gesamt_sock);
		 	/**
		 	 * select() needs the highest socket descriptor
		 	 */
		 	if (sock2 > sock_max) sock_max = sock2;
		 	if (i > max) max = i;
		 	
		 	/**
		 	 * Are there any waiting descriptors?
		 	 */
		 	if (--ready <= 0) continue;
		} // end if (FD_ISSET...
	} // end for
}
