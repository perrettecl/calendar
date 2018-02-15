#ifndef DBMANAGER_H
#define DBMANAGER_H

#include "sqlite3.h"
#include <string>

class DbManager;
class DbManager
{
//------------- Variables
private:
    static DbManager* m_instance;
	sqlite3 *m_db;

//------------- Functions

public:
    static DbManager* getInstance();
    static sqlite3* getConnector();
    
    static void bind(sqlite3_stmt * statement, const std::string & value, uint32_t position);
    static void bind(sqlite3_stmt * statement, int value, uint32_t position);
    
    static std::string getString(sqlite3_stmt * statement, uint32_t position);
    static int getInt(sqlite3_stmt * statement, uint32_t position);

private:
    DbManager();
    DbManager(DbManager const&) =delete;
    DbManager& operator=(DbManager const&) =delete;
    ~DbManager()=delete;



};

#endif // DBMANAGER_H
