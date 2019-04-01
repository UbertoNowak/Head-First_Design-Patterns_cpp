#include <iostream>
#include "smarthome.h"

void Light::turn_on()
{
    std::cout<< "Light turned on" <<std::endl;
}

void Light::turn_off()
{
    std::cout<< "Light turned off" <<std::endl;
}

void GarageDoor::open()
{
    std::cout<< "Open garage door" <<std::endl;
}

void GarageDoor::close()
{
    std::cout<< "Close garage door" <<std::endl;
}

void Ventilator::turn_on()
{
    std::cout<< "Ventilator turned on" <<std::endl;
}

void Ventilator::turn_off()
{
    std::cout<< "Ventilator turned off" <<std::endl;
}

void StereoSystem::turn_on()
{
    std::cout<< "StereoSystem turned on" <<std::endl;
}

void StereoSystem::turn_off()
{
    std::cout<< "StereoSystem turned off" <<std::endl;
}
