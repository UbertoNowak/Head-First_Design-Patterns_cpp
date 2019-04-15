#include <iostream>
#include <memory>
#include "factorymethod.h"

Pizzeria::~Pizzeria(){}

Pizza* Pizzeria::orderPizza(PizzaType aType)
{
  Pizza* pPizza = factoryMethod(aType);
  pPizza->preparation();
  pPizza->baking();
  pPizza->slicing();
  pPizza->packing();
  return pPizza;
}

Pizza *ItalianPizzeria::factoryMethod(PizzaType aType)
{
    Pizza* pizza = nullptr;
    switch(aType)
    {
    case PizzaType::Cheese:
        pizza = new ItalianCheesePizza();
        break;
    case PizzaType::Peperoni:
        pizza = new ItalianPepperoniPizza();
        break;
    case PizzaType::Seefood:
        pizza = new ItalianSeefoodPizza();
        break;
    }
    return pizza;
}

Pizza *AmericanPizzeria::factoryMethod(PizzaType aType)
{
    Pizza* pizza = nullptr;
    switch(aType)
    {
    case PizzaType::Cheese:
        pizza = new AmericanCheesePizza();
        break;
    case PizzaType::Peperoni:
        pizza = new AmericanPepperoniPizza();
        break;
    case PizzaType::Seefood:
        pizza = new AmericanSeefoodPizza();
        break;
    }
    return pizza;
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
    std::unique_ptr<ItalianPizzeria> pItalianPizzeria(new ItalianPizzeria());
    std::unique_ptr<AmericanPizzeria> pAmericanPizzeria(new AmericanPizzeria());

    std::unique_ptr<Pizza> pItalianPizza(pItalianPizzeria->orderPizza(PizzaType::Cheese));
    std::unique_ptr<Pizza> pAmericanPizza(pAmericanPizzeria->orderPizza(PizzaType::Peperoni));

    return 0;
}


