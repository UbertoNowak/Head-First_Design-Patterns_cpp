#include <iostream>
#include "templateMethod.h"

DrinkWithCaffeine::~DrinkWithCaffeine(){}

void DrinkWithCaffeine::recipe()
{
    boilingWater();
    pourIntoACup();
    brewing();
    additives();
}

void DrinkWithCaffeine::boilingWater()
{
    std::cout << "  Boilng water." << std::endl;
}

void DrinkWithCaffeine::pourIntoACup()
{
    std::cout << "  Pour into a cup." << std::endl;
}

void Coffee::brewing()
{
    std::cout << "  Brewing coffee." << std::endl;
}

void Coffee::additives()
{
    std::cout<< "  Add suger and milk." << std::endl;
}

void Tea::brewing()
{
    std::cout<< "  Brewing tea." << std::endl;
}

void Tea::additives()
{
    std::cout<< "  Add lemon." << std::endl;
}

int main()
{
    Tea* tea = new Tea();
    Coffee* coffee = new Coffee();

    std::cout<< "Create delicious tea:" << std::endl;
    tea->recipe();

    std::cout<< "Create delicious coffee:" << std::endl;
    coffee->recipe();

    return 0;
}
