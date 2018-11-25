#ifndef _CRC_H__
#define _CRC_H__

#include <string>

#define START_BYTE 0x01
#define STOP_BYTE 0x0d

class frame_tools {
	public:
		static bool check_crc(const unsigned char *isb_frame, const unsigned int framesize);
		static bool check_crc(const std::string isb_data);
		static bool is_frame_complete(const unsigned char *isb_frame, const unsigned int size);
		static std::string hexDump(const unsigned char *,int);
		static unsigned short calc_crc(const unsigned char *isb_frame, unsigned int framesize);
		static unsigned short calc_crc(std::string);
};

#endif


