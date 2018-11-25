/**
==================================================

	linux_server.cpp
	
Version: $Rev$
Last Modification: $Id$

Module: 
Created: 01.07.2007
Author: ig

Copyright 2007 by iSysBus

==================================================
*/
#include  "linux_server.h"
#include <log4cxx/logger.h>

#include <signal.h>

extern log4cxx::LoggerPtr logger;

void sigpipe_handler(int sig) {
  LOG4CXX_WARN(logger,"ignoring sigpipe");
}


/**
 * Prints an error and exits
 */
void error_exit(const char *error_message) {
    fprintf(stderr, "%s: %s\n", error_message, strerror(errno));
   // exit(EXIT_FAILURE);
}

/**
 * Create a socket
 */
int create_socket( int af, int type, int protocol ) {
    socket_t sock;
    const int y = 1;
    /* Erzeuge das Socket */
    sock = socket(af, type, protocol);
    if (sock < 0) error_exit("Fehler beim Anlegen eines Socket");
    /* Mehr dazu siehe Anmerkung am Ende des Listings ... */
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &y, sizeof(int));
    return sock;
}

/* Erzeugt die Bindung an die Serveradresse
 * (genauer an einen bestimmten Port) */
void bind_socket(socket_t *sock, unsigned long adress, unsigned short port) {
   signal(SIGPIPE, sigpipe_handler); // Aufgrund einer racecondition wird manchmal TCP_send aufgerufen, wenn ein anderer Thread den socket schon geschlossen hat. Daher wird hier einfachh sigpipe gefangen und ignoriert. Dass der Handler bei bind neu registiert wird, is auch haesslich...
   struct sockaddr_in server;
   memset( &server, 0, sizeof (server));
   server.sin_family = AF_INET;
   server.sin_addr.s_addr = htonl(adress);
   server.sin_port = htons(port);
   if (bind(*sock, (struct sockaddr*)&server,sizeof(server)) < 0)
       error_exit("Kann das Socket nicht \"binden\"");
}

/* Teile dem Socket mit, dass Verbindungswnsche
 * von Clients entgegengenommen werden */
void listen_socket(socket_t *sock) {
	if (listen(*sock, 5) == 1) error_exit("Fehler bei listen");
}

/* Bearbeite die Verbindungswnsche von Clients
 * Der Aufruf von accept() blockiert solange,
 * bis ein Client Verbindung aufnimmt 
 */
void accept_socket(socket_t *socket, socket_t *new_socket) {
	struct sockaddr_in client;
	socklen_t len;
	len = sizeof(client);
	*new_socket = accept(*socket, (struct sockaddr *)&client, &len);
	if (*new_socket == 1) error_exit("Fehler bei accept");
}

/* Baut die Verbindung zum Server auf */
void connect_socket(socket_t *sock, char *serv_addr,
                    unsigned short port) {
   struct sockaddr_in server;
   struct hostent *host_info;
   unsigned long addr;
   memset( &server, 0, sizeof (server));
   if ((addr = inet_addr( serv_addr )) != INADDR_NONE) {
       /* argv[1] ist eine numerische IP-Adresse */
       memcpy( (char *)&server.sin_addr, &addr, sizeof(addr));
   } else {
       /* Fr den Fall der F„lle: Wandle den
        * Servernamen bspw. "localhost" in eine IP-Adresse um */
       host_info = gethostbyname( serv_addr );
       if (NULL == host_info) error_exit("Unbekannter Server");
       memcpy( (char *)&server.sin_addr, host_info->h_addr,
               host_info->h_length);
   }
   server.sin_family = AF_INET;
   server.sin_port = htons( port );
   /* Baue die Verbindung zum Server auf */
   if (connect(*sock, (struct sockaddr *)&server, sizeof( server)) < 0)
      error_exit( "Kann keine Verbindung zum Server herstellen");
}
/* Daten versenden via TCP */
int TCP_send( socket_t *sock, char *data, size_t size) {
	int retval;
	if((retval = send(*sock, data, size, 0)) == SOCKET_ERROR) {
		LOG4CXX_ERROR(logger,"Error while sending TCP data");
		close_socket(sock);
	}
	return retval;
 //  if(send(*sock, data, size, 0) == 1) LOG4CXX_ERROR(logger,"Error while sending TCP data");
}
/* Daten empfangen via TCP */
int TCP_recv( socket_t *sock, char *data, size_t size) {
    int len;
    len = recv (*sock, data, size, 0);
    if( len > 0 || len != 1 ) data[len] = '\0';
    	else LOG4CXX_ERROR(logger,"Error while receiving TCP data");
    return len;
}

/* Daten senden via UDP */
void UDP_send (socket_t *sock, char *data, size_t size,
                char *addr, unsigned short port){
  struct sockaddr_in addr_sento;
  struct hostent *h;
  int rc;
  /* IP-Adresse vom Server berprfen */
  h = gethostbyname(addr);
  if (h == NULL)
     error_exit("Unbekannter Host?");
  addr_sento.sin_family = h->h_addrtype;
  memcpy ( (char *) &addr_sento.sin_addr.s_addr,
           h->h_addr_list[0], h->h_length);
  addr_sento.sin_port = htons (port);
  rc = sendto(*sock, data, size, 0,
                 (struct sockaddr *) &addr_sento,
                 sizeof (addr_sento));
  if (rc < 0)
     error_exit("Konnte Daten nicht senden sendto()");
}
/* Daten empfangen via UDP */
void UDP_recv( socket_t *sock, char *data, size_t size){
   struct sockaddr_in addr_recvfrom;
   socklen_t len;
   int n;
   len = sizeof (addr_recvfrom);
   n = recvfrom(*sock, data, size, 0, (struct sockaddr *) &addr_recvfrom, &len);
   if (n < 0) {
       printf ("Keine Daten empfangen ...\n");
       return;
    }
}
/* Socket schlie˜en */
void close_socket( socket_t *sock ){
    LOG4CXX_DEBUG(logger,"closing socket");
    socket_t t_sock = *sock;
    *sock = -1;
    close(t_sock);
}
/* Unter Linux/UNIX nichts zu tun ... */
void cleanup(void){
   LOG4CXX_DEBUG(logger,"Aufraeumarbeiten erledigt ...");
   return;}
