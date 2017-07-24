#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <iostream>
using namespace std;

class Object
{
public:
    Object() {
        cout << "construct Object" << endl;
    }
    virtual ~Object() {
        cout << "destruct Object" << endl;
    }

    virtual void update()=0;

public:
    float temperature;
    float humidity;
    float pressure;
};

#endif
