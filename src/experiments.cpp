#include <iostream>
#include <memory>

#include <algorithm>
#include <array>

class BaseClass
{
public:
    BaseClass()
    {
        std::cout << "It is BaseClass" << std::endl;
    }

    virtual int b()
    {
        return 0;
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

std::function<int()> the_function_which_creates(const int number)
{
    return [=](){
        return number;
    };
}

std::function<std::shared_ptr<BaseClass>()> another_function_which_returns_base_class(std::shared_ptr<BaseClass> class_object){
    return [=]() {
        return class_object;
    };
}

int main()
{
    {
        std::unique_ptr<BaseClass> object(new DerrivedClass);
    }

    {
        // algorithms
        std::array<int, 8> foo = {3, 5, 7, 11, 13, 17, 19, 23};

        if (std::all_of(foo.begin(), foo.end(), [](int i)
                        { return i % 2; }))
        {
            std::cout << "All the elements are odd numbers. \n";
        }
        else
        {
            std::cout << "At least some elements are not odd. \n";
        }

        namespace crazy = std;
        crazy::cout << "It is crazy namespace" << std::endl;
    }

    {
        std::function<int()> my_function = the_function_which_creates(5);
        std::cout << "my_function returns " << my_function() << std::endl;
    }

    std::shared_ptr<BaseClass> base_class_pointer;
    {
        base_class_pointer = another_function_which_returns_base_class(std::make_shared<BaseClass>())();
    }

    std::cout << base_class_pointer->b() << std::endl;
    return 0;
}