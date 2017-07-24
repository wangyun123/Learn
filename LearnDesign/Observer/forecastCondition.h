#ifndef _FORECAST_CONDITION_H_
#define _FORECAST_CONDITION_H_

#include "object.h"
#include <iostream>
using namespace std;

class ForecastCondition : public Object
{
public:
    ForecastCondition() {
        cout << "construct ForecastCondition" << endl;
    }
    virtual ~ForecastCondition() {
        cout << "construct ForecastCondition" << endl;
    }

    void update(){
        cout << "Forecast Condition:" << temperature 
            << "," << humidity << "," << pressure << endl;
    }
};

#endif
