#include <iostream>
#include "currentCondition.h"
#include "forecastCondition.h"
#include "weatherData.h"

using namespace std;

int main(void)
{
    CurrentCondition current;
    ForecastCondition forecast;

    WeatherData subject;
    subject.registerObject(&current);
    subject.registerObject(&forecast);
    subject.notify();
   
    subject.removeObject(&forecast);
    subject.notify(); 

    return 0;
}
