#include "MySingleton.h"

MySingleton* MySingleton::instance = NULL;

MySingleton::MySingleton()
    : semaphoreA(2), semaphoreB(0)
{
}

MySingleton* MySingleton::getInstance()
{
    if (instance==NULL)
        instance = new MySingleton;
    return instance;
}
