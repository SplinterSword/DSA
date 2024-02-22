//Pointers are variables that store the address of other variables in the memory block. 
//Adress of a variable is in hexadecimal form
#include <iostream>
using namespace std;

int main(){

    int a=10;
    int* aptr; //to declare a pointer you need '*' after datatype of the variable which the pointer is pointing to. This '*' is used for this process which is called referencing.
    aptr=&a; //& operator gives the address of a variable which is stored in the memory block.

    cout<<a<<endl;
    cout<<aptr<<endl;
    cout<<*aptr<<endl; // * is also used for dereferencing which means to access or change the value of the variable directly.

    *aptr=20; //value of a is directly changed

    cout<<a<<endl;

    return 0;
}