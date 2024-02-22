#include <iostream>
using namespace std;

int main()
{
    int x, *y=NULL;
    cin>>x;

    try 
    {
        y=new int[x];
    }
    catch (bad_alloc) //for special execeptions, special keywords are used in the catch block to handle the exception. In this example memory may not be allocated to the heap memory.
    {
        cout<<"Not enough memory\n";
        return 0;
    }

    cout<<"Memory allocated\n";
    delete []y;
    return 0;
}