#include <iostream>
using namespace std;

class base
{
    public:
    virtual void fun()=0;
    base(int a,int b)
    {
        cout<<"Sum="<<a+b;
    }
};
class derived:public base
{
    public:
    derived(int a,int b):base(a,b)
    {}
    void fun(){}
};


int main()
{
    base *a=new derived(4,5);
    delete a;
    return 0;
}