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

	//object methods
public:

	/*
	@brief Create a new Event object
	@param in: title, from, until, text
	*/
	Event(const TitleEvent & title, const FromEvent & from, const UntilEvent & until, const TextEvent & text);


	/**
	* @brief Load an event by its id
	* @param in: id of the event in the database
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
	//void write();

	//void erase();

	IdEvent getId() const;

	TitleEvent getTitle() const;
	void setTitle(const TitleEvent & title);

	FromEvent getFrom() const;
	void setFrom(const FromEvent & from);

	UntilEvent getUntil() const;
	void setUntil(const UntilEvent & until);

	TextEvent getText() const;
	void setText(const TextEvent & text);

private: 
	void insert();
	//void update(int idEvent);


	//static methods
public:
	static void printAll();
	static void write();
	static void update(int idEvent);
	static void erase(int idEvent);
};

std::ostream& operator<<(std::ostream &strm, const Event &event);

#endif // EVENT_H
