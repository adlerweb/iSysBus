/*
 * Simple tool for the isysbus isbd protocol.
 * License: GPL
 * Author: Tobias Hain (grondhal (at) grondhal.de)
 */
#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>
#include <vector>
//#include "../../../isbd/trunk/src/frame_tools.h"
#include "checksum.hpp"
#include "isb_frame.hpp"
#include "isb_frame_switch.hpp"
#include "isb_frame_multicast_raw.hpp"

#include <boost/program_options.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>

using namespace std;
using boost::asio::ip::tcp;   


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
    cout << "resolving..." << host << "/" << port << endl;
    tcp::resolver::iterator endpoint_iter = resolver.resolve(query);
    const tcp::endpoint endpoint = *endpoint_iter;  

    cout << "starting async connect..." << endl;
    
    try {
    
      m_socket.async_connect(endpoint,
        boost::bind(&isbd_con::handle_connect, this, boost::asio::placeholders::error, ++endpoint_iter)
      );
    } catch (const std::exception &e) {
      cerr << "error in async connect: " << e.what() << endl;
      throw;
    }
  
  };

  void handle_connect(const boost::system::error_code& error, tcp::resolver::iterator endpoint_iterator) {
  
  
    if (!error)
    {
      cout << "connected. reading greeting..." << endl;
      m_socket.async_read_some(
          boost::asio::buffer(m_read_buf),
          boost::bind(&isbd_con::handle_read_greeting, this,
            boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
    }
    else if (endpoint_iterator != tcp::resolver::iterator())
    {
      cerr << "connection error" << error.message() << endl;
      m_socket.close();
      tcp::endpoint endpoint = *endpoint_iterator;
      m_socket.async_connect(endpoint,
          boost::bind(&isbd_con::handle_connect, this,
            boost::asio::placeholders::error, ++endpoint_iterator));
    } else {
      cerr << "connection error: " << error.message() << endl;
      exit(1);
    }
  }

  void handle_read_greeting(const boost::system::error_code& error, size_t bytes_transferred)
  {
    if (!error) 
    {
      m_rx_buf.append(reinterpret_cast<const char*>(&m_read_buf[0]), bytes_transferred);
      cout << "received greeting data, size: " << bytes_transferred << endl;
      //std::size_t p = m_read_buf.find('\n');
      read_buf_iterator iter = find(m_read_buf.begin(), m_read_buf.end(), '\n');
      //if (string::npos == p) {
      if (iter == m_read_buf.end())  {
        cout << "incomplete greeting, starting async read" << endl;
        m_socket.async_read_some(
          boost::asio::buffer(m_read_buf),
          boost::bind(&isbd_con::handle_read_greeting, this,
          boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));

      } else {
        cout << "greeting is complete, logging in" << endl;

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


	cout << "logging in with (" << m_username << "/" << m_passwd << ")" << endl;
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
  
    //cout << "monitor frame data" << endl;
    //if (TOF_MULTICAST==h->flags.tof) {
    //  cout << "******************* MULTICAST FRAME ***********" << endl;
    //}
    
    
    const unsigned char checksum = isb_frame_data[h->flags.dlc + 1]; // plus one reserved byte between data and checksum
    const unsigned char stopbyte = isb_frame_data[h->flags.dlc+sizeof(isb_frame_checksum)+1]; // plus one reserved byte between data and checksum
    cout << "flags: { dlc: " << (int)h->flags.dlc 
         << " tof: " << (int)h->flags.tof 
         << " rtr: " << (int)h->flags.rtr 
         << " reserved: " << (int)h->flags.reserved
         << " } dest: { ";

    switch (h->flags.tof) {
      case TOF_UNICAST:
        cout << h->dest.u.ud.addr << ":" << h->dest.u.ud.port;
      break;
      
      case TOF_MULTICAST:
        cout << h->dest.u.mulid.id;
      break;
      
      case TOF_BROADCAST:
        cout << h->dest.u.brid.id;
      break;
      
      default:
        cout << "{unsupported tof: " << h->flags.tof << "}";
      break;    
    };         
        
    cout << " } src: { "
         << h->source.addr << ":" << h->source.port
         << " } "
         << " checksum: 0x" << hex << setw(2*sizeof(isb_frame_checksum)) << setfill('0') << (static_cast<const unsigned int>(checksum)&0xff) << " <" << (char*)(checksum_fine ? "good" : "bad") << ">"
         << " stopbyte: 0x" << hex << setw(2) << setfill('0') << (static_cast<const unsigned int>(stopbyte)&0xff)
         << " data: ";
    for (int i=0; i<h->flags.dlc; ++i) {
      cout << "\\x" << hex << setw(2) << setfill('0') << ( static_cast<unsigned int>(isb_frame_data[i]) & 0xFF );

    }
    cout << endl; 
  }
 

  void handle_monitor_frame_data(const boost::system::error_code& error, size_t bytes_transferred)
  {
    if (!error) 
    {
    
      /*
      cout << "received frame: ";
      for (int i=0; i<bytes_transferred+sizeof(isb_frame_head); ++i) {
        cout << "\\x" << hex << setw(2) << setfill('0') << ( static_cast<unsigned int>(m_read_buf[i]) & 0xFF );
      }
      cout << endl;
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
    
      //cout << "monitor frame head" << endl;

      if ((sizeof(isb_frame_head)-1) != bytes_transferred) { // startbyte wurde schon gelesen
	throw std::runtime_error("received incomplete frame head");
      }

      const isb_frame_head * h = reinterpret_cast<isb_frame_head*>(&m_read_buf[0]);
      const int remaining_frame_bytes = h->flags.dlc + sizeof(isb_frame_checksum) + sizeof(isb_frame_stopbyte) + 1; // plus 1 reserved byte between data and checksum

      m_rx_buf.resize(sizeof(isb_frame_head) + remaining_frame_bytes);
      std::copy(m_read_buf.begin(), m_read_buf.end(), m_rx_buf.begin());
      
      //cout << "reading " << remaining_frame_bytes << " data bytes" << endl;

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
    cerr << s.str() << endl;
#endif
    
    
    boost::asio::write(m_socket, boost::asio::buffer(m_tx_buf));
  }
  
  void handle_monitor_frame_head_textloop(const boost::system::error_code& error, size_t bytes_transferred) {
       if (error) {
         m_socket.close();
         return;
       }
       
       cerr << "textloop" << endl;
       
       cout << m_read_buf[0];
       
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
         //cout << "received startbyte" << endl;
         m_read_buf.resize(sizeof(isb_frame_head));
         boost::asio::async_read(
	  m_socket,
          boost::asio::buffer(&m_read_buf[1], sizeof(isb_frame_head)-1),
          boost::bind(&isbd_con::handle_monitor_frame_head, this,
          boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
          
       } else {
         cout << "received line: " << hex << (int)m_read_buf[0];
         // text
         boost::asio::async_read(
	  m_socket,
          boost::asio::buffer(m_read_buf),
          boost::bind(&isbd_con::handle_monitor_frame_head_textloop, this,
          boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
         
         
      
       }
  
  
  }
  

  void monitor() {
  
        //cout << "monitoring bus..." << endl;

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

      cout << "calculating checksum for raw multicast frame with " << crc_buf.size() << " bytes:" << endl;
      for (int i=0; i<crc_buf.size(); ++i) {
            cout << "\\x" << hex << setw(2) << setfill('0') << ( static_cast<unsigned int>(crc_buf[i]) & 0xFF );
      }
      trailer.checks = calc_checks(&crc_buf[0], crc_buf.size());
    }
    
    m_tx_buf.append(reinterpret_cast<const char*>(&f), sizeof(f));
    m_tx_buf.append(&data[0], data.size());
    m_tx_buf.append(reinterpret_cast<const char*>(&trailer), sizeof(isb_multicast_raw_frame_v2_trailer));
    send_data();
  
  }
                                                                                                                
  void switch_off_v2(const unsigned short mulid, const unsigned short srcid) {

    cerr << "sending switch off packet v2" << endl;
    switch_frame_v2 f(mulid, srcid);

    // ausschalten
    f.d.cmd = cmd_write;
    f.d.value = 0x00;
    f.checks = calc_checks(reinterpret_cast<unsigned char*>(&f), sizeof(f));
    m_tx_buf.append(reinterpret_cast<const char*>(&f), sizeof(f));
    send_data();

  }


  void switch_on_v2(const unsigned short mulid, const unsigned short srcid) {

    cerr << "sending switch on packet v2" << endl;
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
  tcp::socket m_socket;
  std::vector<unsigned char> m_read_buf;
  std::string m_rx_buf;
  std::string m_tx_buf;
  typedef std::vector<unsigned char>::iterator read_buf_iterator;
  string m_username;
  string m_passwd;
  bool m_data_mode;
  bool m_monitor;

};


int main(int argc, char *argv[]) {

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
    ;
        

  boost::program_options::variables_map vm;
  boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), vm);
  boost::program_options::notify(vm);    
  
    // pruefen ob es eine moeglichkeit gibt, options als mandatory zu deklarieren!

  if (!vm.count("host")) {
    cerr << "host not specified" << endl;
    syntax();
  }

  if (!vm.count("port")) {
    cerr << "port not specified" << endl;
    syntax();
  }

  if (!vm.count("user")) {
    cerr << "username not specified" << endl;
    syntax();
  }

  if (!vm.count("pass")) {
    cerr << "password not specified" << endl;
    syntax();
  }

  if (!vm.count("monitor")) {

      if (!vm.count("mulid")) {
        cerr << "multicast id not specified" << endl;
        syntax();
      }

      if (!vm.count("srcid")) {
        cerr << "srcid not specified" << endl;
        syntax();
      }
      
      cout << "checking for switch or multicast-raw arguments" << endl;

      if ((!vm.count("switch")) && (!vm.count("multicast-raw"))) {
        cerr << "switch or mutlicast-raw not specified" << endl;
        syntax();
      }

  }
  
  const string host = vm["host"].as<string>();
  const unsigned short port = vm["port"].as<unsigned short>();
  const string username = vm["user"].as<string>();
  const string passwd = vm["pass"].as<string>();


  boost::asio::io_service io_service;
  cout << "connecting to " << host << ":" << port << endl;
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
          cerr << "numbytes is mandatory when sending raw multicast frames" << endl;
          syntax();     
        }
        const unsigned int numbytes = vm["numbytes"].as<unsigned int>();
        unsigned char top;
        unsigned char cmd;
        std::vector<char> data(numbytes-2);
        cout << "reading " << numbytes << " bytes (cmd, top and " << (numbytes - 2) <<" bytes payload) from stdin" << endl;
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
    cerr << "error: " << e.what() << endl; 
  }


#if 1
  //printf("sizeof switch_frame: %ld\n", sizeof(switch_frame));
  printf("sizeof isb_frame_head: %ld\n", sizeof(isb_frame_head));
  printf("sizeof isb_frame_head_unicast: %ld\n", sizeof(isb_frame_head_unicast));
  printf("sizeof isb_frame_head_multicast: %ld\n", sizeof(isb_frame_head_multicast));
  
  printf("sizeof isb_frame_flags: %ld\n", sizeof(isb_frame_flags));
  printf("sizeof isb_frame_addr_id: %ld\n", sizeof(isb_frame_addr_id));
  printf("sizeof isb_frame_unicast_addr: %ld\n", sizeof(isb_frame_unicast_addr));
  //printf("sizeof isb_frame_switch_data: %ld\n", sizeof(isb_frame_switch_data));
  printf("sizeof isb_frame_checksum: %ld\n", sizeof(isb_frame_checksum));
  printf("sizeof switch_frame_v2: %ld\n", sizeof(switch_frame_v2)); 
#endif
  
  

  return 0;
}

