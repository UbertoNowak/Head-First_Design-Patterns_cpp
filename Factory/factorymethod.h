#ifndef FACTORYMETHOD_H
#define FACTORYMETHOD_H

#include <memory>

class AbstractFactory;

enum class PizzaType
{
    Cheese,
    Peperoni,
    Seefood
};

class Pizza
{
public:
    virtual ~Pizza();
    virtual void preparation() = 0;
    void baking();
    void slicing();
    void packing();
};

class ItalianCheesePizza : public Pizza
{
public:
    ItalianCheesePizza(AbstractFactory* pFactory);
    void preparation();
private:
    AbstractFactory* m_pFactory;
};

class ItalianPepperoniPizza : public Pizza
{
public:
    ItalianPepperoniPizza(AbstractFactory* pFactory);
    void preparation();
private:
    AbstractFactory* m_pFactory;
};

class ItalianSeefoodPizza : public Pizza
{
public:
    ItalianSeefoodPizza(AbstractFactory* pFactory);
    void preparation();
private:
    AbstractFactory* m_pFactory;
};

class AmericanCheesePizza : public Pizza
{
public:
    AmericanCheesePizza(AbstractFactory* pFactory);
    void preparation();
private:
    AbstractFactory* m_pFactory;
};

class AmericanPepperoniPizza : public Pizza
{
public:
    AmericanPepperoniPizza(AbstractFactory* pFactory);
    void preparation();
private:
    AbstractFactory* m_pFactory;
};

class AmericanSeefoodPizza : public Pizza
{
public:
    AmericanSeefoodPizza(AbstractFactory* pFactory);
    void preparation();
private:
    AbstractFactory* m_pFactory;
};

class Pizzeria
{
public:
    virtual ~Pizzeria();
    std::unique_ptr<Pizza> orderPizza(PizzaType aType);
private:
    virtual std::unique_ptr<Pizza> factoryMethod(PizzaType aType) = 0;
};

class ItalianPizzeria : public Pizzeria
{
    std::unique_ptr<Pizza> factoryMethod(PizzaType aType);
};

class AmericanPizzeria : public Pizzeria
{
    std::unique_ptr<Pizza> factoryMethod(PizzaType aType);
};

#endif // FACTORYMETHOD_H
