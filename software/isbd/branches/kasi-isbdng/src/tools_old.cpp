/**
==================================================

	tools.cpp
	
Version: $Rev$
Last Modification: $Id$

Module: 
Created: 28.08.2007
Author: ig

Copyright 2007 by iSysBus

==================================================
*/
#include "tools_old.h"
#include "Settings.h"
#include "BusDevice.h"
#include "Connection.h"

#include <log4cxx/logger.h>

using namespace std;

extern log4cxx::LoggerPtr mainLogger;
extern bool stop;
extern BusDevice busDevice;


/**
 * Starts a thread
 */

/*
DEPRECATED: now uses boost:thread
void *start_thread(void* arg) {
	
	THREAD_PARAM *p = (THREAD_PARAM *) arg;
	Runnable *runnable = (Runnable *) p->user;
	
	if ( runnable != NULL ) {	
		runnable->run();
	}

	return NULL;
} */

/**
 * Put the program into the background
 */
void daemonize(void) {

#ifdef _WIN32
	LOG4CXX_INFO(mainLogger,"The program cannot be daemonized when running under windows");
#else
	pid_t pid, sid;
	
	pid = fork();
	if (pid == -1) {
		LOG4CXX_ERROR(mainLogger,"The process couldn't be forked");
		return;
	}
	

	if (pid != 0) {
		// Exit the parent process	
		exit(0);
	}
	
	// Create a new SID for the child process
    sid = setsid();
    if (sid < 0) {
		LOG4CXX_ERROR(mainLogger,"A new SID couldn't be created");
	}

    /* Change the current working directory */
	if ((chdir("/")) < 0) {
      /* Log the failure */
      LOG4CXX_FATAL(mainLogger,"Couldn't chdir to /");
	}
#endif
}

#ifndef _WIN32

void make_pidfile() {
#if 1
#warning "make_pidfile ist nicht implementiert"
#else
	FILE    *pf;         /* We use a FILE to use fscanf */
	int      fd;         /* File descriptor for pid file */
	int      fpid;       /* PID found in existing pidfile */
	int      opid;       /* Our PID */
	string pidfilename;
#endif
	
/*	
	pidfilename = "/var/run/isbd.pid";

	pf = fopen("/var/run/isbd.pid", "r");
	if (pf) {
		if (fscanf(pf, "%d", &fpid)) {
			// Check whether the daemon is already running
			if (!(kill(fpid, 0) == -1 && errno == ESRCH)) {
				// Error, another instance seems to be alive
				fclose(pf);
				LOG4CXX_FATAL(mainLogger,"Another instance seems to be running already");
			}
		}
	    // Stale PID file, remove it
	    fclose(pf);
	    if (unlink(pidfilename) != 0) {
			LOG4CXX_FATAL(mainLogger,"The PIDfile couldn't be removed");
		}
	}
*/
	/* Write a new  PID file. */
/*
	fd = creat(pidfilename, 0644);
	if (fd < 0) {
		LOG4CXX_FATAL(mainLogger,"No valid handle while creating PIDfile");
    }
	if (flock(fd, LOCK_EX | LOCK_NB) < 0) {
		LOG4CXX_FATAL(mainLogger,"PIDfile couldn't be locked");
    }
	opid = getpid();
	pf = fdopen(fd, "w");
	if (!pf) {
		LOG4CXX_FATAL(mainLogger,"No valid file handle while trying to write PIDfile");
    }
	fprintf(pf, "%d\n", opid);
	fflush(pf);
	flock(fd, LOCK_UN);
	close(fd);
	*/
}
#endif

void handle_sighup(int recv_sig) {
  /* do something */
}

void handle_sigint(int recv_sig) {
	LOG4CXX_INFO(mainLogger,"Caught SIGINT, exiting program");
 	stop = true;
 	//busDevice.stop();
 	//busDeviceThread.join(&status);
 	/*for (unsigned int i = 0; i < connections.size(); i++) {
		if (connections[i].isActive() == true) {
			connections[i].stop();
		//	connections[i].join(&status);
		}
 	}*/

 	LOG4CXX_INFO(mainLogger,"Exit program");
 	exit(0);
}

void waitforchild() {
	//wait();
}
