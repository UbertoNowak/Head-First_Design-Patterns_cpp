#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

class AbstractFactory
{
public:
    virtual ~AbstractFactory();
    virtual void createDough() = 0;
    virtual void createSauce() = 0;
    virtual void createCheese() = 0;
};

class ItalianIngredientsFactory : public AbstractFactory
{
public:
    void createDough();
    void createSauce();
    void createCheese();
};

class AmericanIngredientsFactory : public AbstractFactory
{
public:
    void createDough();
    void createSauce();
    void createCheese();
};

#endif // ABSTRACTFACTORY_H
