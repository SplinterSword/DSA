//Derived Class(Child)= the class that inherits from another class.
//Base Class(Parent)= the class begin inherited from.

#include <iostream>
using namespace std;

class base_1
{
    public: //Only Public and Protected data of a base class is inherited from the base class. Private data can't be inherited.
    void funcA()
    {
        cout<<"A"<<endl;
    }
};

class base_2
{
    public: //Only Public and Protected data of a base class is inherited from the base class. Private data can't be inherited.
    void funcB()
    {
        cout<<"B"<<endl;
    }
};

class derived : public base_1, public base_2 //This is the syntax for Multiple inheritance of base class to derived class.
{
    public:
};

int main()
{
    derived b;
    b.funcA(); // derived class using a function it inherits from base_1 class.
    b.funcB(); // derived class using a function it inherits from base_2 class.
    return 0;
}