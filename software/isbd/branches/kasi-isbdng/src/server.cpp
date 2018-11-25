#include "server.h"

#include "Connection.h"
#include <log4cxx/logger.h>

#include <list>

#include <log4cxx/logger.h>

log4cxx::LoggerPtr Server::logger(log4cxx::Logger::getLogger("org.isysbus.Server"));

extern log4cxx::LoggerPtr logger;


Server::Server(boost::asio::io_service& io_service, std::string ipAddress, unsigned short port, Settings &s, BusDevice &dev) 
    : acceptor_(io_service, tcp::endpoint(tcp::v4(), port)), settings(s), busDevice(dev) {

	dev.connectReceiver(boost::bind(&Server::notifyRead, this, _1));

	start_accept();
	
/*	tcp_socket_ptr serverSocket(new tcp::socket(acceptor_.get_io_service()));
	acceptor_.async_accept(*serverSocket,
		boost::bind(&Server::handle_accept, this,
			new_connection, boost::asio::placeholders::error));
*/
}

void Server::handle_accept(Connection::pointer new_connection,
		const boost::system::error_code& ec) {
	LOG4CXX_DEBUG(logger,"handle_accept: errorcode: " << ec );
    if (!ec) {
      connections.push_back(new_connection);

      new_connection->connectReceiver(boost::bind(&Server::notifyRead, this, _1));
      new_connection->start();
      start_accept();
    }
}

void Server::start_accept() {

	LOG4CXX_DEBUG(logger,"Start accept");
	Connection::pointer new_connection = Connection::create(acceptor_.get_io_service(),settings,busDevice);

    acceptor_.async_accept(new_connection->socket(),
        boost::bind(&Server::handle_accept, this, new_connection,
          boost::asio::placeholders::error));
}

bool conn_is_inactive (const Connection::pointer& value) { return (! value.get()->isActive()); }

void Server::notifyRead(Packet &p) {
	/**
	 * Send data to clients
	 */
	
	if ( connections.size()==0) {
		return;
	}

	LOG4CXX_DEBUG(logger, "We have " << connections.size() <<  " connections - trying notify");

	int connNr=0;
	for (list<Connection::pointer>::iterator it = connections.begin(); it != connections.end(); ++it) {
		Connection *conn = (*it).get();
		connNr++;
		LOG4CXX_DEBUG(logger,"Checking connection " << connNr);
		if (conn->isActive() ) {
			if ( conn->isAcceptData()) {
				conn->write(p);
				conn->flushQueue();
			} else {
				LOG4CXX_DEBUG(logger," Conn is not in data mode");
			}
		} else {
			LOG4CXX_DEBUG(logger,"Conn is inactive");
		}
	}

	checkConnections();
}

void Server::removeConnection(const Connection *conn) {
	for (list<Connection::pointer>::iterator it = connections.begin(); it != connections.end(); ++it) {
		if ( (*it).get() == conn ) {
			it = connections.erase(it);
		}
	}
}

void Server::checkConnections() {
	connections.remove_if(conn_is_inactive);
} 
