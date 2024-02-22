//Pointers can only do simple arithematic operations like increment(++), decreament(--), plus(+) and minus(-)
#include <iostream>
using namespace std;

int main(){

    int a=10;
    int* aptr=&a;
    
    cout<<aptr<<endl;
    aptr++; //with increment it won't just add one to the pointer variable rather it will move or change to the next memory block differentiated by 4 bytes. This is the same with other operators.
    cout<<aptr<<endl;

    return 0;
}