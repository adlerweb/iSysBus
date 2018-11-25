#ifndef DB_LOGGER_H
#define DB_LOGGER_H

#include <string>
#include <sqlite3.h>
#include <log4cxx/logger.h>

class Frame;
class Settings;
class Packet;


class DbLogger {
public:
	static log4cxx::LoggerPtr logger;
	DbLogger(Settings & s);
	

	void logPacket(Packet &p);
	void logStatus(Packet &p) ;
	void updateStatus(Packet &p);
protected: 
	std::string sqlFromPacket(Packet &p);
	bool	execSql(std::string query);
	void createTables();

private:
	sqlite3 *m_db;
	Settings &m_settings;
};
#endif
