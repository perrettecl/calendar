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
    static void execQuery(const std::string& query);

private:
    DbManager();
    DbManager(DbManager const&) =delete;
    DbManager& operator=(DbManager const&) =delete;
    ~DbManager()=delete;


};

#endif // DBMANAGER_H
