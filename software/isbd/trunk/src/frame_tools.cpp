
#include "frame_tools.h"
#include <stdio.h>
#include <ios>
#include <algorithm>
#include <sstream>

#include <log4cxx/logger.h>

#ifdef _WIN32
#include <Winsock2.h>
#else
#include <arpa/inet.h>
#endif

//extern log4cxx::LoggerPtr logger; 

unsigned short calc_crc(const unsigned char *isb_frame, unsigned int framesize) {

  // code aus avrlib uebernommen.
  // evtl. gemeinsem code verwenden!
  
    const unsigned char *data = isb_frame;
    framesize -= 3; // daten ohne start- und stop-byte, ohne crc

    unsigned int Sum = 0;

    while (1) {
            if (framesize < 2) {
                    break;
            }
            Sum += *((unsigned short *)data);
            data += 2;
            framesize -= 2;
    }
    if (framesize) {
            Sum += *(unsigned char *) data;
    }
    while ((framesize = (unsigned short) (Sum >> 16)) != 0) {
            Sum = (unsigned short) Sum + framesize;
    }

    const unsigned short val = (unsigned short) (Sum ^ 0xFFFF)+1;
    return (val << 8) | (val >> 8);

}

bool check_crc(const unsigned char *isb_frame, const unsigned int framesize) {

  const unsigned short crc = calc_crc(isb_frame, framesize);
  
  unsigned short fcrc = *(unsigned short*)(&isb_frame[framesize - 3]);

  if (crc == fcrc) {
  
    // crc ok
    //LOG4CXX_DEBUG(logger, "frame data: " << hexDump(isb_frame,framesize) << " - crc is ok");
    return true;
  } else {
    // data corrupted

    //LOG4CXX_WARN(logger,"corrupted data - crc does not match, calculated crc: " << std::hex << crc << ", received: " << std::hex << fcrc);
    //LOG4CXX_DEBUG(logger, "Frame data: " << hexDump(isb_frame,framesize));

	// additional check to help debugging...
    if (crc == htons(fcrc) ) {
		//LOG4CXX_WARN(logger,"byteswap detected - FIXME! byteorder of CRC is wrong - assuming correct CRC: calc crc: " << std::hex << crc << ", received: " << std::hex << fcrc);
		return true;
    }
    return false;
  }
                                                              
}


std::string hexDump(const unsigned char * framedata, int len) {
	std::stringstream out;
	for (int i=0;i< len;i++) {
		out << std::hex << (void *) framedata[i] << " " ;
	}	
	return out.str();
}
	
bool is_frame_complete(const unsigned char *isb_frame, const unsigned int size) {

 const static unsigned int MIN_ISB_MSG_SIZE = 9;
 
 if (MIN_ISB_MSG_SIZE <= size) {      
				
   const unsigned int dlc = isb_frame[1] & 0x0F;
   const unsigned int framesize = dlc + MIN_ISB_MSG_SIZE;
				
   if (size == framesize) {
     //LOG4CXX_DEBUG(logger,"msg dlc: %d, framesize: %d\n", dlc, framesize);
     return true;				
   }
 }
 
 return false;

}


