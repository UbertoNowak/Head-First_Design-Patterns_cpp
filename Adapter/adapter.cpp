#include <iostream>
#include "adapter.h"

int EuropeanSocket::voltage()
{
    return 230;
}

int EuropeanSocket::frequency()
{
    return 50;
}

int AmericanSocket::voltage_110()
{
    return 110;
}

int AmericanSocket::voltage_120()
{
    return 120;
}

double AmericanSocket::freq_60Hz()
{
    return 60.001;
}

void BatteryCharger::plugIn(EuropeanSocket *apSocket)
{
    m_pSocket = apSocket;
}

void BatteryCharger::charge()
{
    std::cout<< "Voltage " << m_pSocket->voltage() << ", frequency " << m_pSocket->frequency() << std::endl;
}

ObjectAdapter::ObjectAdapter(AmericanSocket* apSocket)
{
    m_pSocket = apSocket;
}

int ObjectAdapter::voltage()
{
    return m_pSocket->voltage_110();
}

int ObjectAdapter::frequency()
{
    return static_cast<int>(m_pSocket->freq_60Hz());
}

ClassAdapter::ClassAdapter()
{

}

int main()
{
    BatteryCharger charger;
    AmericanSocket incompatible_socket;
    ObjectAdapter adapter(&incompatible_socket);
    charger.plugIn(&adapter);
    charger.charge();

    return 0;
}
