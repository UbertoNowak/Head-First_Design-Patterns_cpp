#include <iostream>
#include "command.h"
#include "smarthome.h"

Command::~Command()
{}

TurnOnLight::TurnOnLight(Light& rLight) : m_rLight(rLight)
{}

void TurnOnLight::execute() const
{
    m_rLight.turn_on();
}

void NullObject::execute() const
{
    std::cout<< "Empty command" << std::endl;
}

MiniRemoteControl::MiniRemoteControl()
{
    m_pEmptyCommand = new NullObject;
    m_pSlot = m_pEmptyCommand;
}

MiniRemoteControl::~MiniRemoteControl()
{
    delete m_pEmptyCommand;
}

void MiniRemoteControl::set_command(Command* apCommand)
{
    m_pSlot = apCommand;
}

void MiniRemoteControl::button_pressed()
{
    m_pSlot->execute();
}

int main()
{
    std::cout << "Command pattern example" << std::endl;
    Light light;
    TurnOnLight command_light(light);
    MiniRemoteControl RemoteControl;

    RemoteControl.button_pressed();
    RemoteControl.set_command(&command_light);
    RemoteControl.button_pressed();

    return 0;
}
