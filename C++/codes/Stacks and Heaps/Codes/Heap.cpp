//Unlike Stack, Heap is a free memory with it limit being the virual memory of the computer.
//We have to manually allocate and deallocate memory in Heap which is unlike stack.
#include <iostream>
using namespace std;

int main(){

    int a=10; //Stored in Stack

    int* p=new int(); //new with datatype() is used to allocate memory of a single element in a heap. Now p has the address of the element in the heap memory.
    *p=10; //Giving value to the element stored in heap using pointers. But the Pointer variable is stored in stack.
    delete(p); //delete(pointer-variable) is used  to delete or deallocate memory or the single element from the heap leaving a pointer pointing to nothing, this type of pointer is called "Dangling Pointer" which is unwanted.

    //There are 2 ways to deal with Dangling Pointer. First-delete the pointer from the stack memory block. Second-Reuse it.
    //Here is Second

    p=new int[4]; //Now pointer p is pointing to an array in the heap memory.
    delete[]p; //Now the array is deallocted and pointer becomes dangling pointer. delete[]pointer-variable is used to delete a memory block or array from the heap memory.

    //Here is the first method.
    p=NULL; //By equating pointer p to NULL, We delete it from the Stack Memory.


    return 0;
}