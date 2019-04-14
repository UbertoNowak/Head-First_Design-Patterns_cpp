#ifndef FACTORYMETHOD_H
#define FACTORYMETHOD_H

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
    void preparation();
};

class ItalianPepperoniPizza : public Pizza
{
public:
    void preparation();
};

class ItalianSeefoodPizza : public Pizza
{
public:
    void preparation();
};

class AmericanCheesePizza : public Pizza
{
public:
    void preparation();
};

class AmericanPepperoniPizza : public Pizza
{
public:
    void preparation();
};

class AmericanSeefoodPizza : public Pizza
{
public:
    void preparation();
};

class Pizzeria
{
public:
    virtual ~Pizzeria();
    Pizza* orderPizza(PizzaType aType);
private:
    virtual Pizza* factoryMethod(PizzaType aType) = 0;
};

class ItalianPizzeria : public Pizzeria
{
    Pizza *factoryMethod(PizzaType aType);
};

class AmericanPizzeria : public Pizzeria
{
    Pizza* factoryMethod(PizzaType aType);
};

#endif // FACTORYMETHOD_H
