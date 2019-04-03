#ifndef ADAPTER_H
#define ADAPTER_H

class EuropeanSocket
{
public:
    virtual int voltage();
    virtual int frequency();
    virtual ~EuropeanSocket();
};

class AmericanSocket
{
public:
    int voltage_110();
    int voltage_120();
    float freq_60Hz();
};

class BatteryCharger
{
public:
    void plugIn(EuropeanSocket* apSocket);
    void charge();

private:
    EuropeanSocket* m_pSocket;
};


class ObjectAdapter : public EuropeanSocket
{
public:
    ObjectAdapter(AmericanSocket* apSocket);
    int voltage() override;
    int frequency() override;

private:
    AmericanSocket* m_pSocket;
};

class ClassAdapter
{
public:
    ClassAdapter();
};

#endif // ADAPTER_H