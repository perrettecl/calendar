#include <iostream>
#include "dbmanager.h"


int main()//(int argc, char *argv[])
{
	std::cout << "Hello World!" << std::endl;
	DbManager::execQuery(" SELECT * FROM Event");
	char test;
	std::cin >> test;
	return 0;
}