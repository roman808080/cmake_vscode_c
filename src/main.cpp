#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
class LinkedListNode
{
public:
    int val;
    LinkedListNode *next;

    LinkedListNode(int node_value)
    {
        val = node_value;
        next = NULL;
    }
};

LinkedListNode *_insert_node_into_singlylinkedlist(LinkedListNode *head, int val)
{
    if (head == NULL)
    {
        head = new LinkedListNode(val);
    }
    else
    {
        LinkedListNode *end = head;
        while (end->next != NULL)
        {
            end = end->next;
        }
        LinkedListNode *node = new LinkedListNode(val);
        end->next = node;
    }
    return head;
}

/*
For your reference:
LinkedListNode {
    int val;
    LinkedListNode *next;
};
*/

void removeAll(int val, LinkedListNode **list)
{
    LinkedListNode *start = *list;

    while (start != NULL)
    {
        if (start->val == val)
        {

            LinkedListNode *temp = start;
            start = start->next;
            delete temp;
        }
        else
        {
            break;
        }
    }

    *list = start;
    LinkedListNode *previous = start;

    if (start == NULL)
    {
        return;
    }
    LinkedListNode *current = start->next;

    while (current != NULL)
    {
        if (current->val == val)
        {
            LinkedListNode *temp = current;
            previous->next = current->next;

            current = current->next;
            delete temp;
        }
        else
        {
            previous = current;
            current = current->next;
        }
    }
}

void start()
{
    int _val;
    cin >> _val;

    int _list_size;
    int _list_item;
    LinkedListNode *_list = NULL;
    cin >> _list_size;
    int _list_i;
    for (_list_i = 0; _list_i < _list_size; _list_i++)
    {
        cin >> _list_item;
        _list = _insert_node_into_singlylinkedlist(_list, _list_item);
    }

    removeAll(_val, &_list);

    LinkedListNode *_current = _list;
    while (_current != NULL)
    {
        cout << _current->val << " ";
        _current = _current->next;
    }
}

char *getChar(int i)
{
    if (i < 3)
    {
        return nullptr;
    }
    return new char('c');
}

int vectorFunction()
{
    std::vector<char> firstVector{'v', 'e', 'c'};
    std::vector<char> secondVector(firstVector);
    std::vector<char> thirdVector{'r', 'e', 'c'};

    char *firstPointer = &firstVector[0];
    char *secondPointer = &secondVector[0];
    char *thirdPointer = &thirdVector[0];

    char *firstPointerData = firstVector.data();
    char *secondPointerData = secondVector.data();
    char *thirdPointerData = thirdVector.data();

    secondVector[1] = 'f';
    char *anotherSecondPointer = &secondVector[0];

    std::vector<char> forthVector(std::move(firstVector));

    std::vector<char> fifthVector(11);

    char *character = nullptr;
    int i = 0;
    while ((character = getChar(i)) == nullptr)
    {
        //
        ++i;
    }

    return 0;
}

// #include <string>
// #include <iostream>
// using namespace std;

// class MyException{};
// class Dummy
// {
//     public:
//     Dummy(string s) : MyName(s) { PrintMsg("Created Dummy:"); }
//     Dummy(const Dummy& other) : MyName(other.MyName){ PrintMsg("Copy created Dummy:"); }
//     ~Dummy(){ PrintMsg("Destroyed Dummy:"); }
//     void PrintMsg(string s) { cout << s  << MyName <<  endl; }
//     string MyName;
//     int level;
// };

// void C(Dummy d, int i)
// {
//     cout << "Entering FunctionC" << endl;
//     d.MyName = " C";
//     throw MyException();

//     cout << "Exiting FunctionC" << endl;
// }

// void B(Dummy d, int i)
// {
//     cout << "Entering FunctionB" << endl;
//     d.MyName = "B";
//     C(d, i + 1);
//     cout << "Exiting FunctionB" << endl;
// }

// void A(Dummy d, int i)
// {
//     cout << "Entering FunctionA" << endl;
//     d.MyName = " A" ;
//   //  Dummy* pd = new Dummy("new Dummy"); //Not exception safe!!!
//     B(d, i + 1);
//  //   delete pd;
//     cout << "Exiting FunctionA" << endl;
// }

// int main()
// {
//     cout << "Entering main" << endl;
//     try
//     {
//         Dummy d(" M");
//         A(d,1);
//     }
//     catch (MyException& e)
//     {
//         cout << "Caught an exception of type: " << typeid(e).name() << endl;
//     }

//     cout << "Exiting main." << endl;
// }

// struct BaseException {
//     virtual const char* what() const { return "BaseException"; }
//     virtual ~BaseException() {}
// };

// struct DerivedException : BaseException {
//     // "virtual" keyword is optional here
//     virtual const char* what() const { return "DerivedException"; }
// };

// int main(int argc, char** argv) {
//     try {
//         try {
//             throw DerivedException();
//         } catch (const BaseException& e) {
//             std::cout << "First catch block: " << e.what() << std::endl;
//             // Output ==> First catch block: DerivedException

//             throw e; // This changes the exception to BaseException
//                      // instead of the original DerivedException!
//         }
//     } catch (const BaseException& e) {
//         std::cout << "Second catch block: " << e.what() << std::endl;
//         // Output ==> Second catch block: BaseException
//     }
//     return 0;
// }

// https://riptutorial.com/cplusplus/example/9212/best-practice--throw-by-value--catch-by-const-reference
// https://stackoverflow.com/questions/41174167/c-exception-in-destructor
// https://stackoverflow.com/questions/44191626/undefined-vs-unspecified-vs-implementation-defined-behavior
// https://team-coder.com/solid-principles/

class BaseInterface
{
};

template <typename T>
class Base: public BaseInterface
{
public:
    void fun()
    {
        T &derived = static_cast<T &>(*this);
        derived.hello();
    }

private:
    Base(){};
    friend T;
};

class Derived : public Base<Derived>
{
public:
    void hello()
    {
        std::cout << "hello" << std::endl;
    }
};

class AnotherDerived : public Base<AnotherDerived>
{
public:
    void hello()
    {
        std::cout << "hello" << std::endl;
    }
};


int main()
{
    std::vector<BaseInterface> objects;
    objects.push_back(Derived());
    objects.push_back(AnotherDerived());

    for (const auto& element: objects)
    {
        // element.fun();
    }
    return 0;
}

// https://wandbox.org/permlink/YOwEetfIRfaafmY6