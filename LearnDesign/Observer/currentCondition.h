#ifndef _CURRENT_CONDITION_H_
#define _CURRENT_CONDITION_H_

#include "object.h"
#include <iostream>
using namespace std;

class CurrentCondition : public Object
{
public:
    CurrentCondition() {
        cout << "construct CurrentCondition" << endl;
    }
    virtual ~CurrentCondition() {
        cout << "destruct CurrentCondition" << endl;
    }

    void update(){
        cout << "Current Condition:" << temperature 
            << "," << humidity << "," << pressure << endl;
    }
};

#endif
