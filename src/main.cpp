#include <iostream>
#include "person.h"
#include "sql.h"
#include "event.h"
#include "sqlerror.h"


int main()//(int argc, char *argv[])
{
	try
	{
        std::cout << "Hello World!" << std::endl;
        Person::printAll();
        Person person(1);
        std::cout << person.getName() << std::endl;
        std::cout << person;		
	}
	catch (SqlError & e)
	{
		std::cout << e.what() << std::endl;
	}
	char test;
	std::cin >> test;
    return 0;
}
