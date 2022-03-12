#include <iostream>
#include <memory>

class BaseClass
{
public:
    BaseClass()
    {
        std::cout << "It is BaseClass" << std::endl;
    }

    virtual ~BaseClass()
    {
        std::cout << "It is ~BaseClass" << std::endl;
    }
};

class DerrivedClass : public BaseClass
{
public:
    DerrivedClass()
    {
        std::cout << "It is DerrivedClass" << std::endl;
    }

    virtual ~DerrivedClass()
    {
        std::cout << "It is ~DerrivedClass" << std::endl;
    }
};

int main()
{
    {
        std::unique_ptr<BaseClass> object(new DerrivedClass);
    }

    std::cout << "Hello world!" << std::endl;
    return 0;
}