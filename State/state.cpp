#include "state.h"

State::State()
{

}

RubberMachine::RubberMachine(int number) : mNumber(number)
{
    mpRubberSold = new RubberSold();
    mpEmptyMachine = new EmptyMachine();
    mpNoCoin = new NoCoin();
    mpCoinInside = new CoinInside();

    mpStateMachine = mpNoCoin;
}
