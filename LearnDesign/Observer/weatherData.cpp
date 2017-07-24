#include "weatherData.h"

WeatherData::WeatherData()
{
}
WeatherData::~WeatherData()
{
}

void WeatherData::registerObject(Object* obj)
{
    m_list.push_back(obj);
}
void WeatherData::removeObject(Object* obj)
{
    m_list.remove(obj);
}
void WeatherData::notify()
{
    for(list<Object*>::iterator it=m_list.begin(); it!=m_list.end(); ++it)
    {
        (*it)->update();
    }
}
