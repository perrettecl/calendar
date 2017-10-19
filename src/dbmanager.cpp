#include "dbmanager.h"
#include <iostream>
DbManager* DbManager::instance;

DbManager::DbManager()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("/home/jarmila/calendar/database/calendar.db");
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

    if(!DbManager::instance)
    {
        DbManager::instance = new DbManager();
    }

    return DbManager::instance;
}
