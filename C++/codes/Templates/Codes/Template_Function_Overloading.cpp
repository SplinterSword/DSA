#include <iostream>
#include <typeinfo>
using namespace std;

void func (int a)
{
    cout<<"I am int func() "<<a<<endl;
}

template <class t1>
void func(t1 a)
{
    cout<<"I am templatised func() "<<a<<endl;
}

int main()
{
    func(5); //Exact match takes the hightest priority.
    func('a');
    return 0;
}