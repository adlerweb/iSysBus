#ifndef PACKET_H
#define PACKET_H

#define RESERVED 0x00

#define STARTBYTE 0x01
#define STOPBYTE 0x0d
#define HEADER_LEN 5 // flags, 2x src, 2x dest
#define SUFFIX_LEN 2
#define MAX_PACKET_LEN 17

#include <string>
#include <log4cxx/logger.h>

#define INVALID_PACKET Packet(-1,-1,"",0,0);

typedef struct {
	unsigned char startbyte;
	unsigned char flags;
	unsigned short destAddr;
	unsigned short srcAddr;

} isb_header;

class Packet {
	public:
		static log4cxx::LoggerPtr logger;
		static Packet parse(std::string,int protocolVersion=2);
		static Packet unicast(unsigned int src, unsigned int dest, std::string data, unsigned char protocolVersion=2);
		static Packet multicast(unsigned int src, unsigned int dest, std::string data, unsigned char protocolVersion=2);
		static std::string hexDump(const char * framedata, int len);
		std::string hexDump();
		void updateCrc(int protoVersion=2);
		Packet(unsigned int src, unsigned int dest, std::string data, unsigned char flags,unsigned short crc, unsigned char protocolVersion=2);
		Packet();
		std::string toBinary();
		std::string toString();
		bool isValid();
		bool isMulticast();
		unsigned int calcChecksumV1();
		unsigned char calcChecksumV2();
		void setSource(unsigned int newSrc) { srcAddr = newSrc; }
		unsigned int getSource() { return srcAddr; }
		unsigned int getDest() { return destAddr; }
		void setDest(unsigned int newDest) { destAddr = newDest; }
		void setData(std::string newData) { data = newData; }
		std::string getData() { return data; }
		unsigned short getCrc() { return crc; }
		void regenerateCrc();
		char getFlags() { return flags; }
		
	protected: 
		std::string _toBinary(bool calc);
	private:
		unsigned char flags;
		unsigned int srcAddr;
		unsigned int destAddr;
		std::string data;
		unsigned short crc;
		unsigned char protocolVersion;

		unsigned char encodeFlags();
		unsigned short sumFields();
		unsigned int sumV1();
};

#endif
