#include <iostream>
using namespace std;

int main(){

    int arr[3]={10,20,30};
    cout<<*arr<<endl; //When an array is declared the variable name becomes an indexing pointer, not a memory pointer. So this pointer can't be modified(increment or decriment). It always points to the first element of the array.

    //To make it in to a memory pointer, we declare another pointer variable. And equate it to the indexing pointer.
    int* ptr=arr;
    
    //we can also use both indexing and memory pointer to display the elements in the array.
    for(int i=0;i<3;i++){
        cout<<*(arr+i)<<"-"; //arr can be plus or minused.
        cout<<*ptr<<endl;
        ptr++;
    }
    return 0;
}