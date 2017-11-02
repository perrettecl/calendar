#include "person.h"
#include "dbmanager.h"
#include <QSqlQuery>
#include <QVariant>
#include <iostream>

Person::Person()
{

}

void Person::printAll()
{
    QSqlQuery query;
    query = DbManager::execQuery("SELECT * FROM PERSON");
    while (query.next())
    {
        int indexPerson = query.value(0).toInt();
        std::string namePerson = query.value(1).toString().toStdString();
        std::cout << indexPerson << " " << namePerson << std::endl;
    }
}
