#include <iostream>
#include <typeinfo>
using namespace std;

template <class T1=int,class T2=char> //this is how you use default datatypes parameters in templates
class default_parameters
{
    public:
    default_parameters(T1 a,T2 b)
    {
        cout<<"This class is used for datatypes "<<typeid(a).name()<<" and "<<typeid(b).name()<<endl;
    }
};

int main()
{
    default_parameters<int,float> a(1,1.2);
    default_parameters<char,double> b('a',5.6666);
    default_parameters<> c(1,'a'); //This is how you declare default parametes templates and make sure you use "<>" to declare it as it is a template class. 
    return 0;
}