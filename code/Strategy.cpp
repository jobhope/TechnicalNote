#include<iostream>

class SortInterface
{
public:
    virtual void Sort() = 0;
};

class BubbleSort : public SortInterface
{
public:
    void Sort() override
    {
        std::cout << "Bubble Sort" << std::endl;
    }
};

class MergeSort : public SortInterface
{
public:
    void Sort() override
    {
        std::cout << "Merge Sort" << std::endl;
    }
};

class QuickSort : public SortInterface
{
public:
    void Sort() override
    {
        std::cout << "Quick Sort" << std::endl;
    }
};

// Context
class SortManager
{
public:
    SortManager() : sortInterface_(nullptr) {}
    ~SortManager()
    {
        if (sortInterface_)
        {
            delete sortInterface_; 
        }
    }

    void Sort()
    {
        sortInterface_->Sort();
    }

    void SetInterface(SortInterface* interface_)
    {
        if (sortInterface_)
        {
            delete sortInterface_;
        }
        sortInterface_ = interface_;
    }
private:
    SortInterface* sortInterface_;
};

int main()
{
    SortManager manager;
    manager.SetInterface(new QuickSort);
    manager.Sort();

    manager.SetInterface(new MergeSort);
    manager.Sort();

    manager.SetInterface(new BubbleSort);
    manager.Sort();

    return 0;
}