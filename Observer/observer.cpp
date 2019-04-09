#include <algorithm>
#include <iostream>
#include "observer.h"

Subject::~Subject()
{}

Observer::~Observer()
{}

DisplayData::~DisplayData()
{}

void WeatherData::RegisterObserver(std::shared_ptr<Observer> apObserver)
{
    m_vpObservers.push_back(apObserver);
}

void WeatherData::RemoveObserver(std::shared_ptr<Observer> apObserver)
{
    auto it = std::find(m_vpObservers.begin(), m_vpObservers.end(), apObserver);
    if (it != m_vpObservers.end())
    {
        m_vpObservers.erase(it);
    }
}

void WeatherData::NotifyObservers() const
{
    for(auto&& i : m_vpObservers)
    {
        i->update(m_Temp, m_Humidity, m_Pressure);
    }
}

void WeatherData::MeasurementsChanged() const
{
    NotifyObservers();
}

void WeatherData::SetMeasurements(float aTemp, float aHumidity, float aPressure)
{
    m_Temp = aTemp;
    m_Humidity = aHumidity;
    m_Pressure = aPressure;
    MeasurementsChanged();
}

void CelsiusDegrees::update(float aTemp, float aHumidity, float aPressure)
{
    m_Temp = aTemp;
    m_Humidity = aHumidity;
    m_Pressure = aPressure;
    display();
}

void CelsiusDegrees::display()
{
    std::cout << "Temp: " << m_Temp << " C, humidity: " << m_Humidity <<
                 ", pressure: " << m_Pressure << std::endl;
}

void KelvinDegrees::update(float aTemp, float aHumidity, float aPressure)
{
    m_Temp = aTemp + 273.15;
    m_Humidity = aHumidity;
    m_Pressure = aPressure;
    display();
}

void KelvinDegrees::display()
{
    std::cout << "Temp: " << m_Temp << " K, humidity: " << m_Humidity <<
                 ", pressure: " << m_Pressure << std::endl;
}

int main()
{
    WeatherData weatherStation;
    std::shared_ptr<Observer> celsius(new CelsiusDegrees());
    std::shared_ptr<Observer> kelvin(new KelvinDegrees());

    weatherStation.RegisterObserver(celsius);
    weatherStation.RegisterObserver(kelvin);

    weatherStation.SetMeasurements(18.5, 44.4, 985.0);
    weatherStation.RemoveObserver(kelvin);
    weatherStation.SetMeasurements(25.1, 65.5, 1002.0);

    return 0;
}
