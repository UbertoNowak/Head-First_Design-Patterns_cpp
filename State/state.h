#ifndef STATE_H
#define STATE_H

class State
{
public:
    State();
    virtual ~State();

    virtual void putCoin();
    virtual void returnCoin();
    virtual void twist();
    virtual void makeRubber();
};

class RubberSold : public State
{
public:
    void putCoin();
    void returnCoin();
    void twist();
    void makeRubber();
};

class EmptyMachine : public State
{
public:
    void putCoin();
    void returnCoin();
    void twist();
    void makeRubber();
};

class NoCoin : public State
{
public:
    void putCoin();
    void returnCoin();
    void twist();
    void makeRubber();
};

class CoinInside : public State
{
public:
    void putCoin();
    void returnCoin();
    void twist();
    void makeRubber();
};

class RubberMachine
{
public:
    RubberMachine(int number);

private:
    int mNumber;

    State* mpRubberSold;
    State* mpEmptyMachine;
    State* mpNoCoin;
    State* mpCoinInside;

    State* mpStateMachine;
};

#endif // STATE_H
