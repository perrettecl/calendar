#ifndef DBMANAGER_H
#define DBMANAGER_H
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>

class DbManager;
class DbManager
{
//------------- Variables
private:
    static DbManager* m_instance;
    QSqlDatabase m_db;

//------------- Functions

public:
    static DbManager* getInstance();
    static QSqlQuery execQuery(const std::string& query);
private:
    DbManager();
    DbManager(DbManager const&) =delete;
    DbManager& operator=(DbManager const&) =delete;
    ~DbManager()=delete;


};

#endif // DBMANAGER_H
