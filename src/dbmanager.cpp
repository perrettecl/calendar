#include "dbmanager.h"
#include <iostream>
DbManager* DbManager::m_instance = NULL;

DbManager::DbManager()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("calendar.db");
    if (!m_db.open())
      {
         std::cerr << "Error: connection with database fail" << std::endl;
      }
      else
      {
         std::cerr << "Database: connection ok" << std::endl;
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

QSqlQuery DbManager::execQuery(const std::string& query)
{
    DbManager* db = getInstance();
    return db->m_db.exec(QString::fromStdString(query));
}
