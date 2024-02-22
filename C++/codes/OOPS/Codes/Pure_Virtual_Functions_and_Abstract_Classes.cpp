#include <iostream>
using namespace std;

//Pure virtual function are the functions which is used to give structure to the base class.
//Abstract class is a class from which other classes are derived from. Abstract class is a class which as atleast one pure virtual function.
//Both together are used to give design to a program which is used in large scale programs.
//Abstract classes can have constructors,destructors and other non virtual functions.

class base
{
    public:
    virtual void show()=0; //to make a pure virtual function just initialise virtual function with 0;
};

void base::show() //pure virtual functions always defined outside the class by using scope resolution(::).
{
    cout<<"This is base class\n";
}
class derived:public base
{
    public:
    void show()
    {
        cout<<"This is derived class\n";
    }
};

int main()
{
    base *b=new derived;
    b->show();
    return 0;
}