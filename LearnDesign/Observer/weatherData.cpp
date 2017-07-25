#include "weatherData.h"

WeatherData::WeatherData()
{
}
WeatherData::~WeatherData()
{
}

void WeatherData::registerObject(Observer* obj)
{
    m_list.push_back(obj);
}
void WeatherData::removeObject(Observer* obj)
{
    m_list.remove(obj);
}
void WeatherData::notify() const
{
    for(list<Observer*>::const_iterator it=m_list.begin(); it!=m_list.end(); ++it)
    {
        (*it)->update();
    }
}
