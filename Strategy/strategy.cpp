#include <iostream>
#include "strategy.h"

Flying::~Flying()
{}

void Wings::fly()
{
    std::cout << "I can fly !" << std::endl;
}

void IDoNotFly::fly()
{
    std::cout << "I can't fly, because I don't have wings!" << std::endl;
}

Sound::~Sound()
{}

void Quack::quack()
{
    std::cout << "Quack !" << std::endl;
}

void DontQuack::quack()
{
    std::cout << "Don't quack !" << std::endl;
}

void Squeal::quack()
{
    std::cout << "Squeal !" << std::endl;
}

Duck::~Duck()
{
    delete m_pFlying;
    delete m_pSound;
}

void Duck::fly()
{
    m_pFlying->fly();
}

void Duck::sound()
{
    m_pSound->quack();
}

void Duck::setSound(Sound *apSound)
{
    m_pSound = apSound;
}

void Duck::setFlying(Flying *apFlying)
{
    m_pFlying = apFlying;
}

WildDuck::WildDuck()
{
    setFlying(new Wings());
    setSound(new Quack());
}

void WildDuck::display()
{
    std::cout << "Wild Duck" << std::endl;
}

RubberDuck::RubberDuck()
{
    setFlying(new IDoNotFly());
    setSound(new Squeal());
}

void RubberDuck::display()
{
    std::cout << "Rubber Duck" << std::endl;
}

DecoyDuck::DecoyDuck()
{
    setFlying(new IDoNotFly());
    setSound(new Quack());
}

void DecoyDuck::display()
{
    std::cout << "Decoy Duck" << std::endl;
}

WoodenDuck::WoodenDuck()
{
    setFlying(new IDoNotFly());
    setSound(new DontQuack());
}

void WoodenDuck::display()
{
    std::cout << "Wooden Duck" << std::endl;
}

int main()
{
    WildDuck* p_Duck = new WildDuck();
    p_Duck->display();
    p_Duck->fly();
    p_Duck->sound();
    delete p_Duck;

    DecoyDuck* p_dDuck = new DecoyDuck();
    p_dDuck->display();
    p_dDuck->fly();
    p_dDuck->sound();
    delete p_dDuck;

    RubberDuck* p_rDuck = new RubberDuck();
    p_rDuck->display();
    p_rDuck->fly();
    p_rDuck->sound();
    delete p_rDuck;

    WoodenDuck* p_wDuck = new WoodenDuck();
    p_wDuck->display();
    p_wDuck->fly();
    p_wDuck->sound();
    delete p_wDuck;

    return 0;
}
