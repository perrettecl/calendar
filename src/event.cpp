#include "event.h"
#include "sql.h"
#include <iostream>
#include <sstream>

Event::Event(const TitleEvent & title, const FromEvent & from, const UntilEvent & until, const TextEvent & text)
	: m_id(0), m_title(title), m_from(from), m_until(until), m_text(text)
{

}

Event::Event(IdEvent id)
{
	read(id);
}

void Event::read(IdEvent id)
{
	Sql query = "SELECT event.idEvent, event.title FROM event WHERE event.idEvent = ?";
	query.bind(id,1);

	//if we found a person with this id
	if (query.execQuery())
	{
		int index = 0;

		m_id = query.getInt(index++);

		m_title = query.getString(index++);

		m_from = query.getInt(index++);

		m_until = query.getInt(index++);

		m_text = query.getString(index++);
	}
}
/*--------------------------------------------------------------------*/
void Event::write()
{
	Sql query = "INSERT INTO event (title, `from`, until, text) VALUES (?,?,?,?)";
	std::string test = "test title";
	std::string testtext = "test text";
	query.bind(test, 1);
	query.bind(12, 2);
	query.bind(24, 3);
	query.bind(testtext, 4);

	query.execQuery();

}

void Event::update(int idEvent)
{
	Sql query = "UPDATE event SET title = ?, `from` = ?, until = ?, text = ? WHERE idEvent = ?";

	std::string testUpdate = "test update";
	std::string testtextUpdate = "test text update";

	query.bind(testUpdate, 1);
	query.bind(11, 2);
	query.bind(25, 3);
	query.bind(testtextUpdate, 4);
	query.bind(idEvent, 5);

	query.execQuery();
}

void Event::erase(int idEvent)
{
	Sql query = "DELETE FROM event WHERE idEvent = ?";
	
	query.bind(idEvent, 1);

	query.execQuery();

}

/*--------------------------------------------------------------------*/
std::ostream& operator<<(std::ostream &strm, const Event &event) {
	return strm << "Event(nameEvent = " << event.getTitle() << ", ID = " << event.getId() << ")" << std::endl;
}

/*--------------------------------------------------------------------*/
IdEvent Event::getId() const
{
	return m_id;
}

TitleEvent Event::getTitle() const
{
	return m_title;
}

void Event::setTitle(const TitleEvent & title)
{
	m_title = title;
}

FromEvent Event::getFrom() const
{
	return m_from;
}

void Event::setFrom(const FromEvent & from)
{
	m_from = from;
}

UntilEvent Event::getUntil() const
{
	return m_until;
}

void Event::setText(const TextEvent & text)
{
	m_text = text;
}

TextEvent Event::getText() const
{
	return m_text;
}

void Event::printAll()
{
	Sql query = "SELECT event.idEvent, event.title FROM event";

	while (query.nextRow())
	{
		int index = 0;

		std::cout << query.getInt(index++);
		std::cout << " - ";
		std::cout << query.getString(index++) << std::endl;

	}
	
}
