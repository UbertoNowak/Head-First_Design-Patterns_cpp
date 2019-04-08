#include <iostream>
#include "strategy.h"

void Wings::fly()
{
    std::cout << "I can fly !" std::endl;
}

void IDoNotFly::fly()
{
    std::cout << "I can't fly, because I don't have wings!" << std::endl;
}

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
