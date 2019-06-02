#ifndef STATE_H
#define STATE_H

#include <memory>

class State
{
public:
    virtual ~State();

    virtual void putCoin() = 0;
    virtual void returnCoin() = 0;
    virtual void twist() = 0;
    virtual void makeRubber() = 0;
};

class RubberSold : public State
{
public:
    void putCoin(){};
    void returnCoin(){};
    void twist(){};
    void makeRubber(){};
};

class EmptyMachine : public State
{
public:
    void putCoin(){};
    void returnCoin(){};
    void twist(){};
    void makeRubber(){};
};

class NoCoin : public State
{
public:
    void putCoin(){};
    void returnCoin(){};
    void twist(){};
    void makeRubber(){};
};

class CoinInside : public State
{
public:
    void putCoin(){};
    void returnCoin(){};
    void twist(){};
    void makeRubber(){};
};

class RubberMachine
{
public:
    RubberMachine(int number);

private:
    int mNumber;

    std::shared_ptr<State> mpRubberSold;
    std::shared_ptr<State> mpEmptyMachine;
    std::shared_ptr<State> mpNoCoin;
    std::shared_ptr<State> mpCoinInside;

    std::shared_ptr<State> mpStateMachine;
};

#endif // STATE_H
