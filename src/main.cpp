#include <iostream>
#include "person.h"


int main()//(int argc, char *argv[])
{
    std::cout << "Hello World!" << std::endl;
    Person::printAll();
    Person person("jarmilasagiova@gmail.com");
    Person person2("perrette.c@gmail.com");
    std::cout << person2;
    person2.setName("Thibaut");
    person2.write();
    person2.erase();
    Person::printAll();
    person2.write();
    Person::printAll();
    
    char test;
    std::cin >> test;
    return 0;
}
