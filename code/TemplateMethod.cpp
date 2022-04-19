#include<iostream>

class CoffeeMaker
{
public:
    // 자식 클래스에서 공통으로 사용하는 TEMPLATE METHOD
    void makeCoffee()
    {
        boilWater();
        putEspresso();
        putIce();
        putExtra();
    }

    // HOOK METHOD
    virtual void putExtra() = 0;

    void boilWater()
    {
        std::cout << "물을 끓인다" << std::endl;
    }

    void putEspresso()
    {
        std::cout << "에스프레소를 넣는다." << std::endl;
    }

    void putIce()
    {
        std::cout << "얼음을 넣는다." << std::endl;
    }
};

class LatteMaker : public CoffeeMaker
{
public:
    void putExtra() override
    {
        std::cout << "우유를 넣는다." << std::endl;
    }
};

class AmericanoMaker : public CoffeeMaker
{
public:
    void putExtra() override
    {
        std::cout << "시럽을 넣는다." << std::endl;
    }
};

int main()
{
    CoffeeMaker* latteMaker = new LatteMaker();
    latteMaker->makeCoffee();
    std::cout << std::endl;
    CoffeeMaker* americanoMaker = new AmericanoMaker();
    americanoMaker->makeCoffee();
    return 0;
}