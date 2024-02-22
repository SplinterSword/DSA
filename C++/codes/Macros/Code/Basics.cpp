#include <iostream>
using namespace std;

//A piece for code that is replaced by the value of a macro
#define PI 3.14 //this is a macro
//this saves storage
//this value can't be changed and it does not take any storage

int main()
{
    double area=PI * 2 *2;
    cout<<area;
    return 0;
}