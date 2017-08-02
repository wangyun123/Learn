#ifndef _MY_SINGLETON_H_
#define _MY_SINGLETON_H_

#include <pthread.h>

class Singleton
{
public:
    static Singleton* getInstance();
    static pthread_mutex_t mutex;

private:
    Singleton();

    static Singleton* pInstance;
};

#endif
