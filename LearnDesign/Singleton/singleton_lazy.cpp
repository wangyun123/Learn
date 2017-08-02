#include "singleton_lazy.h"
#include <iostream>
using namespace std;

Singleton* Singleton::pInstance = NULL;
pthread_mutex_t Singleton::mutex;

Singleton::Singleton()
{
    pthread_mutex_init(&mutex,NULL);
    cout << "construct Singleton" << endl;
}

Singleton* Singleton::getInstance()
{
    if (pInstance == NULL)
    {
        pthread_mutex_lock(&mutex);
        if (pInstance == NULL)
            pInstance = new Singleton();
        pthread_mutex_unlock(&mutex);
    }

    return pInstance;
}
