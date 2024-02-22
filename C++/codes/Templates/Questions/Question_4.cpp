#include <iostream>
using namespace std;

template <class T>
T maximum(T a,T b)
{
    return a>b?a:b;
}
template <class T>
T minimum(T a,T b)
{
    return a<b?a:b;
}

int main()
{
    cout<<maximum(1,2)<<endl;
    cout<<minimum(2.2,3.2)<<endl;
    return 0;
}