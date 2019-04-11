#ifndef SIMPLEFACTORY_H
#define SIMPLEFACTORY_H

class Pizzeria
{
public:
    void zamowPizze();
};


class SimpleFactory
{
public:
    static void createPizza();
};

class Pizza
{
public:
    void przygotowanie();
    void pieczenie();
    void krojenie();
    void pakowanie();
};

class PizzaSerowa : public Pizza
{

};

#endif // SIMPLEFACTORY_H
