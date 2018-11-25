/**
==================================================

	runnable.h
	
Version: $Rev$
Last Modification: $Id$

Module: 
Created: 01.07.2007
Author: ig

Copyright 2007 by iSysBus

==================================================
*/
#ifndef RUNNABLE_H_
#define RUNNABLE_H_

using namespace std;

class Runnable {
		virtual void start() = 0;
	public:
		void run() { printf("TEST\n"); fflush(stdout); //start(); 
		this->start();
		}
		virtual ~Runnable() {}
};

#endif /*RUNNABLE_H_*/
