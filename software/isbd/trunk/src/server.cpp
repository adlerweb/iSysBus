#include "server.h"

#include "Connection.h"
#include <log4cxx/logger.h>

#include <vector>

std::vector<Connection::pointer> connections;
extern log4cxx::LoggerPtr logger;


server::server(boost::asio::io_service& io_service, std::string ipAddress, unsigned short port) 
    : acceptor_(io_service, tcp::endpoint(tcp::v4(), port)) {

	start_accept();
	
/*	tcp_socket_ptr serverSocket(new tcp::socket(acceptor_.get_io_service()));
	acceptor_.async_accept(*serverSocket,
		boost::bind(&server::handle_accept, this,
			new_connection, boost::asio::placeholders::error));
*/
}

void server::handle_accept(Connection::pointer new_connection,
		const boost::system::error_code& ec) {
	LOG4CXX_DEBUG(logger,"handle_accept: errorcode: " << ec );
    if (!ec) {
      new_connection->start();
      start_accept();
    }
}

void server::start_accept() {

	LOG4CXX_DEBUG(logger,"Start accept");
    Connection::pointer new_connection =
      Connection::create(acceptor_.io_service());

    acceptor_.async_accept(new_connection->socket(),
        boost::bind(&server::handle_accept, this, new_connection,
          boost::asio::placeholders::error));
}
