//Derived Class(Child)= the class that inherits from another class.
//Base Class(Parent)= the class begin inherited from.

#include <iostream>
using namespace std;

class base
{
    public: //Only Public and Protected data of a base class is inherited from the base class. Private data can't be inherited.
    void func()
    {
        cout<<"Inherited"<<endl;
    }
};

class derived : public base //This is the syntax for single inheritance of base class to derived class.
{
    //If rather that public base, It was private base then it will not be public for other objects or functions rather it becomes a private part of class derived.
};

int main()
{
    derived b;
    b.func(); // derived class using a function it inherits from base class.
    return 0;
}