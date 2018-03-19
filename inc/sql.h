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

	//------------- Functions
public:
	Sql(const SqlQuery & query);
	bool execQuery();
	bool nextRow();
	~Sql();

	void bind(const std::string & value, uint32_t position);
	void bind(int value, uint32_t position);

	std::string getString(uint32_t position);
	int getInt(uint32_t position);

	static uint32_t lastInsertId();

private:
	Sql() = delete;
	Sql(DbManager const&) = delete;
	Sql& operator=(DbManager const&) = delete;
	


};

#endif // SQL
