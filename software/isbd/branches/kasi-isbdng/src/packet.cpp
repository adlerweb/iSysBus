#include "packet.h"

#include <arpa/inet.h>
#include <string.h>
#include <iomanip>
#include <sstream>
#include "Tools.h"

#include <iostream>

#include <log4cxx/logger.h>

log4cxx::LoggerPtr Packet::logger(log4cxx::Logger::getLogger("org.isysbus.Packet"));

using namespace std;

#define SWAP(x) ((x & 0xff) << 8 | ((x >> 8 ) &0xff) )
#define HI(x) (x >> 8) 
#define LO(x) (x & 0xff)

// msg struct:    

typedef struct Isb_Msg_t Isb_Msg_t;
struct Isb_Msg_t
{
uint8_t Flags;
uint16_t DestId;
uint16_t SourceId;
uint8_t Data[8];
};

unsigned short calc_crc_v1(const unsigned char *isb_frame, unsigned int framesize) {

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

	LOG4CXX_TRACE(Packet::logger, std::hex << "V1 CRC Sum: " << Sum);
    while ((framesize = (unsigned short) (Sum >> 16)) != 0) {
            Sum = (unsigned short) Sum + framesize;
    }

    const unsigned short val = (unsigned short) (Sum ^ 0xFFFF)+1;

	return val;
}


uint16_t Lib_Crc_Calc16(const unsigned char* aData, uint16_t aLength) {
	uint32_t Sum = 0;
	while (1) {
		if (aLength < 2) {
			break;
		}
		Sum += *((uint16_t *)aData);
		aData += 2;
		aLength -= 2;
	}
	if (aLength) {
		Sum += *(uint8_t *) aData;
	}
	while ((aLength = (uint16_t) (Sum >> 16)) != 0) {
		Sum = (uint16_t) Sum + aLength;
	}
	return (uint16_t) Sum ^ 0xFFFF;
}

unsigned int Packet::sumV1() {
     std::string data = _toBinary(false); 
    int framesize = data.length();
    const char *cstr = data.c_str();
    framesize -= 3; // daten ohne start- und stop-byte, ohne crc
    unsigned int Sum = 0;

    for (int i=0;i< framesize;i+=2) {
            if (framesize -i < 2) {
                    break;
            }
	unsigned short current = *((unsigned short*) cstr+i);	
        Sum += current;
        framesize -= 2;
    }

    if (framesize) {
            Sum += *(unsigned char *) cstr;
    }

    while ((framesize = (unsigned short) (Sum >> 16)) != 0) {
            Sum = (unsigned short) (Sum + framesize);
    }

    const unsigned short val = (unsigned short) (Sum ^ 0xFFFF)+1;
    return SWAP(val); // (val << 8) | (val >> 8);
}

unsigned short Packet::sumFields() {
	unsigned int sum = 0;
	unsigned short tmp;

	unsigned char encFlags = encodeFlags();
//	LOG4CXX_DEBUG(Packet::logger, "Encoded flags:" << std::hex << static_cast<int>(static_cast<char>(encFlags)));
	if ( protocolVersion == 1 ) {

		// v1 works word wise
		// 0x28, 0xe,
		// 0, 0x17,
		// 0, 0x22, hi dst,
		// 0x1, 0x10,
		// 0xff, 0xff,
		// 0, 0,
		// 0, 0xd6,
		// 0xa8, 0xd

		// SOH is part of the V1 checksum!
             	// sum+=0x01; // SOH is part of the V1 checksum!
	
		/*Isb_Msg_t msg;
		msg.DestId = destAddr;
		msg.SourceId = srcAddr;
		msg.Flags = encFlags;
		memcpy(msg.Data,data.c_str(),data.length());
		LOG4CXX_DEBUG(Packet::logger," Length: " << (5+data.length()) );*/

//		unsigned short v1src = Lib_Crc_Calc16(&msg,5+data.length());
		std::string bin = _toBinary(false);
		const char * binval = bin.c_str();
		unsigned short v1crc = calc_crc_v1((const unsigned char *) (binval),5+data.length());

		LOG4CXX_TRACE(Packet::logger," AVR sum: " << std::hex << v1crc);
		return SWAP(v1crc);


		


             	tmp = LO(destAddr)  + encFlags*256;
             	LOG4CXX_TRACE(Packet::logger,"1+2:" << std::hex <<tmp);
             	sum+=tmp;
		
		tmp = LO(srcAddr) * 256 + HI(destAddr);
		sum+=tmp;
		LOG4CXX_TRACE(Packet::logger,"3+4:" << std::hex <<tmp);

		tmp = HI(srcAddr);

	} else {
		// V2 works byte wise
		sum += encFlags;
		sum += srcAddr &0xff;
		sum += srcAddr >> 8;
		sum += destAddr &0xff;
		sum += destAddr >>8 ;
	}

	int dataBytes = data.length();
//	LOG4CXX_DEBUG(Packet::logger,"Data len from string:" << dataBytes);
	if ( dataBytes > 8 ) {
		dataBytes = 8;
	}


	if ( 1 == protocolVersion )  {
		unsigned char *ucdata = (unsigned char *) data.c_str();
		int i=0;
		while ( i < dataBytes ) {
				if (i == 0 ) {
					tmp += ucdata[0] *256;
					LOG4CXX_TRACE(Packet::logger," 5+6 " << std::hex << tmp);
					sum+=tmp;
					i++;
				} else if (i != dataBytes-1 ) {
					LOG4CXX_TRACE(Packet::logger, "Index: " << i);
					tmp = ucdata[i+1]+ucdata[i]*256;
					LOG4CXX_TRACE(Packet::logger, "" << i << "+" << (i+1) << ": " << std::hex <<tmp);
					sum+=tmp;
					i+=2;
				} else {
					LOG4CXX_TRACE(Packet::logger, "Index: " << i);
					LOG4CXX_TRACE(Packet::logger,"last index adding only one");
					sum+=ucdata[i];
					i++;
				}
		}
	} else {
		for ( int i=0;i< dataBytes;i++) {
			sum+=data[i];
		}
	}
	LOG4CXX_TRACE(Packet::logger, " Sum: " << std::hex << sum);
	return sum &0xFFFF;
}

unsigned int Packet::calcChecksumV1() {

	unsigned int sum;

	sum = sumFields();
	unsigned int tmp;
	// works word wise ...

	// cut msbs and add them
	tmp = sum >>16;
	while ( tmp > 0 ) {
		LOG4CXX_TRACE(Packet::logger,"sum had overflow => adding"  <<tmp );
		sum = (sum&0xffff)+tmp;
		tmp = sum >> 16;
	}

	unsigned int retval = sum & 0xFFFF;
	retval = (retval ^ 0xFFFF) +1;
	return retval;
}

unsigned char Packet::calcChecksumV2() {
	unsigned int sum = sumFields();
	unsigned char retval = sum & 0xFF;

	retval = (retval ^ 0xFF) +1;

	return retval;
}
void Packet::regenerateCrc() {
	int calcChecksum;

	if ( protocolVersion == 1 ) {
		calcChecksum = calcChecksumV1();
	} else {
		calcChecksum = calcChecksumV2();
	}
	crc = calcChecksum;
}

bool Packet::isValid() {
	bool retval = true;
	
	retval &= srcAddr>=0;
	retval &= destAddr>=0;
	retval &= (srcAddr!=destAddr || isMulticast());

	if ( protocolVersion == 1 ) {
		return retval;
	}

	int calcChecksum =-1;

	if ( protocolVersion == 1 ) {
		calcChecksum = calcChecksumV1();
	} else {
		calcChecksum = calcChecksumV2();
	}

	LOG4CXX_TRACE(Packet::logger,"Calc. checksum: 0x" << std::hex << calcChecksum );
	retval &= ( crc == calcChecksum);
	return retval;
}

Packet::Packet() {

}

Packet::Packet( unsigned int pSrcAddr, 	unsigned int pDestAddr, std::string pData, unsigned char pFlags, unsigned short pCrc, unsigned char pProtoVersion) {
	flags = pFlags;
	srcAddr = pSrcAddr;
	destAddr = pDestAddr;
	data = pData;
	crc = pCrc;
	protocolVersion = pProtoVersion;
}

unsigned char Packet::encodeFlags() {
	if ( data.length()>8) {
		return flags <<4 | 8;
	}
	return flags << 4 | (unsigned char) data.length();
}

std::string Packet::toBinary() {
	return _toBinary(true);
}

std::string Packet::_toBinary(bool calc) {
	std::stringstream retval(std::stringstream::out|std::stringstream::binary);
	unsigned char encodedFlags = encodeFlags();
	
	unsigned int calcCrc;
	if ( calc) {
		if ( protocolVersion == 1) {
			calcCrc = calcChecksumV1();
		} else {
			calcCrc = calcChecksumV2();
		}
	} else {
		calcCrc = crc;
	}

	retval << (unsigned char) STARTBYTE;
	retval << encodedFlags;

	retval << (unsigned char) (destAddr % 256);
	retval << (unsigned char) (destAddr / 256);
	retval << (unsigned char) (srcAddr % 256);
	retval << (unsigned char) (srcAddr /256);
	retval.write(data.c_str(),data.length()) ;
	if ( protocolVersion == 1) {
		retval << (unsigned char) (calcCrc %256);
		retval << (unsigned char) (calcCrc /256);
	} else {
		retval << (unsigned char) RESERVED;
		retval << (unsigned char) (calcCrc &0xff);
	}
	retval << (unsigned char) STOPBYTE;
	return retval.str();
}

std::string Packet::toString() {
	std::stringstream retval;
	retval << "from: " << std::hex << srcAddr <<  " to: "
			<< std::hex << destAddr
			<< " data len: " << data.length()
			<< " flags: " << std::hex << static_cast<int>(static_cast<char> (flags))
			<<  " crc: " << std::hex << crc;
	return retval.str();
}

Packet Packet::unicast(unsigned int src, unsigned int dest, std::string data, unsigned char protocolVersion) {
	return Packet(src,dest,data,0,0,protocolVersion);
}

Packet Packet::multicast(unsigned int src, unsigned int dest, std::string data, unsigned char protocolVersion) {
	return Packet(src,dest,data,2,0,protocolVersion);
}

Packet Packet::parse(std::string packet,int protocolVersion) {
	unsigned short srcAddr = 0;
	unsigned short destAddr = 0;

	// basic check: is this a complete packet?
	size_t startPos = packet.find(STARTBYTE);
	size_t endPos = packet.rfind(STOPBYTE);
	LOG4CXX_TRACE(Packet::logger, " start: " << startPos << " endPos: " << endPos << "len: " << packet.length());
	if ( startPos != 0 || endPos != packet.length() -1 || endPos - startPos > MAX_PACKET_LEN ) {
		return INVALID_PACKET;
	}

	LOG4CXX_TRACE(Packet::logger," length check passed");

	isb_header *hdr = (isb_header *) packet.c_str();

	unsigned char flags = hdr->flags;
	srcAddr = hdr->srcAddr;
	destAddr = hdr->destAddr;

	unsigned char databytes = flags & 0x0F;
	flags = flags & 0xf0;
	flags = flags >>4;

	//srcAddr =  packet[3]*256 + packet[2];
	//destAddr = packet[5]*256 + packet[4];
//	srcAddr = (unsigned short) (raw+2);
	//destAddr = (unsigned short) (raw+4);

	unsigned char calcPacketLen = 2+ HEADER_LEN  + databytes+SUFFIX_LEN;

	unsigned char * ucdata = (unsigned char *) packet.c_str();

	LOG4CXX_TRACE(Packet::logger," new len: " << packet.length());
	LOG4CXX_TRACE(Packet::logger," PKT: " << Tools::hexDump(packet));
	unsigned short crc;

	if (1== protocolVersion ) {
		 crc = ucdata[packet.length()-2] *256 + ucdata[packet.length()-3];
	} else {
		crc = (unsigned char ) ucdata[packet.length()-2];
	}

	LOG4CXX_TRACE(Packet::logger," calc packet len: " << (int) calcPacketLen
			<< " len: " << packet.length()
			<< " CRC: " << std::hex << crc);

	std::string data = packet.substr(1+HEADER_LEN,databytes);
	LOG4CXX_TRACE(Packet::logger,"Raw data len:" << data.length());
	return Packet(srcAddr,destAddr,data,flags,crc,protocolVersion);
}

void Packet::updateCrc(int protoVersion) {
	if (protoVersion==2) {
		crc = calcChecksumV2();
	} else {
		crc = calcChecksumV1();
	}
}

std::string Packet::hexDump() {
	std::string packetStr = toBinary();
	return Tools::hexDump(packetStr);
}

/*std::string Packet::hexDump(const char * framedata, int len) {
    std::stringstream out;
    for (int i=0;i< len;i++) {
    	unsigned int val = framedata[i];
    	out << std::hex << std::setw(2) << std::setfill('0')
    		<< static_cast<int>(static_cast<unsigned char>(val)) << " ";
    }
    return out.str();
}*/

bool Packet::isMulticast() {
	return flags == 0x02;
}
