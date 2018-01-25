#ifndef PERSON_H
#define PERSON_H

/**
 * @date 18 JAN 2018
 * @author Jarmila
 * @brief representation of person object link to the database
 */
 
#include <string>

/*--------------------------------------------------------------------*/
//some types
  typedef int IdPerson;
  typedef std::string NamePerson;
/*--------------------------------------------------------------------*/
  class Person
  {
//object attributs
  private:
    IdPerson m_id;
    NamePerson m_name;

//object methodes
  public:
    /**
     * @brief Create a new person. This person isn't add to the database.
     * @param in: name of the person
     */
    Person(const NamePerson & name);
    
    /**
     * @brief Load a person from the database
     * @param in: id of the person in the database
     * @exception runtime_error when the id doesn't exist
     */
    Person(IdPerson id);
    
    /**
     * @brief read a person from the database and store it in the object
     * @param in: id of the person in the database
     * @exception runtime_error when the id doesn't exist
     */
    void read(IdPerson id);
    /**
     * @brief write a person into the database. If the id is empty, 
     * we insert the person, otherwise we update the field
     */
    void write();
    
    IdPerson getId() const;
    
    NamePerson getName() const;
    void setName(const NamePerson & name);
    
    
    
    
//static methodes
  public:
    static void printAll();
  };
  
  std::ostream& operator<<(std::ostream &strm,const Person &person);

#endif // PERSON_H
