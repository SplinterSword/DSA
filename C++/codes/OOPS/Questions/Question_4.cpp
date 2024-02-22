#include <iostream>
using namespace std;

class base
{
    public:
    virtual void display()=0;
    virtual void display(int a)=0;
};

class derived:public base
{
    public:
    void display()
    {
        cout<<"This is Display1() method of Derived Class\n";
    }
    void display(int a)
    {
        cout<<"This is Display2() method of Derived Class\n";
    }
};

int main()
{
    base *a=new derived;
    a->display();
    a->display(1);
    return 0;
}