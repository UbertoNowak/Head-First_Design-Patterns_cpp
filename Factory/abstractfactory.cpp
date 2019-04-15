#include <iostream>
#include "abstractfactory.h"

AbstractFactory::~AbstractFactory()
{}

void ItalianIngredientsFactory::createDough()
{
    std::cout<< "Thin dough" <<std::endl;
}

void ItalianIngredientsFactory::createSauce()
{
    std::cout<< "Marinara sauce" <<std::endl;
}

void ItalianIngredientsFactory::createCheese()
{
    std::cout<< "Reggiano cheese" <<std::endl;
}

void AmericanIngredientsFactory::createDough()
{
    std::cout<< "Thick dough" <<std::endl;
}

void AmericanIngredientsFactory::createSauce()
{
    std::cout<< "Tomato sauce" <<std::endl;
}

void AmericanIngredientsFactory::createCheese()
{
    std::cout<< "Mozzarella cheese" <<std::endl;
}
