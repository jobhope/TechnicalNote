class Singleton
{
public:
    static Singleton& instance()
    {
        // 객체를 사용할때까지 초기화를 미룬다.
        if (instance_ == nullptr)
        {
            instance_ = new Singleton();
        }
        return *instance_;
    }
    Singleton(Singleton const&) = delete;
    Singleton& operator=(Singleton const&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton& operator=(Singleton&&) = delete;

private:
    Singleton() = default;
    static Singleton* instance_;
};

class Singleton
{
public:
    static Singleton& instance()
    {
        static Singleton* instance = new Singleton();
        return *instance;
    }
    Singleton(Singleton const&) = delete;
    Singleton& operator=(Singleton const&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton& operator=(Singleton&&) = delete;
private:
    Singleton() = default;
};