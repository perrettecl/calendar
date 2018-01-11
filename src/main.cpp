#include <iostream>
#include "person.h"


int main()//(int argc, char *argv[])
{
	std::cout << "Hello World!" << std::endl;
	Person::printAll();
	char test;
	std::cin >> test;
	return 0;
}
