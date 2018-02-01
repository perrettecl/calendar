#include <iostream>
#include "person.h"


int main()//(int argc, char *argv[])
{
    std::cout << "Hello World!" << std::endl;
    Person::printAll();
    Person person(1);
    Person person2(3);
    std::cout << person2;
    person2.setName("Gabriela");
    person2.write();
    Person::printAll();
    
    char test;
    std::cin >> test;
    return 0;
}
