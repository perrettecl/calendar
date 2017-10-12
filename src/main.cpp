#include <iostream>
#include "dbmanager.h"

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;
    DbManager* db = DbManager::getInstance();
    return 0;
}
