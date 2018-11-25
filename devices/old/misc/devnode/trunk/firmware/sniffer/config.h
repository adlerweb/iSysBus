#ifndef CONFIG_H_
#define CONFIG_H_

//#define DEBUG

#if defined DEVNODE
	#include "devnode.h"
#elif defined CANUSB
	#include "canusb.h"
#else
	#error "No Sniffer Hardware selected! (Supported: DEVNODE, CANUSB)"
#endif

#endif /*CONFIG_H_*/
