#include <iostream>
#include "person.h"


int main()//(int argc, char *argv[])
{
    std::cout << "Hello World!" << std::endl;
    Person::printAll();
    Person person(1);
    std::cout << person.getName() << std::endl;
    std::cout << person;
    char test;
    std::cin >> test;
    return 0;
}
