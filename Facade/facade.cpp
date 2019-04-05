#include <iostream>
#include "facade.h"

void facade::leaving_the_house()
{
    m_Light.turn_off();
    m_Stereo.turn_off();
    m_Jacuzzi.turn_off();
    m_Door.close();
}

void facade::party_mode()
{
    m_Light.turn_on();
    m_Stereo.turn_on();
    m_Jacuzzi.turn_on();
}

void facade::relax_mode()
{
    m_Light.turn_off();
    m_Stereo.turn_on();
    m_Jacuzzi.turn_on();
    m_Door.close();
}

int main()
{
    facade simple_interface;
    simple_interface.party_mode();
    simple_interface.relax_mode();
    simple_interface.leaving_the_house();

    return 0;
}
