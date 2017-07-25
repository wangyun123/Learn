#ifndef _OBSERVER_H_
#define _OBSERVER_H_

#include <iostream>
using namespace std;

class Observer
{
public:
    Observer() {
        cout << "construct Observer" << endl;
    }
    virtual ~Observer() {
        cout << "destruct Observer" << endl;
    }

    virtual void update()=0;
};

#endif
