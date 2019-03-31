#ifndef COMMAND_H
#define COMMAND_H

class Light;

class Command
{
public:
  virtual ~Command();
  virtual void execute() const = 0;
};

// Commands
class TurnOnLight : public Command
{
public:
    TurnOnLight(Light& rLight);
    void execute() const;

private:
    Light& m_rLight;
};

class NullObject : public Command
{
public:
    void execute() const;
};

// Smart Home
class Light
{
public:
    void turn_on();
    void turn_off();
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

#endif // COMMAND_H
