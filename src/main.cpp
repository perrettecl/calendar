#include <iostream>
#include "person.h"
#include "event.h"


int main()//(int argc, char *argv[])
{
    std::cout << "Hello World!" << std::endl;
    Person::printAll();
    Person person(1);
    std::cout << "Available events:" << std::endl;
	Event::printAll();
	std::cout << "Events list end." << std::endl;
    std::cout << person.getName() << std::endl;
    std::cout << person;
    char test;
    std::cin >> test;
    return 0;
}
