//#include <QSqlError>
//#include <QFile>
#include "dbmanager.h"
#include <iostream>
#include <exception>
DbManager* DbManager::m_instance = NULL;

DbManager::DbManager()
{
//    m_db = QSqlDatabase::addDatabase("QSQLITE");
//    if(!QFile::exists("../calendar/database/calendar.db"))
//    {
//        throw std::runtime_error("Error: connection with database fail, the file doesn't exist");
//    }

//    m_db.setDatabaseName("../calendar/database/calendar.db");
//    if (!m_db.open())
//    {
//         throw std::runtime_error("Error: connection with database fail");
//    }
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
