#include "state.h"

State::~State()
{}

RubberMachine::RubberMachine(int number) : mNumber(number)
{
    mpRubberSold = std::make_shared<RubberSold>();
    mpEmptyMachine = std::make_shared<EmptyMachine>();
    mpNoCoin = std::make_shared<NoCoin>();
    mpCoinInside = std::make_shared<CoinInside>();

    mpStateMachine = mpNoCoin;
}

int main()
{
    return 0;
}


