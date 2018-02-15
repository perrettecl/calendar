#include "dbmanager.h"
#include <iostream>
#include <exception>
#include <sstream>

DbManager* DbManager::m_instance = NULL;
/*--------------------------------------------------------------------*/
DbManager::DbManager()
{
  int returnCode;

  //try to open the database
    returnCode = sqlite3_open("./database/calendar.db", &m_db);

  //check if it's open
  if (returnCode)
    {
       throw std::runtime_error("Error: connection with database failed!");
    }

}
/*--------------------------------------------------------------------*/
sqlite3* DbManager::getConnector()
{
  return getInstance()->m_db;
}
/*--------------------------------------------------------------------*/
DbManager* DbManager::getInstance()
{

    if(!DbManager::m_instance)
    {
        DbManager::m_instance = new DbManager();
    }

    return DbManager::m_instance;
}
/*--------------------------------------------------------------------*/
void DbManager::bind(sqlite3_stmt * statement, const std::string & value, uint32_t position)
{
  sqlite3_bind_text(statement, position, value.c_str(), value.length(),SQLITE_STATIC);
}
/*--------------------------------------------------------------------*/
void DbManager::bind(sqlite3_stmt * statement, int value, uint32_t position)
{
  sqlite3_bind_int(statement, position, value);
}
/*--------------------------------------------------------------------*/
std::string DbManager::getString(sqlite3_stmt * statement, uint32_t position)
{
  std::stringstream stream;
  stream << sqlite3_column_text(statement, position);
  return stream.str();
}
/*--------------------------------------------------------------------*/
int DbManager::getInt(sqlite3_stmt * statement, uint32_t position)
{
  return sqlite3_column_int(statement, position);
}
/*--------------------------------------------------------------------*/
