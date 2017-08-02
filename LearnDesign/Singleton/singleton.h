#ifndef _MY_SINGLETON_H_
#define _MY_SINGLETON_H_

class Singleton
{
public:
    static Singleton* getInstance();

private:
    Singleton();

    static Singleton* pInstance;
};

#endif
