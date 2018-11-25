#include "Tools.h"
#include <string>
#include <iomanip>
#include <sstream>

std::string Tools::hexDump(std::string data) {
        std::stringstream retval;

		return hexDump((unsigned char *) data.c_str(),data.length());
}

std::string Tools::hexDump(const unsigned char * framedata, int len) {
	std::stringstream out;
	for (int i=0;i< len;i++) {
        	int val = framedata[i];
		out << std::hex << std::setw(2) << std::setfill('0') 
			<< val << " " ;
	}	
	return out.str();
}

