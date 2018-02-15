#ifndef SQL_H
#define SQL_H

#include "dbmanager.h"
#include <string>

typedef std::string SqlQuery;

class Sql;
class Sql
{
	//------------- Variables
private:
	sqlite3_stmt *m_pStatement;
	bool m_returnRow;
	//------------- Functions

public:
	Sql(const SqlQuery & query);
	void execQuery();
	bool gotRow();
	bool nextRow();
	
	~Sql();

private:
	Sql() = delete;
	Sql(DbManager const&) = delete;
	Sql& operator=(DbManager const&) = delete;
	


};

#endif // SQL
