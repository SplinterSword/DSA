#include <iostream>
using namespace std;

template <class T>
void calculator(T a, T b)
{
    cout<<"Enter 1 for addition\nEnter 2 for subtraction\nEnter 3 for multiplication\nEnter 4 for division\nEnter your choice: ";
    jump:
        int n;
        cin>>n;
    switch(n)
    {
        case 1:
            cout<<"Addition:"<<a+b<<endl;
            break;
        case 2:
            cout<<"Subtraction:"<<a-b<<endl;
            break;
        case 3:
            cout<<"Multiplication:"<<a*b<<endl;
            break;
        case 4:
            cout<<"Division:"<<a/b<<endl;
            break;
        default:
            cout<<"Enter a valid input.\n";
            goto jump;
            break;
    }
}

int main()
{
    calculator(1,2);
    calculator(2.5,2.5);
    return 0;
}