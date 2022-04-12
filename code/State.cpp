#include<iostream>

class State {
public:
    virtual int Do(int hp) = 0;
};

class DieState : public State
{
public:
    int Do(int hp) override
    {
        return 0;
    }
};

class WalkState : public State
{
public:
    int Do(int hp) override
    {
        return hp + 2;
    }
};

class RunState : public State
{
public:
    int Do(int hp) override
    {
        return hp + 10;
    }
};

class Human
{
public:
    Human(int hp) : healthPoint_(hp), state_(nullptr) {}
    void setState(State* state)
    {
        state_ = state;
    }
    int GetHealthPoint()
    {
        return healthPoint_;
    }
    void Request()
    {
        healthPoint_ = state_->Do(healthPoint_);
    }
private:
    int healthPoint_;
    State* state_;
};

int main()
{
    Human human(100);
    std::cout << human.GetHealthPoint() << std::endl;

    // Walk 상태로 바꾸고 요청한다.
    human.setState(new WalkState());
    human.Request();
    std::cout << human.GetHealthPoint() << std::endl;

    // Run 상태로 바꾸고 요청한다.
    human.setState(new RunState());
    human.Request();
    std::cout << human.GetHealthPoint() << std::endl;

    // Die 상태로 바꾸고 요청한다.
    human.setState(new DieState());
    human.Request();
    std::cout << human.GetHealthPoint() << std::endl;

    return 0;
}
