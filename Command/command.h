#ifndef COMMAND_H
#define COMMAND_H

#include <vector>

class Light;
class GarageDoor;
class Jacuzzi;
class StereoSystem;

class Command
{
public:
    virtual ~Command();
    virtual void execute() const = 0;
    virtual void undo() const = 0;
};

// Commands
class TurnOnLight : public Command
{
public:
    TurnOnLight(Light& rLight);
    void execute() const;
    void undo() const;

private:
    Light& m_rLight;
};

class TurnOffLight : public Command
{
public:
    TurnOffLight(Light& rLight);
    void execute() const;
    void undo() const;

private:
    Light& m_rLight;
};

class OpenDoor : public Command
{
public:
    OpenDoor(GarageDoor& rDoor);
    void execute() const;
    void undo() const;

private:
    GarageDoor& m_rDoor;
};

class CloseDoor : public Command
{
public:
    CloseDoor(GarageDoor& rDoor);
    void execute() const;
    void undo() const;

private:
    GarageDoor& m_rDoor;
};

class JacuzziOn : public Command
{
public:
    JacuzziOn(Jacuzzi& rJacuzzi);
    void execute() const;
    void undo() const;

private:
    Jacuzzi& m_rJacuzzi;
};

class JacuzziOff : public Command
{
public:
    JacuzziOff(Jacuzzi& rJacuzzi);
    void execute() const;
    void undo() const;

private:
    Jacuzzi& m_rJacuzzi;
};

class StereoSystemOn : public Command
{
public:
    StereoSystemOn(StereoSystem& rStereoSystem);
    void execute() const;
    void undo() const;

private:
    StereoSystem& m_rStereoSystem;
};

class StereoSystemOff : public Command
{
public:
    StereoSystemOff(StereoSystem& rStereoSystem);
    void execute() const;
    void undo() const;

private:
    StereoSystem& m_rStereoSystem;
};

class Party : public Command
{
public:
    Party(const std::vector<Command*> &arList);
    void execute() const;
    void undo() const;

private:
    const std::vector<Command*> &m_rList;
};

class NullObject : public Command
{
public:
    void execute() const;
    void undo() const;
};

class MiniRemoteControl
{
public:
    MiniRemoteControl();
    ~MiniRemoteControl();
    void set_command(Command* apCommand);
    void button_pressed();

private:
    Command* m_pSlot;
    NullObject* m_pEmptyCommand;
};

class SuperRemoteControl
{
public:
    SuperRemoteControl();
    ~SuperRemoteControl();
    void set_command(unsigned aSlot, Command* apCommandOn, Command* apCommandOff);
    void button_pressed_on(unsigned aSlot);
    void button_pressed_off(unsigned aSlot);
    void button_pressed_undo();

private:
    Command* m_commandOn[7];
    Command* m_commandOff[7];
    Command* m_pUndoCommand;
    NullObject* m_pEmptyCommand;
};

#endif // COMMAND_H
