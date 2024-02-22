#include <iostream>
#include <typeinfo>
using namespace std;

//Templates for functions
template <class t1>
void swapp(t1 *a,t1 *b)
{
    t1 temp= *a;
    *a=*b;
    *b=temp;
}

int main()
{
    int x=5,y=7;
    swapp(&x,&y);
    cout<<x<<" "<<y<<endl;
    float a=5.2,b=7.6;
    swapp(&a,&b);
    cout<<a<<" "<<b<<endl;
    return 0;
}