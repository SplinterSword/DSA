#include <iostream>
using namespace std;

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