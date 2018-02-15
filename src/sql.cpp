#include "sql.h"

Sql::Sql(const SqlQuery & query) : 
	m_pStatement(NULL), 
	m_returnRow(false)
{
	//get the database instance
	sqlite3 *pDb = DbManager::getConnector();
	int returnCode =  sqlite3_prepare_v2(pDb, query.c_str(), -1, &m_pStatement, 0);

	//create the statemment
	if (returnCode != SQLITE_OK)
	{
		throw std::runtime_error("Error: prepare statement failed!");
	}
}
/*--------------------------------------------------------------------*/
void Sql::execQuery()
{
	int returnCode = sqlite3_step(m_pStatement);
	if (returnCode != SQLITE_OK)
	{
		throw std::runtime_error("Error: prepare statement failed!");
	}

	if (returnCode == SQLITE_ROW)
	{
		m_returnRow = true;
	}
}
/*--------------------------------------------------------------------*/
bool Sql::gotRow()
{
	return m_returnRow;
}
/*--------------------------------------------------------------------*/
bool Sql::nextRow()
{
	return true;
}
/*--------------------------------------------------------------------*/
Sql::~Sql()
{
	//remove the statement
	sqlite3_finalize(m_pStatement);
}
/*--------------------------------------------------------------------*/