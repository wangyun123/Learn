#ifndef _WEATHERDATA_H_
#define _WEATHERDATA_H_

#include "subject.h"
#include "object.h"
#include <list>
using namespace std;

class WeatherData : public Subject
{
public:    
    WeatherData();
    ~WeatherData();

    virtual void registerObject(Object* obj);
    virtual void removeObject(Object* obj);
    virtual void notify();

private:
    list<Object*> m_list;
};

#endif
