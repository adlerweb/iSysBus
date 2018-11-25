#include "Settings.h"
#include "DbLogger.h"

#include "packet.h"
#include "isbdatagram.h"
#include "Tools.h"
#include <log4cxx/logger.h>

log4cxx::LoggerPtr DbLogger::logger(log4cxx::Logger::getLogger("org.isysbus.DbLogger"));


DbLogger::DbLogger(Settings & s) : m_settings(s) {
	int rc;

	if ( s.isEnableDb()) {
					rc = sqlite3_open(s.getDbName().c_str(),&m_db);
					
					if ( rc ) {
						LOG4CXX_ERROR(DbLogger::logger, "DB open failed : " << s.getDbName() << " " << sqlite3_errmsg(m_db));
					}


					createTables();
	}
}
static int sqliteCallback(void *NotUsed, int argc, char **argv, char **azColName) {
/*	int i;
	for(i=0; i<argc; i++){
	    LOG4CXX_DEBUG( DbLogger::logger, "SQLITE3: " << azColName[i] << " = " << argv[i] ? argv[i] : "NULL");
	}
*/
	return 0;
}

void DbLogger::logPacket(Packet &p) {
	if ( ! m_settings.isEnableDb()) { return; }

	if ( m_settings.isLogPackets() ) {
		execSql(sqlFromPacket(p));
	}
	logStatus(p);
}

void DbLogger::logStatus(Packet &p) {
	if ( ! m_settings.isEnableDb()) { return; }
	time_t now = time(0);
	std::string data = p.getData();

	if ( p.isMulticast()) {

		std::stringstream query ;
    ISBDatagram d(data);
    if ( d.getCmd()<1 || d.getCmd() >2) {
      LOG4CXX_DEBUG(DbLogger::logger,"Not logging command " << d.getCmd());
      return;
    }

		query << "SELECT timestamp from status WHERE mulid=" << p.getDest();

		char **result = 0; 
		char *errMsg = 0 ;
		int rows, cols;
		
		sqlite3_get_table(m_db, query.str().c_str(), &result, &rows,&cols, &errMsg);
	
		sqlite3_free_table(result);
		query.str("");
		if ( rows >0 ) {
			query << "UPDATE status set timestamp = " << now << ", status = ";
			query << d.getValue();
      query << ", tov=" << (int) d.getTOV();
      query << ", top=" << (int) d.getTOP();
			query << " WHERE mulid = " << (int) p.getDest();
			bool rc = execSql(query.str());
			if ( ! rc ) {
				LOG4CXX_ERROR(DbLogger::logger,"Error executing SQL update");
			}
		} else {
			LOG4CXX_DEBUG(DbLogger::logger," No status yet for multicast ID " << p.getDest() << " inserting.");
			query.str("");		
			query << "INSERT INTO status VALUES ( " << now;
      query << "," << p.getDest();
			query << "," << (int) d.getTOP();
      query << "," << (int) d.getTOV();
      query << "," << (int) d.getValue();
			query << ");";

			execSql(query.str());
		}
	} else {
		LOG4CXX_DEBUG(DbLogger::logger, "Not multicast not updating status");
	}
}

std::string DbLogger::sqlFromPacket(Packet &p) {
	std::stringstream retval;
	time_t now = time(0);
	
	retval << "INSERT INTO packets VALUES ( " 
		<< now << ","

		<< p.getSource() << "," 
		<< p.getDest() << "," 
		<< "'" << Tools::hexDump( p.getData()) << "',"
		<< p.getData().length() << ","
		<< p.getCrc()  << ","
		<< (int) p.getFlags() 
		<< ")";
	return retval.str();	
}

void DbLogger::createTables() {
	bool result;

	result = execSql("CREATE TABLE if not exists packets ( timestamp int, src int, dest int, data varchar[8], datalen int, crc int, flags int)");
	if ( ! result ) return;

	result = execSql("CREATE TABLE if not exists status ( timestamp int, mulid int, top int, tov int, status int)");
	if ( ! result ) return;

}

bool DbLogger::execSql(std::string query) {
	int rc ;
	char *sqlErrMsg =0;

	LOG4CXX_DEBUG(DbLogger::logger, "SQL Statement: " << query);

 	rc = sqlite3_exec(m_db, query.c_str(), sqliteCallback,0,&sqlErrMsg);
	if ( rc != SQLITE_OK ) {
		LOG4CXX_ERROR(DbLogger::logger, "SQL error: " << sqlErrMsg);
		sqlite3_free(sqlErrMsg);
		return false;
	}
	return true;
}
