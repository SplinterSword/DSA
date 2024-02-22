#include <iostream>
#include <typeinfo>
using namespace std;

template <class T1,class T2> //this is how you use multiple datatypes parameters in templates
class multiple_parameters
{
    public:
    multiple_parameters(T1 a,T2 b)
    {
        cout<<"This class is used for datatypes "<<typeid(a).name()<<" and "<<typeid(b).name()<<endl;
    }
};

int main()
{
    multiple_parameters<int,float> a(1,1.2);
    multiple_parameters<char,double> b('a',5.6666);
    return 0;
}