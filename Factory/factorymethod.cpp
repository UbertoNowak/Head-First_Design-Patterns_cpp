#include <iostream>
#include "factorymethod.h"
#include "abstractfactory.h"

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
    auto factory = std::make_unique<ItalianIngredientsFactory>();
    std::unique_ptr<Pizza> pPizza = nullptr;
    switch(aType)
    {
    case PizzaType::Cheese:
        pPizza = std::make_unique<ItalianCheesePizza>(factory.get());
        break;
    case PizzaType::Peperoni:
        pPizza = std::make_unique<ItalianPepperoniPizza>(factory.get());
        break;
    case PizzaType::Seefood:
        pPizza = std::make_unique<ItalianSeefoodPizza>(factory.get());
        break;
    }
    return pPizza;
}

std::unique_ptr<Pizza> AmericanPizzeria::factoryMethod(PizzaType aType)
{
    auto factory = std::make_unique<AmericanIngredientsFactory>();
    std::unique_ptr<Pizza> pPizza = nullptr;
    switch(aType)
    {
    case PizzaType::Cheese:
        pPizza = std::make_unique<AmericanCheesePizza>(factory.get());
        break;
    case PizzaType::Peperoni:
        pPizza = std::make_unique<AmericanPepperoniPizza>(factory.get());
        break;
    case PizzaType::Seefood:
        pPizza = std::make_unique<AmericanSeefoodPizza>(factory.get());
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

ItalianCheesePizza::ItalianCheesePizza(AbstractFactory *pFactory) : m_pFactory(pFactory)
{}

void ItalianCheesePizza::preparation()
{
    std::cout<< "Prepare italian cheese pizza." <<std::endl;
    m_pFactory->createDough();
    m_pFactory->createSauce();
    m_pFactory->createCheese();
}

ItalianPepperoniPizza::ItalianPepperoniPizza(AbstractFactory *pFactory) : m_pFactory(pFactory)
{}

void ItalianPepperoniPizza::preparation()
{
    std::cout<< "Prepare italian pepperoni pizza." <<std::endl;
    m_pFactory->createDough();
    m_pFactory->createSauce();
    m_pFactory->createCheese();
}

ItalianSeefoodPizza::ItalianSeefoodPizza(AbstractFactory *pFactory) : m_pFactory(pFactory)
{}

void ItalianSeefoodPizza::preparation()
{
    std::cout<< "Prepare italian seefood pizza." <<std::endl;
    m_pFactory->createDough();
    m_pFactory->createSauce();
    m_pFactory->createCheese();
}

AmericanCheesePizza::AmericanCheesePizza(AbstractFactory *pFactory) : m_pFactory(pFactory)
{}

void AmericanCheesePizza::preparation()
{
    std::cout<< "Prepare american cheese pizza." <<std::endl;
    m_pFactory->createDough();
    m_pFactory->createSauce();
    m_pFactory->createCheese();
}

AmericanPepperoniPizza::AmericanPepperoniPizza(AbstractFactory *pFactory) : m_pFactory(pFactory)
{}

void AmericanPepperoniPizza::preparation()
{
    std::cout<< "Prepare american pepperoni pizza." <<std::endl;
    m_pFactory->createDough();
    m_pFactory->createSauce();
    m_pFactory->createCheese();
}

AmericanSeefoodPizza::AmericanSeefoodPizza(AbstractFactory *pFactory) : m_pFactory(pFactory)
{}

void AmericanSeefoodPizza::preparation()
{
    std::cout<< "Prepare american seefood pizza." <<std::endl;
    m_pFactory->createDough();
    m_pFactory->createSauce();
    m_pFactory->createCheese();
}

int main()
{
    auto pItalianPizzeria = std::make_unique<ItalianPizzeria>();
    auto pAmericanPizzeria = std::make_unique<AmericanPizzeria>();

    auto pItalianPizza = pItalianPizzeria->orderPizza(PizzaType::Cheese);
    auto pAmericanPizza = pAmericanPizzeria->orderPizza(PizzaType::Peperoni);

    return 0;
}


