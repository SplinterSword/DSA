#include <iostream>
using namespace std;

int main(){
    
    int a=10;
    int* p=&a;
    int** q=&p; //"**" is used to do double referencing, to point to a pointer.

    cout<<*p<<endl;
    cout<<**q<<endl; //"**" is used to do double dereferencing, to get the value of the variable of the pointer to whom the initial pointer is pointing to.
    cout<<p<<endl;
    cout<<*q<<endl;
    cout<<q<<endl;

    return 0;

}