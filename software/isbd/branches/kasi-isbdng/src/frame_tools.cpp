
#include "frame_tools.h"
#include "Tools.h"
#include <stdio.h>
#include <ios>
#include <algorithm>
#include <sstream>
#include <iomanip>

#include <log4cxx/logger.h>

#ifdef _WIN32
#include <Winsock2.h>
#else
#include <arpa/inet.h>
#endif

extern log4cxx::LoggerPtr logger; 

unsigned short frame_tools::calc_crc(const std::string isb_data) {
	const unsigned char * data = reinterpret_cast<const unsigned char *> (isb_data.c_str());
	return calc_crc(data,isb_data.length());
}

unsigned short frame_tools::calc_crc(const unsigned char *isb_frame, unsigned int framesize) {

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

bool frame_tools::check_crc(std::string isb_data) {
	const unsigned char *data = reinterpret_cast<const unsigned char *>( isb_data.c_str());
	return check_crc(data,isb_data.length());
}

bool frame_tools::check_crc(const unsigned char *isb_frame, const unsigned int framesize) {

  const unsigned short crc = calc_crc(isb_frame, framesize);
  
  unsigned short fcrc = *(unsigned short*)(&isb_frame[framesize - 3]);

  if (crc == fcrc) {
  
    // crc ok
    LOG4CXX_DEBUG(logger, "frame data: " << Tools::hexDump(isb_frame,framesize) << " - crc is ok");
    return true;
  } else {
    // data corrupted

    LOG4CXX_WARN(logger,"corrupted data - crc does not match, calculated crc: " << std::hex << crc << ", received: " << std::hex << fcrc);
    LOG4CXX_DEBUG(logger, "Frame data: " << Tools::hexDump(isb_frame,framesize));

	// additional check to help debugging...
    if (crc == htons(fcrc) ) {
		LOG4CXX_WARN(logger,"byteswap detected - FIXME! byteorder of CRC is wrong - assuming correct CRC: calc crc: " << std::hex << crc << ", received: " << std::hex << fcrc);
		return true;
    }
    return false;
  }
                                                              
}




