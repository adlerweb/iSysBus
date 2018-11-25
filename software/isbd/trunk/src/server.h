#ifndef NET_SERVER_H
#define NET_SERVER_H

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <cmath>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <set>

#include "Connection.h"

using boost::asio::ip::tcp;

typedef boost::shared_ptr<tcp::socket> tcp_socket_ptr;
//typedef boost::shared_ptr<boost::asio::deadline_timer> timer_ptr;
//typedef boost::shared_ptr<control_request> control_request_ptr;


class server {
	public:
		server(boost::asio::io_service& io_service,  std::string ipAddress, unsigned short port);
		void handle_accept(Connection::pointer new_connection, const boost::system::error_code& ec);
		void start_accept();

private:
  // The acceptor used to accept incoming control connections.
	tcp::acceptor acceptor_;
//  tcp::acceptor acceptor_;

	boost::asio::io_service io_service;
	//tcp::socket serverSocket;

};
#endif
