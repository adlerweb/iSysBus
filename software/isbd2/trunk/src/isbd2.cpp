/*
 * Isysbus gateway.
 * License: GPL
 * Author: Tobias Hain (grondhal (at) grondhal.de)
 */
#include <boost/program_options.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/signal.hpp>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <iomanip>
//#include "../../../isbd/trunk/src/frame_tools.h"
#include "../../../isbc/trunk/src/checksum.hpp"

using boost::asio::ip::tcp;
using namespace std;

class connection;

string to_hex(const char *d, const unsigned int size) {
  stringstream s;
  for (int i=0; i<size; ++i) {
    s << "\\x" << hex << setw(2) << setfill('0') << ((int)d[i] & 0xff);
  }
  return s.str();
}

string to_hex(vector<char> d) {
  return to_hex(&d[0], d.size());;
}


/*
 * returns size of frame if frame is complete
 */
unsigned int frame_size(const char *isb_frame, const unsigned int max_size) {

  const static unsigned int MIN_ISB_MSG_SIZE = 6+3; //sizeof(isb_frame_head) + 3; // 6 byte head, 1 byte reserved, 1 byte checksumme, 1 stop-byte
 
  if (MIN_ISB_MSG_SIZE <= max_size) {
  
    const unsigned int dlc = isb_frame[1] & 0x0F;
    const unsigned int framesize = dlc + MIN_ISB_MSG_SIZE;
        
    if (max_size >= framesize) {
      //LOG4CXX_DEBUG(logger,"msg dlc: %d, framesize: %d\n", dlc, framesize);
      return framesize;
    }
  }
                         
  return 0;                           
};


class dispatcher_client {
public:

};

class frame_dispatcher {
public:

    // currently implemented as singleton
    // think about making new_frame_sig static

  boost::shared_ptr<frame_dispatcher> static get() {
    static boost::shared_ptr<frame_dispatcher> fd(new frame_dispatcher);
    return fd; 
  };

  boost::signal< void ( const vector<char>& , const dispatcher_client *src) > new_frame_sig;
  
};



template<typename AsyncWriteStream>
class frame_sender : public dispatcher_client, public boost::enable_shared_from_this<frame_sender<AsyncWriteStream> > {
public:

  boost::shared_ptr< frame_sender<AsyncWriteStream> > static create(AsyncWriteStream &stream) {
    return boost::shared_ptr<frame_sender<AsyncWriteStream> >(new frame_sender<AsyncWriteStream>(stream));
  };

  boost::signal< void () > io_error;

  void add_to_send_queue(const vector<char> &data, const dispatcher_client *src) {
   if (src == this) {
     //cout << "frame_sender::add_to_send_queue ignoring my own frame <" << this << ">" << endl;
     return; // me, myself or i dispatched this frame
   }
   //if ('\d' != data[data.size()-1]) {
   //  cerr << "frame_sender::add_to_send_queue: discarding broken frame (" << data.size() << "bytes, frame not terminated with stop byte" << endl;
   //  return;
   //}
   if (!check_checks((unsigned char*)&data[0], data.size())) {
     cerr << "frame_sender::add_to_send_queue: discarding broken frame (" << data.size() << "bytes, wrong checksum" << endl;
     return;
   }
   if (m_send_q_max > m_send_q.size()) {    
     m_send_q.push(data);
     if (1 == m_send_q.size()) {
       send_data();
     } else {
      cout << "frame_sender::add_to_send_queue - send_q ist has not exactly one elemnt(" << m_send_q.size() << ") - assuming send in progress" << endl;
    }
   } else {
     cerr << "dropping frame - " << m_send_q.size() << " frames in queue - send queue is full (" << this << ")" << endl;
   }
  };
  
private:
  

 
  frame_sender(AsyncWriteStream &stream) : m_stream(stream) {};
 
  void send_data() {
    
    // if there is only 1 element in the q, then there is no send in progress  
    if (0 < m_send_q.size()) { 
      //cout << "sending frame with " << m_send_q.front().size() << " bytes <" << this << ">" << endl;
      boost::asio::async_write(m_stream,
        boost::asio::buffer(&m_send_q.front()[0], m_send_q.front().size()),
        boost::bind( &frame_sender::handle_send_data, this, boost::asio::placeholders::error)
      );        
    } 
  };
  
  void handle_send_data(const boost::system::error_code& error)
  {
    m_send_q.pop();
    if (error) {
      cerr << "error sending data: " << error.message() << "<" << this << ">" << endl;
      io_error();
    } else {
      cout << "frame sent <" << this << ">" << endl;
      send_data();
    }
    
  };
  
  static const unsigned int m_send_q_max = 23;
  queue< vector<char> > m_send_q;
  
  AsyncWriteStream & m_stream;
};

class serial : public boost::enable_shared_from_this<serial> {
public:
  boost::shared_ptr<serial> static create(boost::asio::io_service& io_service, const string device, const unsigned int baudrate)
  {
    return boost::shared_ptr<serial>(new serial(io_service, device, baudrate));
  };
  
  void start() { 
    
    m_ser.open(m_device);
   
    // 8N1, no flow control
    
    const static boost::asio::serial_port_base::flow_control flow(boost::asio::serial_port_base::flow_control::none);
    m_ser.set_option(flow);
    
    const static boost::asio::serial_port_base::baud_rate baud(m_baudrate);
    m_ser.set_option(baud);
    
    const static boost::asio::serial_port_base::character_size databits( 8 );
    m_ser.set_option(databits);
    
    const static boost::asio::serial_port_base::parity parity(boost::asio::serial_port_base::parity::none);
    m_ser.set_option(parity);
    
    const static boost::asio::serial_port_base::stop_bits stopbits(boost::asio::serial_port_base::stop_bits::one);
    m_ser.set_option(stopbits);
    
    m_disp_c = frame_dispatcher::get()->new_frame_sig.connect(
                       boost::bind(&frame_sender<boost::asio::serial_port>::add_to_send_queue, m_fs, _1, _2)
                     );
                     
    read_data();
    
  };
  
protected:
  serial(boost::asio::io_service& io_service, const string &device, const unsigned int baudrate)
  : m_ser(io_service), m_device(device), m_baudrate(baudrate), m_rx_buf(m_rx_buf_size), m_rx_buf_used(0)
  {
  	
    //m_fs(frame_sender<boost::asio::serial_port>::create(m_ser));
    m_fs = frame_sender<boost::asio::serial_port>::create(m_ser);
    cout << "serial ctor <" << this << "> m_fs<" << m_fs.get() << ">" << endl;
    m_fs->io_error.connect(boost::bind(&serial::io_err, this, string("serial: frame sender error")));
  };


  // frame reading is the same for serial and connection
  // this should be put in one class
  void read_data() {
    if (m_rx_buf_size > m_rx_buf_used) { 
      m_ser.async_read_some(boost::asio::buffer((&m_rx_buf[0])+m_rx_buf_used, m_rx_buf_size - m_rx_buf_used),
        boost::bind(&serial::handle_read_data, shared_from_this(),
        boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred));
    } else {
      io_err("received frame to long");
    }
  };

  void remove_bytes_from_buf(const unsigned int size) {
    if (size < m_rx_buf_used) {
      //cout << "removing " << size << " of " << m_rx_buf_used << " octets from rx buffer " << endl;
      // circular_buffer ?
      copy(m_rx_buf.begin()+size, m_rx_buf.begin()+(m_rx_buf_used-1), m_rx_buf.begin());
      m_rx_buf_used -= size;
    } else {
      //cout << "rx buf is now empty (" << size << ")" << endl;
      m_rx_buf_used = 0;
    }
  
  };

  
  void io_err(const string err) {
    cout << "serial::io_err" << err << endl;
    m_ser.close();
  };
  
  
  void close_stream() {
    if (m_disp_c.connected()) {
      m_disp_c.disconnect();
    }
    m_ser.close();
  
  };

  void handle_read_data(const boost::system::error_code& error, size_t bytes_transferred)
  { 
  
    //cout << "serial::handle_read_data" << endl;

    if (!error)
    {
    
      if (0 == bytes_transferred) {
       close_stream();
       return;
      }
      
      m_rx_buf_used += bytes_transferred;
      //cout << "serial::handle_read_data read " << bytes_transferred << " bytes: ***" << string(&m_rx_buf[0], bytes_transferred) << "***" << endl;
      
      do {
        const unsigned int f_size = frame_size(&m_rx_buf[0], m_rx_buf_used);       
        if (0 == f_size) {
          break;
        }     
        
        vector<char> frame(f_size);
        copy( m_rx_buf.begin(), m_rx_buf.begin() + (f_size), frame.begin());       

#if 1
        // frame debug
        stringstream s;
        s << "(" << frame.size() << ")";
        for (int i=0; i<frame.size(); ++i) {
          s << "\\x" << hex << setw(2) << setfill('0') <<
          ((int)frame[i] & 0xff);
        }
        cerr << s.str() << endl;
#endif
                                        
        
        if (check_checks((unsigned char*)&frame[0], frame.size())) {
                  
          //cout << "received frame with " << f_size << "bytes (" << this << ")" << endl;

          // todo: optimize frame handling (copying etc)
          //cout << "dispatching frame (" << this << ")" << endl;
          frame_dispatcher::get()->new_frame_sig(frame, m_fs.get());
          
        } else {
          cerr << "serial::handle_read_data: discarding broken frame (" << f_size << " bytes, wrong checksum) " << to_hex(frame) << endl;
        }
        
        remove_bytes_from_buf(f_size);
      } while (1);
      
      read_data();
      
    } else {
      io_err(error.message());
    }

  };


private:
  boost::asio::serial_port m_ser;
  boost::shared_ptr<frame_sender< boost::asio::serial_port > > m_fs;
  boost::signals::connection m_disp_c;
  
  const string m_device;
  const unsigned int m_baudrate;
  
  static const unsigned int m_rx_buf_size = 8192;
  unsigned int m_rx_buf_used;
  std::vector<char> m_rx_buf;
};


class connection : public boost::enable_shared_from_this<connection>
{
public:

  boost::shared_ptr<connection> static create(boost::asio::io_service& io_service, const std::string &user, const std::string &pass) { 
    return boost::shared_ptr<connection>(new connection(io_service, user, pass));
  };
  
  tcp::socket& socket()
  {
    return m_socket;
  }
  


  void start()
  {
    cout << "new connection - starting auth sequence" << endl;
    static const string welcome_msg("+OK 200 Welcome\r\n");
    send_line(welcome_msg);
    read_line();    
  };
  
  ~connection() {
    cout << "connection dtor (" << this << ")" << endl;
  };

protected:

  connection(boost::asio::io_service& io_service, const std::string &user, const std::string &pass)
    : m_socket(io_service), m_rx_buf(m_rx_buf_size), m_rx_buf_used(0), m_state(S_READ_AUTH_T), m_auth_type(A_PLAIN),
      m_user(user), m_pass(pass)
  {
    cout << "connection ctor (" << this << ")" << endl;
  }

  void send_line(const std::string &s) {
    boost::asio::async_write(m_socket,
        boost::asio::buffer(s, s.size()),
        boost::bind(&connection::handle_send_line, shared_from_this(),
        boost::asio::placeholders::error));
  };
  
  void handle_send_line(const boost::system::error_code& error)
  {
    if (error) {
      cerr << "error sending line: " << error.message() << "(" << this << ")" << endl;
      m_socket.close();
    }
    
  };
  
  
  void proto_err() {
    send_line("+ERR 400 PROTOCOL_ERROR - bye bye\r\n");
    m_socket.close();
  };
  
  
  void close_sock() {
    if (m_disp_c.connected()) {
      m_disp_c.disconnect();
    }
    m_socket.close();
  
  };
  
  void read_line() {
  
    if (m_rx_buf_size > m_rx_buf_used) { 
      m_socket.async_read_some(boost::asio::buffer((&m_rx_buf[0])+m_rx_buf_used, m_rx_buf_size - m_rx_buf_used),
        boost::bind(&connection::handle_read_line, shared_from_this(),
        boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred));
    } else {
      cerr << "received line to long" << endl;
    }
  };
    
  void handle_read_line(const boost::system::error_code& error,
      size_t bytes_transferred)
  { 
    if (!error)
    {
      m_rx_buf_used += bytes_transferred;
      //cout << "read " << bytes_transferred << " bytes: ***" << string(&m_rx_buf[0], bytes_transferred) << "***" << endl;
    
      int lf_pos;
      do {
        lf_pos = -1;
        for (unsigned int i=0; i<m_rx_buf_used; ++i) {
            if ('\n' == m_rx_buf[i]) {
              lf_pos = static_cast<int>(i);
              m_rx_buf[i] = '\0'; // zero terminated string
              break;
            }
        }
        
        if (-1 == lf_pos) {
          // incomplete line
          if (m_rx_buf_size > m_rx_buf_used) {
            read_line();
            return;
          }
        }
        
        switch (m_state) {
        
          case S_READ_AUTH_T:
          {
            // currently only plain auth is supported
            static const boost::regex auth_line_re("auth[ \\t]+(plain|md5)[ \\t]*\\r", boost::regex::icase);
            const std::string line(&m_rx_buf[0]);
            if (regex_match(line, auth_line_re) ) {
              m_state = S_READ_USER;          
              m_auth_type = (string::npos != line.find("plain")) ? A_PLAIN : A_MD5;
              remove_bytes_from_buf(lf_pos + 1);
              static const string authok("+OK 202 Starting authorization sequence\r\n");
              send_line(authok);
            } else {
              cerr << endl << "auth type not supported: \"" << &m_rx_buf[0] << "\"" << endl;
              proto_err();
            }                   
            break;
          }
    
          case S_READ_USER:
          {
            static const boost::regex user_line_re("user[ \\t]+([a-zA-Z0-9]+)[ \\t]*\\r", boost::regex::icase);
            boost::cmatch what;
            if (regex_match( &m_rx_buf[0], what, user_line_re) ) {
              m_read_user = what[1];
              m_state = S_READ_PASS;
              static const string userok("+OK 311 Username accepted, password needed\r\n");
              send_line(userok);
              remove_bytes_from_buf(lf_pos + 1);
            } else {
              cerr << "error - expected user login" << endl;
              proto_err();
            }                   
            break;
          }
          
          case S_READ_PASS:
          {
            static const boost::regex pass_line_re("pass[ \\t]+([^ \\t\\r\\n]+)[ \\t]*\\r", boost::regex::icase);
            boost::cmatch what;
            if (regex_match( &m_rx_buf[0], what, pass_line_re) ) {
              const std::string pass = what[1];
#if 0
              cerr << "error: ignoring user and password - no auth checking!!!!" << endl;
#else
              if ((m_read_user != m_user) || (m_pass != pass)) {
                cerr << "login failure, received user: ***" << m_read_user << "*** received pass: ***" << pass << "***" << endl;
                static const string passok("+ERR 401 Username or password did not match.\r\n");
                send_line(passok);
                proto_err();
              }
#endif
              static const string passok("+OK 230 User logged in successfully\r\n");
              send_line(passok);
              m_state = S_READ_DATA;
              remove_bytes_from_buf(lf_pos + 1);
            } else {
              cerr << "error - expected password" << endl;
              proto_err();
            }                   
            break;          
          }
          
          case S_READ_DATA:
          {
            static const boost::regex pass_line_re("data[ \\t]*\\r", boost::regex::icase);
            if (regex_match( &m_rx_buf[0], pass_line_re) ) {
              m_state = S_DATA;
              static const string dataok("+OK 204 no data buffered\r\n");
              send_line(dataok);
              remove_bytes_from_buf(lf_pos + 1);
              m_fs = frame_sender<tcp::socket>::create(m_socket);
              m_fs->io_error.connect(boost::bind(&connection::close_sock, shared_from_this()));
              m_disp_c = frame_dispatcher::get()->new_frame_sig.connect(boost::bind(&frame_sender<tcp::socket>::add_to_send_queue, m_fs, _1, _2));
              read_data();
              return;
            } else {
              cerr << "error - expected password" << endl;
              proto_err();
            }                   
            break;          
          }
          
          case S_ERROR:
          default:
            proto_err();
            throw(std::runtime_error("connection state error"));
        
        
        };
        
      } while ((-1 != lf_pos) && m_socket.is_open());   
    
    }
    else
    {
      cerr << "line receive error: " << error.message() << endl;
      proto_err();
      close_sock();
    }
  };
  
  void remove_bytes_from_buf(const unsigned int size) {
    if (size < m_rx_buf_used) {
      //cout << "removing " << size << " of " << m_rx_buf_used << " octets from rx buffer " << endl;
      // circular_buffer ?
      copy(m_rx_buf.begin()+size, m_rx_buf.begin()+(m_rx_buf_used-1), m_rx_buf.begin());
      m_rx_buf_used -= size;
    } else {
      //cout << "rx buf is now empty (" << size << ")" << endl;
      m_rx_buf_used = 0;
    }
  
  };
  
  
  void read_data() {
    if (m_rx_buf_size > m_rx_buf_used) { 
      m_socket.async_read_some(boost::asio::buffer((&m_rx_buf[0])+m_rx_buf_used, m_rx_buf_size - m_rx_buf_used),
        boost::bind(&connection::handle_read_data, shared_from_this(),
        boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred));
    } else {
      cerr << "received frame to long" << endl;
      proto_err();
    }
  };

  void handle_read_data(const boost::system::error_code& error, size_t bytes_transferred)
  { 

    if (!error)
    {
    
      if (0 == bytes_transferred) {
       close_sock();
       return;
      }
    
      m_rx_buf_used += bytes_transferred;
      //cout << "read " << bytes_transferred << " bytes: ***" << string(&m_rx_buf[0], bytes_transferred) << "***" << endl;
      
      do {
        const unsigned int f_size = frame_size(&m_rx_buf[0], m_rx_buf_used);       
        if (0 == f_size) {
          break;
        }     
        
        if (check_checks((unsigned char*)&m_rx_buf[0], f_size)) {
        
          cout << "received frame with " << f_size << "bytes (" << this << ")" << endl;
          vector<char> frame(f_size);
          copy( m_rx_buf.begin(), m_rx_buf.begin() + f_size, frame.begin());
          // todo: optimize frame handling (copying etc)
          cout << "dispatching frame (" << this << ")" << endl;
          frame_dispatcher::get()->new_frame_sig(frame, m_fs.get());
        } else {
          cerr << "connection::handle_read_data discarding broken frame (wrong checksum)" << to_hex(&m_rx_buf[0], f_size) << endl;
        }
        remove_bytes_from_buf(f_size);
      } while (1);
      
      read_data();
      
    } else {
      proto_err();
    }

  };

  
  
  

private:
  enum state { S_ERROR, S_READ_AUTH_T, S_READ_USER, S_READ_PASS, S_READ_DATA, S_DATA };
  state m_state;
  enum auth_t { A_PLAIN, A_MD5 };
  
  auth_t m_auth_type;
  tcp::socket m_socket;
  
  const string m_user;
  const string m_pass;
  string m_read_user;
  
  static const unsigned int m_rx_buf_size = 4096;
  unsigned int m_rx_buf_used;
  std::vector<char> m_rx_buf;
  
  boost::signals::connection m_disp_c;
  
  boost::shared_ptr<frame_sender<tcp::socket> > m_fs;
};




class server
{
public:
  server(boost::asio::io_service& io_service, const short port, const std::string &user, const std::string &pass)
    : io_service_(io_service),
      acceptor_(io_service, tcp::endpoint(tcp::v4(), port)),
      m_user(user), m_pass(pass)
  {
    boost::shared_ptr<connection> new_connection(connection::create(io_service_, m_user, m_pass));
    acceptor_.async_accept(new_connection->socket(),
        boost::bind(&server::handle_accept, this, new_connection,
          boost::asio::placeholders::error));
  };

  void handle_accept(boost::shared_ptr<connection> con,
      const boost::system::error_code& error)
  {
    if (!error)
    {
      con->start();
      boost::shared_ptr<connection> new_connection(connection::create(io_service_, m_user, m_pass));
      acceptor_.async_accept(new_connection->socket(),
          boost::bind(&server::handle_accept, this, new_connection,
            boost::asio::placeholders::error));
    }
    else
    {

    }
  };

private:
  boost::asio::io_service& io_service_;
  tcp::acceptor acceptor_;
  const std::string m_user;
  const std::string m_pass;
};

void syntax() {


  cerr << "required args:"
       << " --port <port>"
       << " --device <serial device>"
       << " [--speed <baudrate, default 115k2>]"
       << " --user <username>"
       << " --pass <password>"
       << endl;
 exit(1);
}


int main(int argc, char* argv[])
{
  try
  {

   boost::program_options::options_description desc("Allowed options");
   desc.add_options()
    ("port", boost::program_options::value<unsigned short>(), "set listen port")
    ("device",  boost::program_options::value<string>(),  "set serial device")
    ("speed",  boost::program_options::value<unsigned int>(),  "set serial speed")
    ("user",  boost::program_options::value<string>(),  "set user name for authentication")
    ("pass",  boost::program_options::value<string>(),  "set auth password user must supply")
    ;  
    
   boost::program_options::variables_map vm;
   boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), vm);
   boost::program_options::notify(vm);
    
   if (!vm.count("port")) {
     cerr << "port not specified" << endl;
     syntax();
   }   
            
   if (!vm.count("device")) {
     cerr << "device not specified" << endl;
     syntax();
   }

   if (!vm.count("user")) {
     cerr << "user not specified" << endl;
     syntax();
   }
   
   if (!vm.count("pass")) {
     cerr << "pass not specified" << endl;
     syntax();
   }
   
   
   const unsigned short port = vm["port"].as<unsigned short>();
   const string device = vm["device"].as<string>();
   unsigned int speed = 115200;
   if (vm.count("speed")) {
     speed = vm["speed"].as<unsigned int>();
   }
   
   const std::string user = vm["user"].as<string>();
   const std::string pass = vm["pass"].as<string>();
                                    
   boost::asio::io_service io_service;

   server s(io_service, port, user, pass);
   boost::shared_ptr<serial> ser(serial::create(io_service, device, speed));
   ser->start();

   io_service.run();
  }
  catch (std::exception& e)
  {
    std::cerr << "Exception: " << e.what() << "\n";
  }

  return 0;
}
