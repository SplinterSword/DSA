#include <iostream>
#include <typeinfo> //header file used to find the datatype of variable
using namespace std;

//Templates allow us to do generic programming and allow us to try a code which will work for many datatypes.
//Allows us to use reusablility principle.

template <class T> class basic //this is how you use templates
{
    public:
    basic (T a) //here T is the placeholder datatype
    {
        cout<<"This template is used as a "<<typeid(a).name()<<" datatype\n"; //typeid(variable).name() is used to find the datatype of a variable.
    }
};

int main()
{
    basic <int> a(1);  //this is how you declare a template class where class_name<datatype>object_name is the syntax.
    basic <char> b('b');

    return 0;
}