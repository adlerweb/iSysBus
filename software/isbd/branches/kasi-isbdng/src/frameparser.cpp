#include <iostream>
#include "frameparser.h"
#include "packet.h"
#include <string>
#include <vector>

#include <log4cxx/logger.h>

extern log4cxx::LoggerPtr logger;
using namespace std;

log4cxx::LoggerPtr FrameParser::logger(log4cxx::Logger::getLogger("org.isysbus.FrameParser"));

Packet FrameParser::parsePacket(string packet,int protocolVersion) {
	return Packet::parse(packet,protocolVersion);
}

FrameParser::FrameParser(bool regen) {
	regenerate=regen;
}

std::vector<Packet> FrameParser::parse(std::string &fragment,int protocolVersion) {

	size_t startPos;
	size_t endPos;
	vector<Packet> retval;

	startPos = fragment.find(STARTBYTE);
	unsigned char flags = fragment[startPos+1];
	unsigned char databytes = flags & 0x0F;

	unsigned char calcPacketLen = 2+ HEADER_LEN  + databytes+SUFFIX_LEN;
	LOG4CXX_TRACE(logger,"Data bytes: "  <<  std::hex << (unsigned int) databytes);
	unsigned int firstEndPos= startPos+2+HEADER_LEN+databytes+1;

	endPos = fragment.find(STOPBYTE,firstEndPos);
	
//	LOG4CXX_DEBUG(logger, "First startbyte: " << startPos << " end: " << endPos
//			<< " calc len " << std::hex <<  (unsigned int) calcPacketLen); 

	LOG4CXX_TRACE(logger, "Start:" << startPos << "End: " << endPos);

	while ( startPos != string::npos && endPos != string::npos ) {
		
		Packet p = parsePacket(fragment.substr(startPos,endPos-startPos+1),protocolVersion);
		LOG4CXX_TRACE(logger, "Erasing frame from fragment");
		// we erase from the start as leading incomplete data is of no future use...
		fragment.erase(0,endPos+1);
		if ( p.getCrc()==0 && regenerate) {
			LOG4CXX_TRACE(logger," CRC is 0 => regenerating");
			p.regenerateCrc();	
		}

		if ( p.isValid() ) {
			LOG4CXX_TRACE(logger, "Packet is valid!");
			LOG4CXX_TRACE(logger, "Dump parsed packet: " << p.hexDump());
			retval.push_back(p);
		} else {
			LOG4CXX_WARN(logger,"Invalid packet: "<< p.hexDump());
		}
		startPos = fragment.find(STARTBYTE);
		firstEndPos= startPos+2+HEADER_LEN+databytes+1;
		endPos = fragment.find(STOPBYTE,firstEndPos);
	}
	if ( startPos != string::npos && endPos == string::npos ) { 
		LOG4CXX_TRACE(logger,"Unterminated packet found");
	}
	return retval;
}

bool FrameParser::isFrameComplete(const unsigned char *isb_frame, const unsigned int size) {

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


