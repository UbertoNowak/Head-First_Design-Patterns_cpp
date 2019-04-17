#include <iostream>
#include "factorymethod.h"

Pizzeria::~Pizzeria(){}

std::unique_ptr<Pizza> Pizzeria::orderPizza(PizzaType aType)
{
  auto pPizza = factoryMethod(aType);
  pPizza->preparation();
  pPizza->baking();
  pPizza->slicing();
  pPizza->packing();
  return pPizza;
}

std::unique_ptr<Pizza> ItalianPizzeria::factoryMethod(PizzaType aType)
{
    std::unique_ptr<Pizza> pPizza = nullptr;
    switch(aType)
    {
    case PizzaType::Cheese:
        pPizza = std::make_unique<ItalianCheesePizza>();
        break;
    case PizzaType::Peperoni:
        pPizza = std::make_unique<ItalianPepperoniPizza>();
        break;
    case PizzaType::Seefood:
        pPizza = std::make_unique<ItalianSeefoodPizza>();
        break;
    }
    return pPizza;
}

std::unique_ptr<Pizza> AmericanPizzeria::factoryMethod(PizzaType aType)
{
    std::unique_ptr<Pizza> pPizza = nullptr;
    switch(aType)
    {
    case PizzaType::Cheese:
        pPizza = std::make_unique<AmericanCheesePizza>();
        break;
    case PizzaType::Peperoni:
        pPizza = std::make_unique<AmericanPepperoniPizza>();
        break;
    case PizzaType::Seefood:
        pPizza = std::make_unique<AmericanSeefoodPizza>();
        break;
    }
    return pPizza;
}

Pizza::~Pizza()
{}

void Pizza::baking()
{
    std::cout<< "Baking." <<std::endl;
}

void Pizza::slicing()
{
    std::cout<< "Slicing." <<std::endl;
}

void Pizza::packing()
{
    std::cout<< "Packing." <<std::endl;
}

void ItalianCheesePizza::preparation()
{
    std::cout<< "Prepare italian cheese pizza." <<std::endl;
}

void ItalianPepperoniPizza::preparation()
{
    std::cout<< "Prepare italian pepperoni pizza." <<std::endl;
}

void ItalianSeefoodPizza::preparation()
{
    std::cout<< "Prepare italian seefood pizza." <<std::endl;
}

void AmericanCheesePizza::preparation()
{
    std::cout<< "Prepare american cheese pizza." <<std::endl;
}

void AmericanPepperoniPizza::preparation()
{
    std::cout<< "Prepare american pepperoni pizza." <<std::endl;
}

void AmericanSeefoodPizza::preparation()
{
    std::cout<< "Prepare american seefood pizza." <<std::endl;
}

int main()
{
    auto pItalianPizzeria = std::make_unique<ItalianPizzeria>();
    auto pAmericanPizzeria = std::make_unique<AmericanPizzeria>();

    auto pItalianPizza = pItalianPizzeria->orderPizza(PizzaType::Cheese);
    auto pAmericanPizza = pAmericanPizzeria->orderPizza(PizzaType::Peperoni);

    return 0;
}


