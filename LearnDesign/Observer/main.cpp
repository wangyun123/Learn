#include <iostream>
#include "currentCondition.h"
#include "forecastCondition.h"
#include "weatherData.h"

using namespace std;

int main(void)
{
    CurrentCondition current;
    ForecastCondition forecast;

    //
    cout << "------------------" << endl;
    WeatherData subject;
    subject.registerObject(&current);
    subject.registerObject(&forecast);
    subject.notify();
   
    cout << "------------------" << endl;
    subject.removeObject(&forecast);
    subject.notify(); 

    getchar();

    return 0;
}
