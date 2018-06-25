#include <iostream>
#include "person.h"
#include "event.h"
#include "sql.h"
#include "sqlerror.h"


int main()//(int argc, char *argv[])
{
	try
	{
		std::cout << "Hello World!" << std::endl;
		Event::printAll();
		//Event::write();
		//Event::update(4);
		Event::erase(5);
		
	}
	catch (SqlError & e)
	{
		std::cout << e.what() << std::endl;
	}
	char test;
	std::cin >> test;
    return 0;
}
