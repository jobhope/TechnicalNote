#include<algorithm>
#include<iostream>
#include<set>
#include<string>
#include<vector>

class Subject;

class Observer
{
public:
    virtual ~Observer() = default;
    virtual void Update(Subject& observable, std::string dataKey) = 0;
};

class Subject
{
public:
    virtual ~Subject() = 0;

    void Register(Observer& observer)
    {
        observerSet_.insert(&observer);
    }

    void Unregister(Observer& observer)
    {
        observerSet_.erase(&observer);
    }

    void Notify(std::string message)
    {
        for (auto& observer : observerSet_)
        {
            observer->Update(*this, message);
        }
    }

private:
    std::set<Observer*> observerSet_;
};

inline Subject::~Subject() = default;

class Creator : public Subject
{
public:
    explicit Creator(std::string name) : name_(std::move(name)) {}

    std::string GetName() const
    {
        return name_;
    }

    std::string GetMessage(std::string message)
    {
        return message;
    }

    void SetMessage(std::string message)
    {
        message = message;
    }
private:
    const std::string name_;
    const std::string message_;
};

class SubScriber : public Observer
{
public:
    explicit SubScriber(std::string name) : name_(std::move(name)) {}

    void Update(Subject& subject, std::string message) override
    {
        auto& creator = static_cast<Creator&>(subject);
        std::cout << name_ << " receive a message \"" << creator.GetMessage(message) << "\" from creator " << creator.GetName() << std::endl;
    }

    void Subscribe(Creator& creator)
    {
        creator.Register(*this);
    }

    void UnSubscribe(Creator& creator)
    {
        creator.Unregister(*this);
    }
private:
    std::string name_;
};

int main()
{
    // 크리에이터
    Creator creator1("Youtuber");

    // 구독자
    SubScriber user1("user_one"), user2("user_two"), user3("user_three");

    // 구독자가 구독을함
    user1.Subscribe(creator1);
    user2.Subscribe(creator1);
    user3.Subscribe(creator1);

    // 크리에이터가 새 동영상을 올렸다고 알린다.
    // 구독한 user1, user2, user3 모두 메시지를 받는다.
    creator1.Notify("New video has been uploaded.");

    // user1과 user2가 구독을 취소한다.
    user1.UnSubscribe(creator1);
    user2.UnSubscribe(creator1);

    std::cout << std::endl;

    // 크리에이터가 새 이미지를 올렸다고 알린다.
    // 구독한 user3는 메시지를 받는다.
    creator1.Notify("New image has been uploaded.");

    return 0;
}