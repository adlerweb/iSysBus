#ifndef NET_SERVER_H
#define NET_SERVER_H

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <cmath>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <set>
#include "Settings.h"
#include "Connection.h"
//#include "ConnectionListener.h"
#include <log4cxx/logger.h>

using boost::asio::ip::tcp;

typedef boost::shared_ptr<tcp::socket> tcp_socket_ptr;
//typedef boost::shared_ptr<boost::asio::deadline_timer> timer_ptr;
//typedef boost::shared_ptr<control_request> control_request_ptr;


class Server : public boost::enable_shared_from_this<Server> {
	public:
		static log4cxx::LoggerPtr logger;
                typedef boost::shared_ptr<Server> pointer;
		void handle_accept(Connection::pointer new_connection, const boost::system::error_code& ec);
		void start_accept();
		void checkConnections();
		void notifyRead(Packet &p);
		void removeConnection(const Connection * conn);
		Server(boost::asio::io_service& io_service,  std::string ipAddress, unsigned short port, Settings &settings, BusDevice &dev);
protected:

private:
  // The acceptor used to accept incoming control connections.
	tcp::acceptor acceptor_;
	Settings &settings;
	BusDevice &busDevice;
//  tcp::acceptor acceptor_;

	boost::asio::io_service io_service;
	list<Connection::pointer> connections;
	//tcp::socket serverSocket;

};
#endif
