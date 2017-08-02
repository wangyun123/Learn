#include "singleton.h"
#include <iostream>
using namespace std;

Singleton* Singleton::pInstance = NULL;

Singleton::Singleton()
{
    cout << "construct Singleton" << endl;
}

Singleton* Singleton::getInstance()
{
    if (pInstance == NULL)
        pInstance = new Singleton();

    return pInstance;
}
