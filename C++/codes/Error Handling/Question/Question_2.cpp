#include <iostream>
using namespace std;

int main()
{
    int age;
    cout<<"Enter the age: ";
    cin>>age;
    try
    {
        if (age<18)
        {
            throw age;
        }
        else
        {
            cout<<"Access granted - you are old enough\n";
        }
    }
    catch(int a)
    {
        cout<<"Access denied - You must be at least 18 years old.\n";
        cout<<"Age is: "<<a<<endl; 
    }
    
    return 0;
}