#include "event.h"
#include "dbmanager.h"
#include <iostream>
#include <sstream>

Event::Event(const TitleEvent & title)
	: m_id(0), m_title(title)
{

}

Event::Event(IdEvent id)
{
	read(id);
}

void Event::read(IdEvent id)
{
	//get the database instance
	sqlite3 *db = DbManager::getConnector();

	//create sql statement
	sqlite3_stmt *statement;
	const char* sqlQuery = "SELECT event.idEvent, event.title FROM event WHERE event.idEvent = ?";
	int returnCode = sqlite3_prepare_v2(db, sqlQuery, -1, &statement, 0);

	if (returnCode != SQLITE_OK)
	{
		throw std::runtime_error("Error: prepare statement failed!");
	}

	//fill the statement with the idEvent 
	sqlite3_bind_int(statement, 1, id);

	//read the first answer
	returnCode = sqlite3_step(statement);

	//if we found a person with this id
	if (returnCode == SQLITE_ROW)
	{
		//get the id                                            
		m_id = sqlite3_column_int(statement, 0);

		//get the name
		std::stringstream stream;
		stream << sqlite3_column_text(statement, 1);
		m_title = stream.str();
	}
	else
	{
		sqlite3_finalize(statement);
		throw std::runtime_error("Error: no event found with the id: " + std::to_string(id) + "!");
	}

	//remove the statement
	sqlite3_finalize(statement);
}
/*--------------------------------------------------------------------*/
void Event::write()
{
}
/*--------------------------------------------------------------------*/
IdEvent Event::getId() const
{
	return m_id;
}
/*--------------------------------------------------------------------*/
TitleEvent Event::getName() const
{
	return m_title;
}
/*--------------------------------------------------------------------*/
std::ostream& operator<<(std::ostream &strm, const Event &event) {
	return strm << "Event(nameEvent = " << event.getName() << ", ID = " << event.getId() << ")" << std::endl;
}
/*--------------------------------------------------------------------*/
void Event::setTitle(const TitleEvent & title)
{
	m_title = title;
}
/*--------------------------------------------------------------------*/
void Event::printAll()
{
	//get the database instance
	sqlite3 *db = DbManager::getConnector();

	//create sql statement
	sqlite3_stmt *res;
	int rc = sqlite3_prepare_v2(db, "SELECT event.idEvent, event.title FROM event", -1, &res, 0);

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
