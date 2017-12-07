#include "dbmanager.h"
#include <iostream>
#include <exception>
DbManager* DbManager::m_instance = NULL;

DbManager::DbManager()
{

	int returnCode;
	//try to open the database
    returnCode = sqlite3_open("../calendar/database/calendar.db", &m_db);

	//check if it's open
	if (returnCode)
    {
       throw std::runtime_error("Error: connection with database fail");
    }

}

DbManager* DbManager::getInstance()
{

    if(!DbManager::m_instance)
    {
        DbManager::m_instance = new DbManager();
    }

    return DbManager::m_instance;
}

//QSqlQuery DbManager::execQuery(const std::string& query)
//{
//    DbManager* db = getInstance();
//    QSqlQuery result = db->m_db.exec(QString::fromStdString(query));
//    return result;
//}
