#ifndef TOOLS_H
#define TOOLS_H

#include <string> 

class Tools {
	public:
		 static std::string hexDump(std::string);
		 static	std::string hexDump(const unsigned char * framedata, int len);
};
#endif
