#include<iostream>
#include<memory>
#include<string>

class Drink
{
public:
    virtual ~Drink() = default;
    virtual std::string getName() const = 0;
};

class Coffee : public Drink
{
    std::string getName() const override
    {
        return "커피";
    }
};
class Coke : public Drink
{
    std::string getName() const override
    {
        return "콜라";
    }
};

class Cocoa : public Drink
{
    std::string getName() const override
    {
        return "코코아";
    }
};

enum class DrinkType
{
    Coffee,
    Coke,
    Cocoa
};

class DrinkFactory
{
public:
    virtual ~DrinkFactory() = default;
    virtual std::unique_ptr<Drink> Create() const = 0;
};

class CoffeeFactory : public DrinkFactory
{
public:
    std::unique_ptr<Drink> Create() const override
    {
        return std::make_unique<Coffee>();
    }
};

class CokeFactory : public DrinkFactory
{
public:
    std::unique_ptr<Drink> Create() const override
    {
        return std::make_unique<Coke>();
    }
};

class CocoaFactory : public DrinkFactory
{
public:
    std::unique_ptr<Drink> Create() const override
    {
        return std::make_unique<Cocoa>();
    }
};

class VendingMachine final
{
public:
    VendingMachine(std::unique_ptr<DrinkFactory>&& drinkFactory) : drinkFactory_(std::move(drinkFactory))
    {}

    void Create(std::unique_ptr<DrinkFactory>&& creator)
    {
        drinkFactory_ = std::move(creator);
    }

    void PrintDrinkName() const
    {
        std::cout << "Maked drink's name : " << drinkFactory_->Create()->getName() << std::endl;
        std::cout << std::endl;
    }

private:
    std::unique_ptr<DrinkFactory> drinkFactory_;
};

int main()
{
    VendingMachine vendingMachine(std::make_unique<CoffeeFactory>());

    std::cout << "==== Vending Machine Factory ====" << std::endl;
    vendingMachine.PrintDrinkName();

    vendingMachine.Create(std::make_unique<CokeFactory>());
    vendingMachine.PrintDrinkName();

    vendingMachine.Create(std::make_unique<CocoaFactory>());
    vendingMachine.PrintDrinkName();
    return 0;
}