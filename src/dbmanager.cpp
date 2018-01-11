#include "dbmanager.h"
#include <iostream>
#include <exception>

DbManager* DbManager::m_instance = NULL;

DbManager::DbManager()
{
	int returnCode;

	//try to open the database
    returnCode = sqlite3_open("../database/calendar.db", &m_db);

	//check if it's open
	if (returnCode)
    {
       throw std::runtime_error("Error: connection with database failed!");
    }

}

sqlite3* DbManager::getConnector()
{
	return getInstance()->m_db;
}

DbManager* DbManager::getInstance()
{

    if(!DbManager::m_instance)
    {
        DbManager::m_instance = new DbManager();
    }

    return DbManager::m_instance;
}

void DbManager::execQuery(const std::string& query)
{
	//get the database instance
	sqlite3 *db = getInstance()->m_db;

	//create sql statement
	sqlite3_stmt *res;

	int rc = sqlite3_prepare_v2(db, query.c_str(), -1, &res, 0);

	if (rc != SQLITE_OK)
	{
		throw std::runtime_error("Error: prepare statement failed!");
	}

	//read the answer
	rc = sqlite3_step(res);

	if (rc == SQLITE_ROW)
	{
		std::cout << sqlite3_column_text(res, 0) << std::endl;
	}

	while ((rc = sqlite3_step(res)) == SQLITE_ROW)
	{                                              
		std::cout << sqlite3_column_int(res, 0) << std::endl;
	}

	//remove the statement
	sqlite3_finalize(res);
}
