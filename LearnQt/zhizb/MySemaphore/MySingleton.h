#ifndef MYSINGLETON_H
#define MYSINGLETON_H

#include <QSemaphore>

class MySingleton
{
public:
    static MySingleton* getInstance();

private:
    MySingleton();

    static MySingleton* instance;

public:
    QSemaphore semaphoreA;
    QSemaphore semaphoreB;
};

#endif // MYSINGLETON_H
