/*
 * Simple tool for the isysbus isbd protocol.
 * License: GPL
 * Author: Tobias Hain (grondhal (at) grondhal.de)
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include "isb_frame.hpp"
#include "isb_frame_switch.hpp"
#include "isb_frame_multicast_raw.hpp"

#include <boost/program_options.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <log4cxx/logger.h>
#include "log4cxx/basicconfigurator.h"

/*#include <lua5.1/lua.hpp>
	FUTURE: LUA SCRIPTING
*/

using namespace std;
using boost::asio::ip::tcp;   
namespace po = boost::program_options;

log4cxx::LoggerPtr logger(log4cxx::Logger::getLogger("isbc"));

// d points to the complete frame including checksum (which is ignored) and stopbyte!
unsigned char calc_checks(const unsigned char *d, const unsigned int len);
bool check_checks(const unsigned char *d, const unsigned int len);

void syntax() {


  cerr << "required args:"
       << " --host <host>"
       << " --port <port>"
       << " --user <username>"
       << " --pass <password>"
       << " --monitor"
       << " [--mulid <multicast id>]"
       << " [--srcid <src id>]"
       << " [--switch <on/off>]"
       << " [--multicast-raw]"
       << " [--srcport <port>]"
       << " [ --numbytes <count>]"
       << endl;
 exit(1);
}


class isbd_con {
public:
  isbd_con(const string &host, const unsigned short port, const string &username, const string &passwd, boost::asio::io_service &io_service)
  : m_io_service(io_service), m_username(username), m_passwd(passwd), m_socket(io_service), m_read_buf(512), m_data_mode(false), m_monitor(false)
  {


    tcp::resolver resolver(m_io_service);
    char port_string[8];
    sprintf(port_string, "%d", port);
    tcp::resolver::query query(host, port_string);
    LOG4CXX_DEBUG(logger,"resolving..." << host << "/" << port );
    tcp::resolver::iterator endpoint_iter = resolver.resolve(query);
    const tcp::endpoint endpoint = *endpoint_iter;  

    LOG4CXX_DEBUG(logger,"starting async connect..." );
    
    try {
    
      m_socket.async_connect(endpoint,
        boost::bind(&isbd_con::handle_connect, this, boost::asio::placeholders::error, ++endpoint_iter)
      );
    } catch (const std::exception &e) {
      LOG4CXX_ERROR(logger,"error in async connect: " << e.what() );
      throw;
    }
  
  };

  void handle_connect(const boost::system::error_code& error, tcp::resolver::iterator endpoint_iterator) {
  
  
    if (!error)
    {
      LOG4CXX_DEBUG(logger,"connected. reading greeting..." );
      m_socket.async_read_some(
          boost::asio::buffer(m_read_buf),
          boost::bind(&isbd_con::handle_read_greeting, this,
            boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
    }
    else if (endpoint_iterator != tcp::resolver::iterator())
    {
      LOG4CXX_ERROR(logger,"connection error" << error.message() );
      m_socket.close();
      tcp::endpoint endpoint = *endpoint_iterator;
      m_socket.async_connect(endpoint,
          boost::bind(&isbd_con::handle_connect, this,
            boost::asio::placeholders::error, ++endpoint_iterator));
    } else {
      LOG4CXX_ERROR(logger,"connection error: " << error.message() );
      exit(1);
    }
  }

  void handle_read_greeting(const boost::system::error_code& error, size_t bytes_transferred)
  {
    if (!error) 
    {
      m_rx_buf.append(reinterpret_cast<const char*>(&m_read_buf[0]), bytes_transferred);
      LOG4CXX_DEBUG(logger,"received greeting data, size: " << bytes_transferred );
      //std::size_t p = m_read_buf.find('\n');
      read_buf_iterator iter = find(m_read_buf.begin(), m_read_buf.end(), '\n');
      //if (string::npos == p) {
      if (iter == m_read_buf.end())  {
        LOG4CXX_DEBUG(logger,"incomplete greeting, starting async read" );
        m_socket.async_read_some(
          boost::asio::buffer(m_read_buf),
          boost::bind(&isbd_con::handle_read_greeting, this,
          boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));

      } else {
        LOG4CXX_DEBUG(logger,"greeting is complete, logging in" );

        if (0 != m_rx_buf.find("+OK 200")) throw std::runtime_error("bad greeting");
        // greeting aus puffer entfernen
	m_rx_buf.erase(0, m_rx_buf.find('\n')+1);

	// set auth plain
        const string login_auth("AUTH plain\r\n");
	boost::asio::write(m_socket, boost::asio::buffer(login_auth));

        m_socket.async_read_some(
          boost::asio::buffer(m_read_buf),
          boost::bind(&isbd_con::handle_read_auth_resp, this,
          boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));        
      }
    }
    else
    {
      m_socket.close();
    }
  }

  void handle_read_auth_resp(const boost::system::error_code& error, size_t bytes_transferred)
  {
    if (!error) 
    {
      m_rx_buf.append(reinterpret_cast<const char*>(&m_read_buf[0]), bytes_transferred);
      //std::size_t p = m_read_buf.find('\n');
      //if (string::npos == p) {
      read_buf_iterator iter = find(m_read_buf.begin(), m_read_buf.end(), '\n');
      if (iter == m_read_buf.end())  {
      
        m_socket.async_read_some(
          boost::asio::buffer(m_read_buf),
          boost::bind(&isbd_con::handle_read_auth_resp, this,
          boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));

      } else {
        if (0 != m_rx_buf.find("+OK 202")) throw std::runtime_error("bad auth response");
        // antwort aus puffer entfernen
	m_rx_buf.erase(0, m_rx_buf.find('\n')+1);


	LOG4CXX_DEBUG(logger,"logging in with (" << m_username << "/" << m_passwd << ")" );
	// send username
        const string login_user("USER " + m_username + "\r\n");
	boost::asio::write(m_socket, boost::asio::buffer(login_user));

        m_socket.async_read_some(
          boost::asio::buffer(m_read_buf),
          boost::bind(&isbd_con::handle_read_user_resp, this,
          boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));        
      }     
    }
    else
    {
      m_socket.close();
    }
  }
                                                                                                                
  void handle_read_user_resp(const boost::system::error_code& error, size_t bytes_transferred)
  {
    if (!error) 
    {
      m_rx_buf.append(reinterpret_cast<const char*>(&m_read_buf[0]), bytes_transferred);
      //std::size_t p = m_read_buf.find('\n');
      //if (string::npos == p) {
      read_buf_iterator iter = find(m_read_buf.begin(), m_read_buf.end(), '\n');
      if (iter == m_read_buf.end())  {

        m_socket.async_read_some(
          boost::asio::buffer(m_read_buf),
          boost::bind(&isbd_con::handle_read_user_resp, this,
          boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));

      } else {
        if (0 != m_rx_buf.find("+OK 311")) throw std::runtime_error("bad user response");
        // antwort aus puffer entfernen
	m_rx_buf.erase(0, m_rx_buf.find('\n')+1);

	// send password
        const string login_pass("PASS " + m_passwd + "\r\n");
	boost::asio::write(m_socket, boost::asio::buffer(login_pass));

        m_socket.async_read_some(
          boost::asio::buffer(m_read_buf),
          boost::bind(&isbd_con::handle_read_passwd_resp, this,
          boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));        
      }     
    }
    else
    {
      m_socket.close();
    }
  }


  void handle_read_passwd_resp(const boost::system::error_code& error, size_t bytes_transferred)
  {
    if (!error) 
    {
      m_rx_buf.append(reinterpret_cast<const char*>(&m_read_buf[0]), bytes_transferred);
      //std::size_t p = m_read_buf.find('\n');
      //if (string::npos == p) {
      read_buf_iterator iter = find(m_read_buf.begin(), m_read_buf.end(), '\n');
      if (iter == m_read_buf.end())  {

        m_socket.async_read_some(
          boost::asio::buffer(m_read_buf),
          boost::bind(&isbd_con::handle_read_passwd_resp, this,
          boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));

      } else {
        if (0 != m_rx_buf.find("+OK 230")) throw std::runtime_error("login failed. check username/password");
        // antwort aus puffer entfernen
	m_rx_buf.erase(0, m_rx_buf.find('\n')+1);

	// set data mode
        const string data_mode("DATA\r\n");
	boost::asio::write(m_socket, boost::asio::buffer(data_mode));

        m_socket.async_read_some(
          boost::asio::buffer(m_read_buf),
          boost::bind(&isbd_con::handle_read_data_resp, this,
          boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));        
      }     
    }
    else
    {
      m_socket.close();
    }
  }

  void handle_read_data_resp(const boost::system::error_code& error, size_t bytes_transferred)
  {
    if (!error) 
    {
      m_rx_buf.append(reinterpret_cast<const char*>(&m_read_buf[0]), bytes_transferred);
      //std::size_t p = m_read_buf.find('\n');
      //if (string::npos == p) {
      read_buf_iterator iter = find(m_read_buf.begin(), m_read_buf.end(), '\n');
      if (iter == m_read_buf.end())  {      

        m_socket.async_read_some(
          boost::asio::buffer(m_read_buf),
          boost::bind(&isbd_con::handle_read_data_resp, this,
          boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));

      } else {
        // antwort aus puffer entfernen
	m_rx_buf.erase(0, m_rx_buf.find('\n')+1);
        m_data_mode = true;
        do_work();
      }

    }
    else
    {
      m_socket.close();
    }
  }
  
  void do_work() {
  
    send_data();
    if (m_monitor) monitor();
  
  }
  
  void print_frame(const isb_frame_head * h, const unsigned char *isb_frame_data, const bool checksum_fine) {
  
    //LOG4CXX_DEBUG(logger,"monitor frame data" );
    //if (TOF_MULTICAST==h->flags.tof) {
    //  LOG4CXX_DEBUG(logger,"******************* MULTICAST FRAME ***********" );
    //}
    
    
    const unsigned char checksum = isb_frame_data[h->flags.dlc + 1]; // plus one reserved byte between data and checksum
    const unsigned char stopbyte = isb_frame_data[h->flags.dlc+sizeof(isb_frame_checksum)+1]; // plus one reserved byte between data and checksum
    LOG4CXX_DEBUG(logger,"flags: { dlc: " << (int)h->flags.dlc 
         << " tof: " << (int)h->flags.tof 
         << " rtr: " << (int)h->flags.rtr 
         << " reserved: " << (int)h->flags.reserved
         << " } dest: { ");

    switch (h->flags.tof) {
      case TOF_UNICAST:
        LOG4CXX_DEBUG(logger,h->dest.u.ud.addr << ":" << h->dest.u.ud.port);
      break;
      
      case TOF_MULTICAST:
        LOG4CXX_DEBUG(logger,h->dest.u.mulid.id);
      break;
      
      case TOF_BROADCAST:
        LOG4CXX_DEBUG(logger,h->dest.u.brid.id);
      break;
      
      default:
        LOG4CXX_DEBUG(logger,"{unsupported tof: " << h->flags.tof << "}");
      break;    
    };         
        
    LOG4CXX_DEBUG(logger," } src: { "
         << h->source.addr << ":" << h->source.port
         << " } "
         << " checksum: 0x" << hex << setw(2*sizeof(isb_frame_checksum)) << setfill('0') << (static_cast<const unsigned int>(checksum)&0xff) << " <" << (char*)(checksum_fine ? "good" : "bad") << ">"
         << " stopbyte: 0x" << hex << setw(2) << setfill('0') << (static_cast<const unsigned int>(stopbyte)&0xff)
         << " data: ");
    for (int i=0; i<h->flags.dlc; ++i) {
      LOG4CXX_DEBUG(logger,"\\x" << hex << setw(2) << setfill('0') << ( static_cast<unsigned int>(isb_frame_data[i]) & 0xFF ));

    }
  }
 

  void handle_monitor_frame_data(const boost::system::error_code& error, size_t bytes_transferred)
  {
    if (!error) 
    {
    
      /*
      LOG4CXX_DEBUG(logger,"received frame: ";
      for (int i=0; i<bytes_transferred+sizeof(isb_frame_head); ++i) {
        LOG4CXX_DEBUG(logger,"\\x" << hex << setw(2) << setfill('0') << ( static_cast<unsigned int>(m_read_buf[i]) & 0xFF );
      }
      LOG4CXX_DEBUG(logger,endl;
      */
                    
    
      const isb_frame_head * h = reinterpret_cast<isb_frame_head*>(&m_read_buf[0]);
    
      if (bytes_transferred < h->flags.dlc + sizeof(isb_frame_checksum) + sizeof(isb_frame_stopbyte)) {
        
        throw std::runtime_error("frame size did not match");
      }
      

      print_frame(h, &m_read_buf[sizeof(isb_frame_head)], check_checks(&m_read_buf[0], bytes_transferred+sizeof(isb_frame_head)));
    

      monitor();

    }
    else
    {
      m_socket.close();
    }
  }

  void handle_monitor_frame_head(const boost::system::error_code& error, size_t bytes_transferred)
  {
    if (!error) 
    {
    
      //LOG4CXX_DEBUG(logger,"monitor frame head" );

      if ((sizeof(isb_frame_head)-1) != bytes_transferred) { // startbyte wurde schon gelesen
	throw std::runtime_error("received incomplete frame head");
      }

      const isb_frame_head * h = reinterpret_cast<isb_frame_head*>(&m_read_buf[0]);
      const int remaining_frame_bytes = h->flags.dlc + sizeof(isb_frame_checksum) + sizeof(isb_frame_stopbyte) + 1; // plus 1 reserved byte between data and checksum

      m_rx_buf.resize(sizeof(isb_frame_head) + remaining_frame_bytes);
      std::copy(m_read_buf.begin(), m_read_buf.end(), m_rx_buf.begin());
      
      //LOG4CXX_DEBUG(logger,"reading " << remaining_frame_bytes << " data bytes" );

      boost::asio::async_read(
	  m_socket,
          boost::asio::buffer(&m_read_buf[sizeof(isb_frame_head)], remaining_frame_bytes),
          boost::bind(&isbd_con::handle_monitor_frame_data, this,
          boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
    }
    else
    {
      m_socket.close();
    }
  }
 
  void send_data() {
    if (!m_data_mode) return;

#if 0    
    stringstream s;
    s << "(" << m_tx_buf.size() << ")";
    for (int i=0; i<m_tx_buf.size(); ++i) {
      s << "\\x" << hex << setw(2) << setfill('0') << 
      ((int)m_tx_buf[i] & 0xff);
    }
    LOG4CXX_ERROR(logger,s.str() );
#endif
    
    
    boost::asio::write(m_socket, boost::asio::buffer(m_tx_buf));
  }
  
  void handle_monitor_frame_head_textloop(const boost::system::error_code& error, size_t bytes_transferred) {
       if (error) {
         m_socket.close();
         return;
       }
       
       LOG4CXX_ERROR(logger,"textloop"  << m_read_buf[0]);
       
       if ('\n' == m_read_buf[0]) {       
         monitor();        
       } else {      
        
        // text
        boost::asio::async_read(
	  m_socket,
          boost::asio::buffer(m_read_buf),
          boost::bind(&isbd_con::handle_monitor_frame_head_textloop, this,
          boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
       }
       
       
       
  }

       
  void handle_monitor_frame_head_startbyte(const boost::system::error_code& error, size_t bytes_transferred) {
       if (error) {
         m_socket.close();
         return;
       }
  
       if (0x01 == m_read_buf[0]) {
         //LOG4CXX_DEBUG(logger,"received startbyte" );
         m_read_buf.resize(sizeof(isb_frame_head));
         boost::asio::async_read(
	  m_socket,
          boost::asio::buffer(&m_read_buf[1], sizeof(isb_frame_head)-1),
          boost::bind(&isbd_con::handle_monitor_frame_head, this,
          boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
          
       } else {
         LOG4CXX_DEBUG(logger,"received line: " << hex << (int)m_read_buf[0]);
         // text
         boost::asio::async_read(
	  m_socket,
          boost::asio::buffer(m_read_buf),
          boost::bind(&isbd_con::handle_monitor_frame_head_textloop, this,
          boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
         
         
      
       }
  
  
  }
  

  void monitor() {
  
        //LOG4CXX_DEBUG(logger,"monitoring bus..." );

 	m_read_buf.resize(1);

	boost::asio::async_read(
	  m_socket,
          boost::asio::buffer(&m_read_buf[0], 1),
          boost::bind(&isbd_con::handle_monitor_frame_head_startbyte, this,
          boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));

  };  
  
  void do_monitor() {
  
    m_monitor = true;
  };

  void send_multicast_raw(const unsigned short mulid, const unsigned short srcid, const unsigned char cmd, const unsigned char top, const std::vector<char> &data) {
    
    isb_multicast_raw_frame_v2 f(mulid, srcid, cmd, reinterpret_cast<const isb_frame_top_vals&>(top), data.size());
    isb_multicast_raw_frame_v2_trailer trailer;

    { 
      // ugly!
      std::vector<unsigned char> crc_buf(data.size() + sizeof(isb_multicast_raw_frame_v2) + sizeof(isb_multicast_raw_frame_v2_trailer));   
      memcpy(&crc_buf[0], &f, sizeof(isb_multicast_raw_frame_v2));
      memcpy(&crc_buf[sizeof(isb_multicast_raw_frame_v2)], &data[0], data.size());

      LOG4CXX_DEBUG(logger,"calculating checksum for raw multicast frame with " << crc_buf.size() << " bytes:" );
      for (int i=0; i<crc_buf.size(); ++i) {
            LOG4CXX_DEBUG(logger,"\\x" << hex << setw(2) << setfill('0') << ( static_cast<unsigned int>(crc_buf[i]) & 0xFF ));
      }
      trailer.checks = calc_checks(&crc_buf[0], crc_buf.size());
    }
    
    m_tx_buf.append(reinterpret_cast<const char*>(&f), sizeof(f));
    m_tx_buf.append(&data[0], data.size());
    m_tx_buf.append(reinterpret_cast<const char*>(&trailer), sizeof(isb_multicast_raw_frame_v2_trailer));
    send_data();
  
  }
                                                                                                                
  void switch_off_v2(const unsigned short mulid, const unsigned short srcid) {

    LOG4CXX_ERROR(logger,"sending switch off packet v2" );
    switch_frame_v2 f(mulid, srcid);

    // ausschalten
    f.d.cmd = cmd_write;
    f.d.value = 0x00;
    f.checks = calc_checks(reinterpret_cast<unsigned char*>(&f), sizeof(f));
    m_tx_buf.append(reinterpret_cast<const char*>(&f), sizeof(f));
    send_data();

  }


  void switch_on_v2(const unsigned short mulid, const unsigned short srcid) {

    LOG4CXX_ERROR(logger,"sending switch on packet v2" );
    switch_frame_v2 f(mulid, srcid);

    // einschalten
    f.d.cmd = cmd_write;
    f.d.value = 0x01;
    f.checks = calc_checks(reinterpret_cast<unsigned char*>(&f), sizeof(f));
    m_tx_buf.append(reinterpret_cast<const char*>(&f), sizeof(f));
    send_data();
  }


  boost::asio::io_service &m_io_service;
  tcp::resolver::iterator endpoint_iter;
  string m_username;
  string m_passwd;
  tcp::socket m_socket;
  std::vector<unsigned char> m_read_buf;
  std::string m_rx_buf;
  std::string m_tx_buf;
  typedef std::vector<unsigned char>::iterator read_buf_iterator;
  bool m_data_mode;
  bool m_monitor;

};


int main(int argc, char *argv[]) {
	log4cxx::BasicConfigurator::configure();
  // Declare the supported options.
  boost::program_options::options_description desc("Allowed options");
  desc.add_options()
    ("host", boost::program_options::value<string>(), "set host")
    ("port", boost::program_options::value<unsigned short>(), "set port")
    ("user", boost::program_options::value<string>(), "set username")
    ("pass", boost::program_options::value<string>(), "set password")
    ("monitor", "monitor bus and output received frames")
    ("mulid",  boost::program_options::value<unsigned short>(),  "set multicast id")
    ("srcid",  boost::program_options::value<unsigned short>(),  "set source id")
    ("switch", boost::program_options::value<bool>(), "switch on/off")
    ("multicast-raw", "send raw multicast frame (reading cmd, top, tov and 5 raw bytes from stdin)")
    ("srcport", boost::program_options::value<unsigned short>(),  "set source port")
    ("numbytes", boost::program_options::value<unsigned int>(),  "number of bytes")
		("configfile,c", po::value<string>(), "Path to config-file")
    ;
        
  boost::program_options::variables_map vm;
  boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), vm);
  boost::program_options::notify(vm);    

	// read config file 
	std::string cfgfile;

	if ( vm.count("configfile")) {
		cfgfile =  vm["configfile"].as<string>();
	}

	if (cfgfile.length() == 0) {
		// No name for the config-file was provided by the user, so try to find it 
		#ifdef _WIN32
			cfgfile = string("isbc.conf");
		#else
			cfgfile = string("/opt/isysbus/isbc.conf");
		#endif
	}

	std::ifstream ifs(cfgfile.c_str());
	po::store(parse_config_file(ifs, desc), vm);
	po::notify(vm);

  
    // pruefen ob es eine moeglichkeit gibt, options als mandatory zu deklarieren!

  if (!vm.count("host")) {
    LOG4CXX_ERROR(logger,"host not specified" );
    syntax();
  }

  if (!vm.count("port")) {
    LOG4CXX_ERROR(logger,"port not specified" );
    syntax();
  }

  if (!vm.count("user")) {
    LOG4CXX_ERROR(logger,"username not specified" );
    syntax();
  }

  if (!vm.count("pass")) {
    LOG4CXX_ERROR(logger,"password not specified" );
    syntax();
  }

  if (!vm.count("monitor")) {

      if (!vm.count("mulid")) {
        LOG4CXX_ERROR(logger,"multicast id not specified" );
        syntax();
      }

      if (!vm.count("srcid")) {
        LOG4CXX_ERROR(logger,"srcid not specified" );
        syntax();
      }
      
      LOG4CXX_DEBUG(logger,"checking for switch or multicast-raw arguments" );

      if ((!vm.count("switch")) && (!vm.count("multicast-raw"))) {
        LOG4CXX_ERROR(logger,"switch or mutlicast-raw not specified" );
        syntax();
      }

  }
  
  const string host = vm["host"].as<string>();
  const unsigned short port = vm["port"].as<unsigned short>();
  const string username = vm["user"].as<string>();
  const string passwd = vm["pass"].as<string>();


  boost::asio::io_service io_service;
  LOG4CXX_DEBUG(logger,"connecting to " << host << ":" << port );
  isbd_con con(host, port, username, passwd, io_service);                                          


  if (vm.count("monitor")) {
    
     con.do_monitor();
	
  } else {

      const unsigned short mulid = vm["mulid"].as<unsigned short>();
      const unsigned short srcid = vm["srcid"].as<unsigned short>();
      bool swtch;
      if (vm.count("switch")) {
        swtch = vm["switch"].as<bool>();
      }
          
      if (vm.count("multicast-raw")) {
        if (!vm.count("numbytes")) {
          LOG4CXX_ERROR(logger,"numbytes is mandatory when sending raw multicast frames" );
          syntax();     
        }
        const unsigned int numbytes = vm["numbytes"].as<unsigned int>();
        unsigned char top;
        unsigned char cmd;
        std::vector<char> data(numbytes-2);
        LOG4CXX_DEBUG(logger,"reading " << numbytes << " bytes (cmd, top and " << (numbytes - 2) <<" bytes payload) from stdin" );
        cin.read(reinterpret_cast<char*>(&top), 1);
        cin.read(reinterpret_cast<char*>(&cmd), 1);
        cin.read(&data[0], data.size());
        con.send_multicast_raw(mulid, srcid, cmd, top, data);
      } else {
        if (swtch) {
          con.switch_on_v2(mulid, srcid);
        } else {
          con.switch_off_v2(mulid, srcid);
        }
      }

  }


  try {
    io_service.run();
  } catch (const std::exception &e) {
    LOG4CXX_ERROR(logger,"error: " << e.what() ); 
  }

  //LOG4CXX_DEBUG(logger,"sizeof switch_frame: " << sizeof(switch_frame));
  LOG4CXX_DEBUG(logger,"sizeof isb_frame_head: " << sizeof(isb_frame_head));
  LOG4CXX_DEBUG(logger,"sizeof isb_frame_head_unicast: " << sizeof(isb_frame_head_unicast));
  LOG4CXX_DEBUG(logger,"sizeof isb_frame_head_multicast: " << sizeof(isb_frame_head_multicast));
  
  LOG4CXX_DEBUG(logger,"sizeof isb_frame_flags: " << sizeof(isb_frame_flags));
  LOG4CXX_DEBUG(logger,"sizeof isb_frame_addr_id: " << sizeof(isb_frame_addr_id));
  LOG4CXX_DEBUG(logger,"sizeof isb_frame_unicast_addr: " << sizeof(isb_frame_unicast_addr));
  //LOG4CXX_DEBUG(logger,"sizeof isb_frame_switch_data: " << sizeof(isb_frame_switch_data));
  LOG4CXX_DEBUG(logger,"sizeof isb_frame_checksum: " << sizeof(isb_frame_checksum));
  LOG4CXX_DEBUG(logger,"sizeof switch_frame_v2: " << sizeof(switch_frame_v2)); 
  
  return 0;
}


// d points to the complete frame including checksum (which is ignored) and stopbyte
unsigned char calc_checks(const unsigned char *d, const unsigned int len) {
 unsigned int sum=0;
 for (unsigned int i=0; i<(len - 3); ++i) { // all bytes except startbyte, checksum and stopbyte
  sum += d[i+1];
 }
 return (((sum & 0xff) ^ 0xff) + 1);
};

bool check_checks(const unsigned char *d, const unsigned int len) {
  unsigned int sum=0;
  for (unsigned int i=0; i<(len - 2); ++i) {
   sum += d[i+1];
  }

  return 0 == (sum & 0xff);
}

