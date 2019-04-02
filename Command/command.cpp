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

void TurnOnLight::undo() const
{
    m_rLight.turn_off();
}

TurnOffLight::TurnOffLight(Light& rLight) : m_rLight(rLight)
{}

void TurnOffLight::execute() const
{
    m_rLight.turn_off();
}

void TurnOffLight::undo() const
{
    m_rLight.turn_on();
}

OpenDoor::OpenDoor(GarageDoor& rDoor) : m_rDoor(rDoor)
{}

void OpenDoor::execute() const
{
    m_rDoor.open();
}

void OpenDoor::undo() const
{
    m_rDoor.close();
}

CloseDoor::CloseDoor(GarageDoor& rDoor) : m_rDoor(rDoor)
{}

void CloseDoor::execute() const
{
    m_rDoor.close();
}

void CloseDoor::undo() const
{
    m_rDoor.open();
}

JacuzziOn::JacuzziOn(Jacuzzi& rJacuzzi) : m_rJacuzzi(rJacuzzi)
{}

void JacuzziOn::execute() const
{
    m_rJacuzzi.turn_on();
}

void JacuzziOn::undo() const
{
    m_rJacuzzi.turn_off();
}

JacuzziOff::JacuzziOff(Jacuzzi& rJacuzzi) : m_rJacuzzi(rJacuzzi)
{}

void JacuzziOff::execute() const
{
    m_rJacuzzi.turn_off();
}

void JacuzziOff::undo() const
{
    m_rJacuzzi.turn_on();
}

StereoSystemOn::StereoSystemOn(StereoSystem& rStereoSystem) : m_rStereoSystem(rStereoSystem)
{}

void StereoSystemOn::execute() const
{
    m_rStereoSystem.turn_on();
}

void StereoSystemOn::undo() const
{
    m_rStereoSystem.turn_off();
}

StereoSystemOff::StereoSystemOff(StereoSystem& rStereoSystem) : m_rStereoSystem(rStereoSystem)
{}

void StereoSystemOff::execute() const
{
    m_rStereoSystem.turn_off();
}

void StereoSystemOff::undo() const
{
    m_rStereoSystem.turn_on();
}

Party::Party(const std::vector<Command*> &arList) : m_rList(arList)
{}

void Party::execute() const
{
    for(auto it = m_rList.begin(); it != m_rList.end(); ++it)
    {
        (*it)->execute();
    }
}

void Party::undo() const
{
    for(auto it = m_rList.rbegin(); it != m_rList.rend(); ++it)
    {
        (*it)->undo();
    }
}

void NullObject::execute() const
{
    std::cout<< "Empty command" << std::endl;
}

void NullObject::undo() const
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

SuperRemoteControl::SuperRemoteControl()
{
    m_pEmptyCommand = new NullObject;
    for(unsigned i = 0; i < sizeof(m_commandOn)/sizeof (m_commandOn[0]); i++)
    {
        m_commandOn[i] = m_pEmptyCommand;
        m_commandOff[i] = m_pEmptyCommand;
    }
    m_pUndoCommand = m_pEmptyCommand;
}

SuperRemoteControl::~SuperRemoteControl()
{
    delete m_pEmptyCommand;
}

void SuperRemoteControl::set_command(unsigned aSlot, Command *apCommandOn, Command *apCommandOff)
{
    if(aSlot >= 0 && aSlot < sizeof(m_commandOn)/sizeof (m_commandOn[0]))
    {
        m_commandOn[aSlot] = apCommandOn;
        m_commandOff[aSlot] = apCommandOff;
    }
    else
    {
        std::cout << "Wrong slot number" << std::endl;
    }
}

void SuperRemoteControl::button_pressed_on(unsigned aSlot)
{
    if(aSlot >= 0 && aSlot < sizeof(m_commandOn)/sizeof (m_commandOn[0]))
    {
        m_commandOn[aSlot]->execute();
        m_pUndoCommand = m_commandOn[aSlot];
    }
    else
    {
        std::cout << "Wrong slot number" << std::endl;
    }
}

void SuperRemoteControl::button_pressed_off(unsigned aSlot)
{
    if(aSlot >= 0 && aSlot < sizeof(m_commandOn)/sizeof (m_commandOn[0]))
    {
        m_commandOff[aSlot]->execute();
        m_pUndoCommand = m_commandOff[aSlot];
    }
    else
    {
        std::cout << "Wrong slot number" << std::endl;
    }
}

void SuperRemoteControl::button_pressed_undo()
{
    m_pUndoCommand->undo();
}

int main()
{
    std::cout << "Command pattern example" << std::endl;
    Light light;
    TurnOnLight kitchen_light_on(light);
    TurnOffLight kitchen_light_off(light);
    GarageDoor door;
    OpenDoor open_garage_door(door);
    CloseDoor close_garage_door(door);
    Jacuzzi jacuzzi;
    JacuzziOn jacuzzi_turn_on(jacuzzi);
    JacuzziOff jacuzzi_turn_off(jacuzzi);
    StereoSystem stereo;
    StereoSystemOn stereo_turn_on(stereo);
    StereoSystemOff stereo_turn_off(stereo);

    MiniRemoteControl BasicRemoteControl;
    SuperRemoteControl RemoteControl;

    BasicRemoteControl.button_pressed();
    BasicRemoteControl.set_command(&kitchen_light_on);
    BasicRemoteControl.button_pressed();

    std::cout << std::endl;

    RemoteControl.set_command(0, &kitchen_light_on, &kitchen_light_off);
    RemoteControl.set_command(1, &open_garage_door, &close_garage_door);
    RemoteControl.button_pressed_on(0);
    RemoteControl.button_pressed_on(1);
    RemoteControl.button_pressed_on(2);
    RemoteControl.button_pressed_off(0);
    RemoteControl.button_pressed_off(1);
    RemoteControl.button_pressed_undo();

    std::cout << std::endl;
    std::vector<Command*> p_party_on;
    p_party_on.push_back(&kitchen_light_off);
    p_party_on.push_back(&jacuzzi_turn_on);
    p_party_on.push_back(&stereo_turn_on);
    std::vector<Command*> p_party_off;
    p_party_off.push_back(&kitchen_light_on);
    p_party_off.push_back(&jacuzzi_turn_off);
    p_party_off.push_back(&stereo_turn_off);
    Party party_on(p_party_on);
    Party party_off(p_party_off);

    RemoteControl.set_command(2, &party_on, &party_off);
    RemoteControl.button_pressed_on(2);
    RemoteControl.button_pressed_undo();
    RemoteControl.button_pressed_off(2);

    return 0;
}
