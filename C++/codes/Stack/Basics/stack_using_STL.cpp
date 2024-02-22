// Stack is a data structure that follows LIFO (Last in First Out) algorithm.
#include <iostream>
#include <stack> // header file to include stl to use stack
using namespace std;

int main()
{
    stack<int> a;
    a.push(1); // include an element to the pop
    a.push(2);

    cout<<a.top()<<endl; //returns the last/top element of the stack

    a.pop(); // removes and returns the last element of the stack

    cout<<a.top()<<endl;

    if (a.empty())  //returns true if the stack is empty else returns false
    {
        cout<<"Empty\n";
    }
    else
    {
        cout<<"Not empty\n";
    }

    cout<<"Size: "<<a.size()<<endl; // returns the size of the stack
    return 0;
}