#include <iostream>
using namespace std;


//inline function works with only when it has 1-3 lines and works like Macros
inline int getMax(int &a, int &b)
{
    return (a > b ? a : b);
}
int main()
{
    int a = 1, b = 2;
    cout << getMax(a, b);
    return 0;
}