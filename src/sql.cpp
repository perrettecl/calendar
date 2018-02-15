#include "sql.h"

Sql::Sql(const SqlQuery & query) : 
	m_pStatement(NULL)
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
bool Sql::execQuery()
{
	int returnCode = sqlite3_step(m_pStatement);
	if (returnCode != SQLITE_OK)
	{
		throw std::runtime_error("Error: prepare statement failed!");
	}

	if (returnCode == SQLITE_ROW)
	{
		return true;
	}

	return false;
}
/*--------------------------------------------------------------------*/
bool Sql::nextRow()
{
	return execQuery();
}
/*--------------------------------------------------------------------*/
Sql::~Sql()
{
	//remove the statement
	sqlite3_finalize(m_pStatement);
}
/*--------------------------------------------------------------------*/
void Sql::bind(const std::string & value, uint32_t position)
{
	DbManager::bind(m_pStatement, value, position);
}
/*--------------------------------------------------------------------*/
void Sql::bind(int value, uint32_t position)
{
	DbManager::bind(m_pStatement, value, position);
}
/*--------------------------------------------------------------------*/
std::string Sql::getString(uint32_t position)
{
	return DbManager::getString(m_pStatement, position);
}
/*--------------------------------------------------------------------*/
int Sql::getInt(uint32_t position)
{
	return DbManager::getInt(m_pStatement, position);
}
/*--------------------------------------------------------------------*/