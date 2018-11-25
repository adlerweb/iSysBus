/**
==================================================

	win32_server.h
	
Version: $Rev$
Last Modification: $Id$

Module: 
Created: 01.07.2007
Author: ig

Copyright 2007 by iSysBus

==================================================
*/
#ifndef WIN_SERVER_H_
#define WIN_SERVER_H_

#include <stdio.h>
#include <stdlib.h>
#include <winsock.h>
#include <windows.h>
#include <io.h>

// Create abstract socket type
#define socket_t SOCKET
void error_exit(char *error_message);
int create_socket( int af, int type, int protocol );
void bind_socket(socket_t *sock, unsigned long adress, unsigned short port);
void listen_socket( socket_t *sock );
void accept_socket( socket_t *new_socket, socket_t *socket );
void connect_socket(socket_t *sock, char *serv_addr, unsigned short port);
int TCP_send( socket_t *sock, char *data, size_t size);
int TCP_recv( socket_t *sock, char *data, size_t size);
void UDP_send (socket_t *sock, char *data, size_t size);
void UDP_recv( socket_t *sock, char *data, size_t size, char *addr, unsigned short port);
void close_socket(int *sock);
void cleanup(void);

#endif /*WIN_SERVER_H_*/
