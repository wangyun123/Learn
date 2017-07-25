#ifndef _CURRENT_CONDITION_H_
#define _CURRENT_CONDITION_H_

#include "observer.h"
#include <iostream>
using namespace std;

class CurrentCondition : public Observer
{
public:
    CurrentCondition() 
        : temperature(12.0), humidity(30.0), pressure(200.0)
    {
        cout << "construct CurrentCondition" << endl;
    }
    virtual ~CurrentCondition() {
        cout << "destruct CurrentCondition" << endl;
    }

    void update(){
        cout << "Current Condition:" << temperature 
            << "," << humidity << "," << pressure << endl;
    }

private:
    float temperature;
    float humidity;
    float pressure;
};

#endif
