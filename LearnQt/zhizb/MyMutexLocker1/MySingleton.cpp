#include "MySingleton.h"

MySingleton* MySingleton::instance = NULL;

MySingleton::MySingleton()
{
}

MySingleton* MySingleton::getInstance()
{
    if (instance==NULL)
        instance = new MySingleton;
    return instance;
}
