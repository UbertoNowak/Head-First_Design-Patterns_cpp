#include <iostream>
#include "simplefactory.h"

Pizza *SimpleFactory::createPizza(PizzaType aType)
{
    Pizza* pizza = nullptr;
    switch(aType)
    {
    case PizzaType::Cheese:
        pizza = new CheesePizza();
        break;
    case PizzaType::Peperoni:
        pizza = new PepperoniPizza();
        break;
    case PizzaType::Seefood:
        pizza = new SeefoodPizza();
        break;
    }
    return pizza;
}

Pizzeria::Pizzeria(SimpleFactory aFactory) : m_Factory(aFactory)
{}

Pizza* Pizzeria::orderPizza(PizzaType aType)
{
  Pizza* pPizza;
  pPizza = m_Factory.createPizza(aType);
  pPizza->preparation();
  pPizza->baking();
  pPizza->slicing();
  pPizza->packing();
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

void CheesePizza::preparation()
{
    std::cout<< "Prepare cheese pizza." <<std::endl;
}

void PepperoniPizza::preparation()
{
    std::cout<< "Prepare pepperoni pizza." <<std::endl;
}

void SeefoodPizza::preparation()
{
    std::cout<< "Prepare seefood pizza." <<std::endl;
}

int main()
{
    Pizza* pPizza = nullptr;
    SimpleFactory factory;
    Pizzeria italianPizzeria(factory);
    pPizza = italianPizzeria.orderPizza(PizzaType::Peperoni);
    delete  pPizza;
    return 0;
}
