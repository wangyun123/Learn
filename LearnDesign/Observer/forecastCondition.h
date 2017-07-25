#ifndef _FORECAST_CONDITION_H_
#define _FORECAST_CONDITION_H_

#include "observer.h"
#include <iostream>
using namespace std;

class ForecastCondition : public Observer
{
public:
    ForecastCondition() 
        : temperature(30.0), humidity(80.0), pressure(100.0)
    {
        cout << "construct ForecastCondition" << endl;
    }
    virtual ~ForecastCondition() {
        cout << "destruct ForecastCondition" << endl;
    }

    void update(){
        cout << "Forecast Condition:" << temperature 
            << "," << humidity << "," << pressure << endl;
    }

private:
    float temperature;
    float humidity;
    float pressure;
};

#endif
