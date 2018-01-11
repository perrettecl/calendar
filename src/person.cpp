#include "person.h"
#include "dbmanager.h"
#include <iostream>

Person::Person()
{

}

void Person::printAll()
{
	//get the database instance
	sqlite3 *db = DbManager::getConnector();

	//create sql statement
	sqlite3_stmt *res;

	int rc = sqlite3_prepare_v2(db, "SELECT person.idPerson, person.name FROM PERSON", -1, &res, 0);

	if (rc != SQLITE_OK)
	{
		throw std::runtime_error("Error: prepare statement failed!");
	}

	//read the answer
	while ((rc = sqlite3_step(res)) == SQLITE_ROW)
	{                                              
		std::cout << sqlite3_column_int(res, 0) << " - ";
		std::cout << sqlite3_column_text(res, 1) << std::endl;
	}

	//remove the statement
	sqlite3_finalize(res);
}
