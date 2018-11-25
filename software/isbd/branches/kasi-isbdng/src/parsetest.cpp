#include <log4cxx/logger.h>
#include "log4cxx/basicconfigurator.h"
#include "log4cxx/propertyconfigurator.h"

#include <boost/program_options.hpp>
#include <boost/foreach.hpp>
#include <boost/tokenizer.hpp>


#include "frameparser.h"
#include "Tools.h"
#include "packet.h"
#include "isbdatagram.h"

#include <sstream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

log4cxx::LoggerPtr logger(log4cxx::Logger::getLogger("isbd"));

std::string hexDump(const char *data, int len) {
	return Tools::hexDump((unsigned char *) data,len);
}

bool __assertParse(FrameParser &fp,std::string pktData, unsigned int version, std::string descr, bool expectValid, int testNr) {
	cerr << "Test #" << testNr << ": " << descr << " (V" << version <<") : " ;
	LOG4CXX_DEBUG(logger, descr);
	LOG4CXX_DEBUG(logger,"  -- hexdump: " << Tools::hexDump(pktData));
	std::vector<Packet> pkts = fp.parse(pktData,version);
	if ( ! expectValid ) {
			if ( pkts.size() > 0 && pkts[0].isValid()) {	
				cerr << "******TEST FAILED - packet is recognized as valid but isn't!***" << endl;
				return false;
			}
	} else {
		if ( ( pkts.size() <1 ) || ! pkts[0].isValid() ) {	
			cerr << "******TEST FAILED - packet is recognized as invalid!***" << endl;
			return false;
		} else {
      ISBDatagram d(pkts[0].getData());
    }
	}
	cerr << "OK." << endl;
	return true;
}


bool assertInvalidParse(FrameParser &fp,std::string pktData, unsigned int version, std::string descr,int nr) {
	return __assertParse(fp,pktData,version,descr,false,nr);
}

void assertValidParse(FrameParser &fp,std::string pktData, unsigned int version, std::string descr, int nr) {
	__assertParse(fp,pktData,version,descr,true,nr);
}


int main (int argc, char **argv){

	bool regenerate=false;
	
	if (argc  >1 ) {
		regenerate=true;
	}

	string loggerCfg;
	//string loggerCfg = settings.getLoggerConfig();

	if ( loggerCfg.length() >0 ) {
		log4cxx::PropertyConfigurator::configure(loggerCfg);
	} 
	bool initialized = log4cxx::Logger::getRootLogger()->getAllAppenders().size() ? true : false;

	if( ! initialized ) {
		// config did not work i.e. no logging properties configured or file could not be read ...
		cout << "Logging not configured: using basic configurator" <<endl;
		log4cxx::BasicConfigurator::configure();
		log4cxx::Logger::getRootLogger()->setLevel(log4cxx::Level::getTrace());
	}

	unsigned short us;
	unsigned int ui;

	LOG4CXX_DEBUG(logger,"unsigned short:" << sizeof(us));
	LOG4CXX_DEBUG(logger,"unsigned int:" << sizeof(ui));

	FrameParser fp(regenerate);
	
	string test1="asdfasdfasdasdf\001abcdefghijklmnopq\r";
	char test2[] = { 0x01,0x08,0x02,0x01,0x04,0x03,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0xfe, 0xdd,0x0d };
	string str2(test2,17);
	string test3="abcdefghijklmnopq\r";
	string test4="\001abcdef";

	char validV1_1[] = { 0x1 ,0x35 ,0x2 ,0x80 ,0x7 ,0x00 ,0x21 ,0x2 ,0x10 ,0x00 ,0x00 ,0x48 ,0xc5 ,0xd };
	std::string strValidV1_1 = string(validV1_1,14);
	char validV1_2[] = { 0x1 ,0x28 ,0xb, 0x00 ,0x7 ,0x00 ,0x22 ,0x2 ,0x10 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0xd5 ,0xbb ,0xd};
	std::string strValidV1_2 = string(validV1_2,17);

	char validV1_3[] = { 0x1, 0x28, 0xb, 0, 0x17, 0, 0x22, 0x1, 0x10, 0xff, 0xff, 0, 0, 0, 0xd6, 0xab, 0xd };
	std::string strValidV1_3 = string(validV1_3,17);
	char test6[] = { 0x1, 0x28, 0xe, 0, 0x17, 0, 0x22, 0x1, 0x10, 0xff, 0xff, 0, 0, 0, 0xd6, 0xa8, 0xd };
	std::string str6 = string(test6,17);
	char test7[] = { 0x01, 0x07, 0xFF, 0x07, 0x02, 0x00, 0xC7, 0x04, 0x00, 0x06, 0x00, 0x00, 0x01, 0x00, 0x00, 0x0D };
	std::string str7 = string(test7,16);
	char test8[] = { 0x01, 0x07, 0x02, 0x00, 0xFF, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xEA, 0x0D };
	char data8[] = { 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

	/* LIVE V1 Data */
//	char v1_data_1[] = { 0x01, 0x28, 0x09, 0x00, 0x2a, 0x00, 0x22, 0x01, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0xd7, 0xc4, 0x0d };

	std::string str8 = string(test8,16);
	std::string datastr8 =  string(data8,7);

bool test_general=false;
Packet pkt;
if (test_general) {

	LOG4CXX_DEBUG(logger,"Test1: expects invalid packet" );
	assertInvalidParse(fp,test1,1,"Test1: expects invalid packet",1);
	LOG4CXX_DEBUG(logger,"Test2: VALID PACKET from 0x0203 to 0x0304 data 11,12,13,14,15,16,17,18 (hex) bad crc 0xdd" );
	assertValidParse(fp,str2,1,"Test",2);
	LOG4CXX_DEBUG(logger,"Test3: expects invalid packet" );
	assertValidParse(fp,test3,1,"Test",3);
	LOG4CXX_DEBUG(logger,"Test4: expects invalid packet (incomplete" );
//	assertValidParse(fp,test4,1);


	LOG4CXX_DEBUG(logger,"========================================================");
	LOG4CXX_DEBUG(logger,"Test5: expects fully valid packets V1 ( sample from net)");
	LOG4CXX_DEBUG(logger,"Hexdump 1a: " << Tools::hexDump(strValidV1_1));
	LOG4CXX_DEBUG(logger,"Parse #1");
	LOG4CXX_DEBUG(logger,"========================================================");
	assertValidParse(fp,strValidV1_1,1, "Test 5",5);

	LOG4CXX_DEBUG(logger,"Hexdump 2a: " << Tools::hexDump(validV1_2));
	LOG4CXX_DEBUG(logger,"Parse #2");
	LOG4CXX_DEBUG(logger,"========================================================");
	assertValidParse(fp,strValidV1_2,1, "Valid V1 #2",2);
	LOG4CXX_DEBUG(logger,"Hexdump 3a: " << Tools::hexDump(validV1_3));
	LOG4CXX_DEBUG(logger,"Hexdump 3b: " << Tools::hexDump(strValidV1_3));
	
	LOG4CXX_DEBUG(logger,"Parse #3");
	LOG4CXX_DEBUG(logger,"========================================================");
	assertValidParse(fp,strValidV1_3,1, "Valid V1 #3",3);

	LOG4CXX_DEBUG(logger,"========================================================");
	LOG4CXX_DEBUG(logger,"Test6: expects fully valid packet V1 ( sample from net)");
	LOG4CXX_DEBUG(logger,"Hexdump raw: " << hexDump(test6,17));
	assertValidParse(fp,str6,1,"Valid V1 #6",6);

	//LOG4CXX_DEBUG(logger,"Test6: Hexdump raw: " << hexDump(test6,17));
	LOG4CXX_DEBUG(logger,"========================================================");
	LOG4CXX_DEBUG(logger,"Test7: expects fully valid packet V2 ( sample from net)");
	LOG4CXX_DEBUG(logger,"Hexdump raw: " << hexDump(test7,16));
	assertValidParse(fp,str7,2,"Valid V2 #1",1);
	LOG4CXX_DEBUG(logger,"========================================================");
	LOG4CXX_DEBUG(logger,"Test8: expects fully valid packet V2 ( sample from net)");
	assertValidParse(fp,str8,2,"Net Sample #8 (valid)",8);

	Packet p(0x7ff,0x2, datastr8,0,0);
	p.updateCrc();
	cerr << p.toString() << endl;


	Packet pkt;
	LOG4CXX_DEBUG(logger,"Test8 Orig Dump  : " << hexDump(test8,16));
	LOG4CXX_DEBUG(logger,"Test8 Parsed Dump: " << p.hexDump());

	LOG4CXX_DEBUG(logger,"Hexdump: " << p.hexDump());
	LOG4CXX_DEBUG(logger,"toString: " << p.toString());
}

	char expectedPacket[] = { 0x01,0x28,0x01,0xF0, 0x00,0x00,0x20,0x01,0x00,0x00,0x01,0x00,0x02,0x00,0x00,0xc3,0x0d };
	char expectedPacket2[] = { 0x01,0x28,0x01,0xF0, 0x00,0x00,0x20,0x01,0x00,0x00,0x01,0x00,0x02,0x00,0x00,0xc3,0x0d }; 


	char bootData[8] = { 0x20,0x01,0x00,0x00,0x01,0x00,0x02,0x00 };
	std::string bootDataStr(bootData,8);

	Packet bootMcast = Packet::multicast(0,0xf001,bootDataStr);
	Packet bootMcast2 = Packet::multicast(1,0xf001,bootDataStr);
	LOG4CXX_DEBUG(logger,bootMcast.hexDump());
	LOG4CXX_DEBUG(logger,bootMcast2.hexDump());


// FILE BASED approach !
 vector<std::string> lines;

  string line;

  ifstream sampleFile( "parsertest-data.txt" );

 if (sampleFile.is_open())
  {
	int row = 0;
    while ( sampleFile.good() )
    {
		getline ( sampleFile,line);
		row++;
	
		boost::char_separator<char> sep(";");
		boost::char_separator<char> hexSep(" ");

		boost::tokenizer<boost::char_separator<char> > tokens(line, sep);

		if ( tokens.begin() == tokens.end()) {
			continue;
		}
		boost::tokenizer<boost::char_separator<char> >::iterator tok_iter = tokens.begin();

		std::string descr = *tok_iter;
		tok_iter++;
		if ( tok_iter == tokens.end()) {
			continue;
		}
		std::string valid = *tok_iter;
		tok_iter++;
		if ( tok_iter == tokens.end()) {
			continue;
		}
		std::string version = *tok_iter;
		tok_iter++;
		if ( tok_iter == tokens.end()) {
			continue;
		}
		std::string data = *tok_iter;

		int iVersion = atoi(version.c_str());

		boost::tokenizer<boost::char_separator<char> > hexTokens(data, hexSep);

		std::string rawData("");

		for ( boost::tokenizer<boost::char_separator<char> >::iterator hexIt = hexTokens.begin();hexIt != hexTokens.end(); ++hexIt) {
			int c; 
	
			if ( sscanf((*hexIt).c_str(),"%x",&c) == 1) {
				rawData+=(char) c;
			}
		}

		if ( valid == "V" ) {
			assertValidParse(fp,rawData,iVersion,descr,row);
		} else {
			assertInvalidParse(fp,rawData,iVersion,descr,row);
		}
		//cout << "Descr: <" << descr << "> Version <" << iVersion << "> Valid <" << valid <<"> Data: <" << Tools::hexDump(rawData) << ">" << endl;

    }
    sampleFile.close();
  }
	else {
		cerr << "cannot open sample data file " << endl;
	}
}
