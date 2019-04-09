#ifndef OBSERVER_H
#define OBSERVER_H

#include <memory>
#include <vector>

class Observer;

class Subject
{
public:
    virtual ~Subject();
    virtual void RegisterObserver(std::shared_ptr<Observer>) = 0;
    virtual void RemoveObserver(std::shared_ptr<Observer>) = 0;
    virtual void NotifyObservers(void) const = 0;
};

class WeatherData : public Subject
{
public:
    void RegisterObserver(std::shared_ptr<Observer> apObserver) override;
    void RemoveObserver(std::shared_ptr<Observer> apObserver) override;
    void NotifyObservers() const override;
    void MeasurementsChanged() const;
    void SetMeasurements(float aTemp, float aHumidity, float aPressure);

private:
    std::vector<std::shared_ptr<Observer>> m_vpObservers;
    float m_Temp;
    float m_Humidity;
    float m_Pressure;
};

class Observer
{
public:
    virtual ~Observer();
    virtual void update(float, float, float) = 0;
};

class DisplayData
{
public:
    virtual ~DisplayData();
    virtual void display() = 0;
};

class CelsiusDegrees : public Observer, public DisplayData
{
public:
    void update(float aTemp, float aHumidity, float aPressure) override;
    void display() override;

private:
    float m_Temp;
    float m_Humidity;
    float m_Pressure;
};

class KelvinDegrees : public Observer, public DisplayData
{
public:
    void update(float aTemp, float aHumidity, float aPressure) override;
    void display() override;

private:
    float m_Temp;
    float m_Humidity;
    float m_Pressure;
};


#endif // OBSERVER_H
