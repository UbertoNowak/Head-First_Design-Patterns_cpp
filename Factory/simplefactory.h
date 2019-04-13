#ifndef SIMPLEFACTORY_H
#define SIMPLEFACTORY_H

class Pizza;

enum class PizzaType
{
    Cheese,
    Peperoni,
    Seefood
};

class SimpleFactory
{
public:
    static Pizza* createPizza(PizzaType aType);
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

class CheesePizza : public Pizza
{
public:
    void preparation();
};

class PepperoniPizza : public Pizza
{
public:
    void preparation();
};

class SeefoodPizza : public Pizza
{
public:
    void preparation();
};

class Pizzeria
{
public:
    Pizzeria(SimpleFactory aFactory);
    Pizza* orderPizza(PizzaType aType);
private:
    SimpleFactory m_Factory;
};

#endif // SIMPLEFACTORY_H
