#include<iostream>
#include<string>

class EnemyAttacker
{
public:
    virtual void fireWeapon() = 0;
    virtual void driveForward() = 0;
    virtual void assignDriver(std::string driverName) = 0;
};

class EnemyTank : public EnemyAttacker
{
public:
    void fireWeapon() override
    {
        int attackDamage = 10;
        std::cout << "Enemy Tank does " << attackDamage << " damage" << std::endl;
    }

    void driveForward() override
    {
        int movement = 5;
        std::cout << "Enemy Tank moves " << movement << " spaces" << std::endl;
    }

    void assignDriver(std::string driverName) override
    {
        std::cout << driverName << " is driving the tank" << std::endl;
    }
};


class EnemyRobot
{
public:
    void smashWithHands()
    {
        int attackDamage = 5;
        std::cout << "Enemy Robot causes " << attackDamage << " damage with its hands" << std::endl;
    }

    void walkForward()
    {
        int movement = 3;
        std::cout << "Enemy Robot walks forward " << movement << " spaces" << std::endl;
    }

    void reactToHuman(std::string driverName)
    {
        std::cout << "Enemy Robot tramps on " << driverName << std::endl;
    }
};

class EnemyRobotAdapter : public EnemyAttacker
{
public:
    std::unique_ptr<EnemyRobot> theRobot;

    EnemyRobotAdapter(std::unique_ptr<EnemyRobot>& newRobot) : theRobot(std::move(newRobot)) {}

    void fireWeapon() override
    {
        theRobot->smashWithHands();
    }

    void driveForward() override
    {
        theRobot->walkForward();
    }

    void assignDriver(std::string driverName) override
    {
        theRobot->reactToHuman(driverName);
    }
};

int main()
{
    auto tank = std::make_unique<EnemyTank>();

    auto robot = std::make_unique<EnemyRobot>();

    auto robotAdapter = std::make_unique<EnemyRobotAdapter>(robot);

    std::cout << "The Robot" << std::endl;
    robot->reactToHuman("Paul");
    robot->walkForward();
    robot->smashWithHands();

    std::cout << std::endl << "The Enemy Tank" << std::endl;
    tank->assignDriver("Frank");
    tank->driveForward();
    tank->fireWeapon();

    std::cout << std::endl << "The Robot with Adapter" << std::endl;
    // EnemyAttacker의 함수를 호출하지만 결과는 Robot의 각 함수를 호출한것과 같다.
    robotAdapter->assignDriver("Mark");
    robotAdapter->driveForward();
    robotAdapter->fireWeapon();

    return 0;
}