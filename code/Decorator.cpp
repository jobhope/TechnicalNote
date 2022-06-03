#include<iostream>
#include<memory>
#include<string>

class Pizza
{
public:
    virtual std::string getDescription() = 0;
    virtual double getCost() = 0;
};

class PlainPizza : public Pizza
{
    std::string getDescription() override
    {
        return "얇은 도우";
    }

    double getCost() override
    {
        return 4.00;
    }
};

class ToppingDecorator : public Pizza
{
public:
    Pizza* tempPizza;

    ToppingDecorator(Pizza* newPizza)
    {
        tempPizza = newPizza;
    }

    std::string getDescription() override
    {
        return tempPizza->getDescription();
    }

    double getCost() override
    {
        return tempPizza->getCost();
    }
};

class Mozzarella : public ToppingDecorator
{
public:
    Mozzarella(Pizza* newPizza) : ToppingDecorator(newPizza)
    {
        std::cout << "도우 추가" << std::endl;
        std::cout << "모짜렐라 치즈 추가" << std::endl;
    }

    std::string getDescription() override
    {
        return tempPizza->getDescription() + ", 모짜렐라 치즈";
    }

    double getCost() override
    {
        return tempPizza->getCost() + .50;
    }
};

class TomatoSauce : public ToppingDecorator
{
public:
    TomatoSauce(Pizza* newPizza) : ToppingDecorator(newPizza)
    {
        std::cout << "토마토 소스 추가" << std::endl;
    }

    std::string getDescription() override
    {
        return tempPizza->getDescription() + ", 토마토 소스";
    }

    double getCost() override
    {
        return tempPizza->getCost() + .35;
    }
};

int main()
{
    auto basicPizza = std::unique_ptr<Pizza>(new TomatoSauce(new Mozzarella(new PlainPizza)));
    std::cout << "재료 : " << basicPizza->getDescription() << std::endl;
    std::cout << "가격 : " << basicPizza->getCost() << std::endl;
    // 도우 추가
    // 모짜렐라 치즈 추가
    // 토마토 소스 추가
    // 재료 : 얇은 도우, 모짜렐라 치즈, 토마토 소스
    // 가격 : 4.85
    return 0;
}