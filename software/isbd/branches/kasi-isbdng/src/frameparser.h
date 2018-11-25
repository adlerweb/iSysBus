#ifndef FRAMEPARSER_H
#define FRAMEPARSER_H

#include <iostream>
#include <string>
#include <vector>
#include "packet.h"
#include <log4cxx/logger.h>

class FrameParser {
	public:
		static log4cxx::LoggerPtr logger;
		std::vector<Packet> parse(std::string &fragment,int protocolVersion=2);
		Packet parsePacket(std::string,int protocolVersion=2);
		FrameParser(bool regenerate);
		static bool isFrameComplete(const unsigned char *isb_frame, const unsigned int size);

	private:
		bool 	regenerate;

};
/*
class ParseResult {
	private:
		Packet p;
		int    startPos;
		int 	endPos;
	public:
		Packet p = getPacket() { return p; }
		int getEndPos() { return endPos; }
		int getStartPos() { return startPos; }
		void setPacket(Packet pack) { this.p = pack; }
		void setStartPos(int sp) { this.startPos = sp; }
		void setEndPos(int ep) { this.endPos = ep; }
};
*/
#endif
