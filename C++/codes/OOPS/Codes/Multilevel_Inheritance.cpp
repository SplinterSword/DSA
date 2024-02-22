//Derived Class(Child)= the class that inherits from another class.
//Base Class(Parent)= the class begin inherited from.

#include <iostream>
using namespace std;

class A
{
    public: //Only Public and Protected data of a base class is inherited from the base class. Private data can't be inherited.
    void funcA()
    {
        cout<<"A"<<endl;
    }
};

class B : public A
{
    public: //Only Public and Protected data of a base class is inherited from the base class. Private data can't be inherited.
    void funcB()
    {
        cout<<"B"<<endl;
    }
};

class C : public B //This is the syntax for Multilevel inheritance of base class to derived class. It got members of both class A and class B.
{
    public:
};

int main()
{
    C b;
    b.funcA(); // derived class using a function it inherits from A class which is inherited from B class.
    b.funcB(); // derived class using a function it inherits from B class.
    return 0;
}