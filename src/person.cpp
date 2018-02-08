#include "person.h"
#include "dbmanager.h"
#include <iostream>
#include <sstream>

  Person::Person(const NamePerson & name)
  : m_id(0), m_name(name)
  {
    
  }
/*--------------------------------------------------------------------*/
  Person::Person(IdPerson id)
  {
    read(id);
  }
/*--------------------------------------------------------------------*/
void Person::read(IdPerson id)
{
  //get the database instance
  sqlite3 *db = DbManager::getConnector();

  //create sql statement
  sqlite3_stmt *statement;
  const char* sqlQuery = "SELECT person.idPerson, person.name FROM person WHERE person.idPerson = ?";
  int returnCode = sqlite3_prepare_v2(db, sqlQuery, -1, &statement, 0);

  if (returnCode != SQLITE_OK)
  {
    sqlite3_finalize(statement);
    throw std::runtime_error("Error: prepare statement failed!");
  }
  
  //fill the statement with the idPerson 
  sqlite3_bind_int(statement, 1, id);
  
  //read the first answer
  returnCode = sqlite3_step(statement);
  
  //if we found a person with this id
  if( returnCode == SQLITE_ROW)
  {  
    //get the id                                            
    m_id = sqlite3_column_int(statement, 0);
    
    //get the name
    std::stringstream stream;
    stream << sqlite3_column_text(statement, 1);
    m_name = stream.str();
  }
  else
  {
    sqlite3_finalize(statement);
    throw std::runtime_error("Error: no person found with the id: "+std::to_string(id)+"!");
  }

  //remove the statement
  sqlite3_finalize(statement);
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
    //DELETE FROM person WHERE person.idPerson = 2; 
    //get the database instance
    sqlite3 *db = DbManager::getConnector();

    //create sql statement
    sqlite3_stmt *statement;
    const char* sqlQuery = "DELETE FROM person WHERE person.idPerson = ?";
    int returnCode = sqlite3_prepare_v2(db, sqlQuery, -1, &statement, 0);

    if (returnCode != SQLITE_OK)
    {
      sqlite3_finalize(statement);
      throw std::runtime_error("Error: prepare statement failed!");
    }
    
    //fill the statement with the idPerson 
    sqlite3_bind_int(statement, 1, m_id);
    
    //delete the person
    returnCode = sqlite3_step(statement);
    
    //if we can't delete
    if( returnCode != SQLITE_DONE)
    {
      sqlite3_finalize(statement);
      throw std::runtime_error("Error: impossible to delete the person with the ID: "+ std::to_string(m_id) +"!");
    }
    
    sqlite3_finalize(statement);
    
    m_id = 0;
  }
}
/*--------------------------------------------------------------------*/
void Person::insert()
{
  //INSERT INTO person (name) VALUES ("Gabriela")
  //get the database instance
  sqlite3 *db = DbManager::getConnector();

  //create sql statement
  sqlite3_stmt *statement;
  const char* sqlQuery = "INSERT INTO person (name) VALUES (?)";
  int returnCode = sqlite3_prepare_v2(db, sqlQuery, -1, &statement, 0);

  if (returnCode != SQLITE_OK)
  {
    sqlite3_finalize(statement);
    throw std::runtime_error("Error: prepare statement failed!");
  }
  
  //fill the statement with the name
  sqlite3_bind_text(statement, 1, m_name.c_str(), m_name.length(),SQLITE_STATIC);
  
  //insert the person
  returnCode = sqlite3_step(statement);
  
  //if insert a person is successfull we get the id
  if( returnCode == SQLITE_DONE)
  {  
    //get the id                                            
    m_id = sqlite3_last_insert_rowid(db);
  }
  else
  {
    sqlite3_finalize(statement);
    throw std::runtime_error("Error: impossible to add the person: "+ m_name +"!");
  }
  
  sqlite3_finalize(statement);
}
/*--------------------------------------------------------------------*/
void Person::update()
{
  //UPDATE person SET name = "Clément" WHERE person.idPerson = 2; 
  //get the database instance
  sqlite3 *db = DbManager::getConnector();

  //create sql statement
  sqlite3_stmt *statement;
  const char* sqlQuery = "UPDATE person SET name = ? WHERE person.idPerson = ?";
  int returnCode = sqlite3_prepare_v2(db, sqlQuery, -1, &statement, 0);

  if (returnCode != SQLITE_OK)
  {
    sqlite3_finalize(statement);
    throw std::runtime_error("Error: prepare statement failed!");
  }
  
  //fill the statement with the name 
  sqlite3_bind_text(statement, 1, m_name.c_str(), m_name.length(),SQLITE_STATIC);
  //fill the statement with the idPerson 
  sqlite3_bind_int(statement, 2, m_id);
  
  //insert the person
  returnCode = sqlite3_step(statement);
  
  //if we can't update
  if( returnCode != SQLITE_DONE)
  {
    sqlite3_finalize(statement);
    throw std::runtime_error("Error: impossible to add the person: "+ m_name +"!");
  }
  
  sqlite3_finalize(statement);
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
std::ostream& operator<<(std::ostream &strm, const Person &person) {
  return strm << "Person(namePerson = " << person.getName() << ", ID = " << person.getId() << ")" << std::endl;
}
/*--------------------------------------------------------------------*/
void Person::setName(const NamePerson & name)
{
  m_name = name;
}
/*--------------------------------------------------------------------*/
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
