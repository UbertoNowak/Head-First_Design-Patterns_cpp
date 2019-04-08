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
    void fly();
    void sound();
    void display();
private:
    Sound* m_pSound;
    Flying* m_pFlying;
};

#endif // STRATEGY_H
