#ifndef STRATEGY_H
#define STRATEGY_H

class Flying
{
public:
    virtual ~Flying();
    virtual void fly() = 0;
};

class Wings : public Flying
{
public:
    void fly() override;
};

class IDoNotFly : public Flying
{
public:
    void fly() override;
};

class Sound
{
public:
    virtual ~Sound();
    virtual void quack() = 0;
};

class Quack : public Sound
{
public:
    void quack() override;
};

class DontQuack : public Sound
{
public:
    void quack() override;
};

class Squeal : public Sound
{
public:
    void quack() override;
};

class Duck
{
public:
    virtual ~Duck();
    void fly();
    void sound();
    virtual void display() = 0;
    void setSound(Sound* apSound);
    void setFlying(Flying* apFlying);
private:
    Sound* m_pSound;
    Flying* m_pFlying;
};

class WildDuck : public Duck
{
public:
    WildDuck();
    void display() override;
};

class RubberDuck : public Duck
{
public:
    RubberDuck();
    void display() override;
};

class DecoyDuck : public Duck
{
public:
    DecoyDuck();
    void display() override;
};

class WoodenDuck : public Duck
{
public:
    WoodenDuck();
    void display() override;
};

#endif // STRATEGY_H
