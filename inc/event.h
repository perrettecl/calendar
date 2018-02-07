#ifndef EVENT_H
#define EVENT_H

/**
* @brief representation of event object link to the database
*/

#include <string>

/*--------------------------------------------------------------------*/
//some types
typedef int IdEvent;
typedef std::string TitleEvent;
typedef int FromEvent;
typedef int UntilEvent;
typedef std::string TextEvent;
/*--------------------------------------------------------------------*/
class Event
{
	//object attributs
private:
	IdEvent m_id;
	TitleEvent m_title;
	FromEvent m_from;
	UntilEvent m_until;
	TextEvent m_text;

	//object methodes
public:
	/**
	* @brief Create a new event.
	* @param in: name of the event
	*/
	Event(const TitleEvent & name);

	/**
	* @brief Load an event from the database
	* @param in: id of the event in the database
	* @exception runtime_error when the id doesn't exist
	*/
	Event(IdEvent id);

	/**
	* @brief read an event from the database and store it in the object
	* @param in: id of the event in the database
	* @exception runtime_error when the id doesn't exist
	*/
	void read(IdEvent id);
	/**
	* @brief write an event into the database. If the id is empty,
	* we insert the event, otherwise we update the field
	*/
	void write();

	IdEvent getId() const;

	TitleEvent getName() const;
	void setTitle(const TitleEvent & title);




	//static methodes
public:
	static void printAll();
};

std::ostream& operator<<(std::ostream &strm, const Event &event);

#endif // EVENT_H
