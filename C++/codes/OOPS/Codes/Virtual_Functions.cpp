#include <iostream>
using namespace std;

//Virtual function is used to perform late binding(binding of member functions to a object during runtime) and runtime polymorphism.
//Virtual function enables us to downcasting(upcasting is possible by default) with the help of pointers.

class base
{
    public:
    virtual void show() //This is how you create a virtual function
    {
        cout<<"This is Base Class\n";
    }
};

class derived:public base //Inheritance is necessary for virtual functions to work.
{
    public:
    void show() //member function in derived class which has the same name as base function.
    {
        cout<<"This is Derived Class\n";
    }
};
class c:public derived
{
    public:
    void show()
    {
        cout<<"This is c class\n";
    }
};

int main()
{
    base *b=new base;
    b->show();
    b=new derived; //late binding,
    b->show();
    delete b;
    return 0;
}