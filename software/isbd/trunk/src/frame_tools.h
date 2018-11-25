#ifndef _CRC_H__
#define _CRC_H__

#include <string>

#define START_BYTE 0x01
#define STOP_BYTE 0x0d

unsigned short calc_crc(const unsigned char *isb_frame, unsigned int framesize);
bool check_crc(const unsigned char *isb_frame, const unsigned int framesize);
bool is_frame_complete(const unsigned char *isb_frame, const unsigned int size);
std::string hexDump(const unsigned char *,int);


#endif


