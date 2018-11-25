/**
==================================================

	win32_server.cpp
	
Version: $Rev$
Last Modification: $Id$

Module: 
Created: 01.07.2007
Author: ig

Copyright 2007 by iSysBus

==================================================
*/
#include <stdio.h>
#include <winsock.h>
#include <windows.h>
#include "win32_server.h"
#include "logger.h"

#define socket_t SOCKET

extern Logger logger;

/**
 * This function displays errors
 */
void error_exit(char *error_message) {
	logger.error(error_message);
	//@TODO logging
	exit(EXIT_FAILURE);
}

/*
 * Create socket for the windows environment
 */
int create_socket(int af, int type, int protocol) {
    socket_t sock;
    WORD wVersionRequested;
    WSADATA wsaData;
    wVersionRequested = MAKEWORD (1, 1);
    if (WSAStartup(wVersionRequested, &wsaData) != 0) logger.fatal("Error while initializing winsock!");
    else logger.info("Winsock initialized\n");
    sock = socket(af, type, protocol);
    if (sock < 0) logger.fatal("Error creating socket");
    return sock;
}

/**
 * Bind to port
 */
void bind_socket(socket_t *sock, unsigned long adress, unsigned short port) {
	struct sockaddr_in server;
	memset(&server, 0, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htonl(adress);
	server.sin_port = htons(port);
	if (bind(*sock, (struct sockaddr*)&server, sizeof(server)) == SOCKET_ERROR)
		logger.fatal("Can't bind to socket");
	else logger.info("Bound to socket");
}

/**
 * Listen on socket for incoming connections
 */
void listen_socket(socket_t *sock) {
	if(listen(*sock, 5) == -1) error_exit("Error start listening");
}

/**
 * Wait for incoming connections
 * Function is blocking
 */
void accept_socket(socket_t *socket, socket_t *new_socket) {
   struct sockaddr_in client;
   int len;
   len = sizeof(client);
   *new_socket=accept(*socket, (struct sockaddr *)&client, &len);
   if (*new_socket == INVALID_SOCKET) logger.fatal("Error accepting connection");
}

/**
 * Connect to server
 */
void connect_socket(socket_t *sock, char *serv_addr, unsigned short port) {
	struct sockaddr_in server;
	struct hostent *host_info;
	unsigned long addr;
	memset( &server, 0, sizeof (server));
	if ((addr = inet_addr( serv_addr )) != INADDR_NONE) {
		memcpy((char *)&server.sin_addr, &addr, sizeof(addr));
	} else {
       host_info = gethostbyname(serv_addr);
       if (host_info == NULL) logger.fatal("Unknown server");
       memcpy((char *)&server.sin_addr, host_info->h_addr, host_info->h_length);
   }
   server.sin_family = AF_INET;
   server.sin_port = htons( port );
	/* Start opening the connection */
	if (connect(*sock, (struct sockaddr*)&server, sizeof( server)) < 0)
		logger.fatal("Unable to connect to server");
}

/**
 * Send data via tcp
 */
int TCP_send(socket_t *sock, char *data, size_t size) {
	int retval;
	if((retval = send(*sock, data, size, 0)) == SOCKET_ERROR) {
		logger.error("Error while sending TCP data");
		close_socket((int*)&sock);
	}
	return retval;
}

/**
 * Receive data via TCP
 */
int TCP_recv(socket_t *sock, char *data, size_t size) {
    int len;
    len = recv(*sock, data, size, 0);
    if (len > 0 || len != SOCKET_ERROR) data[len] = '\0';
    	else len = -1;
    if (len == SOCKET_ERROR) {
    	
    	close_socket((int*)&sock);
    }
    return len;
}

/**
 * Send data via UDP
 */
void UDP_send(socket_t *sock, char *data, size_t size, char *addr, unsigned short port) {
	struct sockaddr_in addr_sento;
	struct hostent *h;
	int rc;
	h = gethostbyname(addr);
	if (h == NULL) logger.fatal("Unknown host?");
	addr_sento.sin_family = h->h_addrtype;
	memcpy((char *) &addr_sento.sin_addr.s_addr, h->h_addr_list[0], h->h_length);
	addr_sento.sin_port = htons(port);
	rc = sendto(*sock, data, size, 0, (struct sockaddr *) &addr_sento, sizeof (addr_sento));
	if (rc == SOCKET_ERROR) logger.fatal("Unable to send UDP data");
}

/**
 * Receive data via UDP
 */
void UDP_recv(socket_t *sock, char *data, size_t size) {
	struct sockaddr_in addr_recvfrom;
	int len;
	int n;
	len = sizeof(addr_recvfrom);
	n = recvfrom(*sock, data, size, 0, (struct sockaddr *) &addr_recvfrom, &len);
	if (n == SOCKET_ERROR) error_exit("Error receiving UDP Data");
}

/**
 * Close socket
 */
void close_socket(int *sock){
	printf("Close socket:: %d", closesocket(*sock));
}

/**
 * Clean up socket
 */
void cleanup(void){
	WSACleanup();
	logger.info("Socket cleanup...");
}
