#ifndef DBMANAGER_H
#define DBMANAGER_H
#include <QtSql/QSqlDatabase>

class DbManager;
class DbManager
{
//------------- Variables
private:
    static DbManager* instance;
    QSqlDatabase m_db;

//------------- Functions

public:
    static DbManager* getInstance();
private:
    DbManager();
    DbManager(DbManager const&){};
    DbManager& operator=(DbManager const&){};

};

#endif // DBMANAGER_H
