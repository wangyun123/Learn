#ifndef _WEATHERDATA_H_
#define _WEATHERDATA_H_

#include "subject.h"
#include "observer.h"
#include <list>
using namespace std;

class WeatherData : public Subject
{
public:    
    WeatherData();
    ~WeatherData();

    virtual void registerObject(Observer* obj);
    virtual void removeObject(Observer* obj);
    virtual void notify() const;

private:
    list<Observer*> m_list;
};

#endif
