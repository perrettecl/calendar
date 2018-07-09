#include "person.h"
#include "sql.h"
#include <iostream>
#include <sstream>


  Person::Person(const NamePerson & name, const SurnamePerson & surname, const EmailPerson & email)
  : m_id(0), m_name(name), m_surname(surname), m_email(email)
  {
    
  }
/*--------------------------------------------------------------------*/
  Person::Person(IdPerson id)
  {
    read(id);
  }
/*--------------------------------------------------------------------*/
  Person::Person(const EmailPerson & email)
  {
    read(email);
  }
/*--------------------------------------------------------------------*/
void Person::read(IdPerson id)
{  
  Sql query("SELECT person.idPerson, person.name, person.surname, person.email FROM person WHERE person.idPerson = ?");
  
  query.bind(id, 1);
  
  //if we found a person with this id
  if(query.execQuery())
  {  
    int index = 0;
    //get the id
    m_id = query.getInt(index++);                                           
    
    //get the name
    m_name = query.getString(index++);
    
    //get the surname
    m_surname = query.getString(index++);
    
    //get the email
    m_email = query.getString(index++);
  }
}
/*--------------------------------------------------------------------*/
void Person::read(const EmailPerson & email)
{
  //create sql statement
  Sql query("SELECT person.idPerson, person.name, person.surname, person.email FROM person WHERE person.email = ?");

  //fill the statement with the email
  query.bind(email, 1);
  
  
  //if we found a person with this email
  if(query.execQuery())
  {  
    int index = 0;
    //get the id
    m_id = query.getInt(index++);                                           
    
    //get the name
    m_name = query.getString(index++);
    
    //get the surname
    m_surname = query.getString(index++);
    
    //get the email
    m_email = query.getString(index++);
  }
}
/*--------------------------------------------------------------------*/
void Person::write()
{
  if (m_id == 0) // insert
  {
    insert();
  }
  else // update
  {
    update();
  }
}
/*--------------------------------------------------------------------*/
void Person::erase()
{
  if (m_id != 0)
  {
    Sql query("DELETE FROM person WHERE person.idPerson = ?");
  
    query.bind(m_id, 1);
    
    query.execQuery();
    
    m_id = 0;
  }
}
/*--------------------------------------------------------------------*/
void Person::insert()
{
  //INSERT INTO person (name) VALUES ("Gabriela")
  Sql query("INSERT INTO person (name, surname, email) VALUES (?, ?, ?)");
  
  int index = 1;
  
  //fill the statement with the name
  query.bind(m_name, index++);
  
  //fill the statement with the surname
  query.bind(m_surname, index++);
  
  //fill the statement with the email
  query.bind(m_email, index++);
  
  //insert the person
  query.execQuery();
  
  //get the id                                            
  m_id = Sql::lastInsertId();
}
/*--------------------------------------------------------------------*/
void Person::update()
{
  //UPDATE person SET name = "Clément" WHERE person.idPerson = 2; 
  //get the database instance
  Sql query("UPDATE person SET name = ?, surname = ?, email = ? WHERE person.idPerson = ?");
  
  int index = 1;
  
  //fill the statement with the name 
  query.bind(m_name, index++);
  
  //fill the statement with the surname 
  query.bind(m_surname, index++);
  
  //fill the statement with the email 
  query.bind(m_email, index++);
    
  query.execQuery();
}
/*--------------------------------------------------------------------*/
IdPerson Person::getId() const
{
  return m_id;
}
/*--------------------------------------------------------------------*/
NamePerson Person::getName() const
{
  return m_name;
}
/*--------------------------------------------------------------------*/
std::ostream& operator<<(std::ostream &strm, const Person &person) 
{
  return strm << "Person(name = " << person.getName()
    << ", surname = " << person.getSurname()
    << ", email = " << person.getEmail()
    << ", ID = " << person.getId()
    << ")" << std::endl;
}
/*--------------------------------------------------------------------*/
void Person::setName(const NamePerson & name)
{
  m_name = name;
}
/*--------------------------------------------------------------------*/
SurnamePerson Person::getSurname() const
{
  return m_surname;
}
/*--------------------------------------------------------------------*/
void Person::setSurname(const SurnamePerson & surname)
{
  m_surname = surname;
}
/*--------------------------------------------------------------------*/
EmailPerson Person::getEmail() const
{
  return m_email;
}
/*--------------------------------------------------------------------*/
void Person::setEmail(const EmailPerson & email)
{
  m_email = email;
}
/*--------------------------------------------------------------------*/
void Person::printAll()
{
  Sql query("SELECT person.idPerson, person.name, person.surname, person.email FROM PERSON");

  //read the answer
  while (query.nextRow())
  {
    int index = 0;                                             
    std::cout << query.getInt(index++) << " - ";
    std::cout << query.getString(index++) << " ";
    std::cout << query.getString(index++) << ", ";
    std::cout << query.getString(index++) << std::endl;
  }
}
