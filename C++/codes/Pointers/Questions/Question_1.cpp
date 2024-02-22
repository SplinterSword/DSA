#include <iostream>
using namespace std;


int main()
{
    int *p=new int[5];
    int size=5;
    for(int i=0;i<5;i++)
    {
        cin>>p[i];
    }
    delete []p;
    cout<<"Array deleted\n";
    return 0;
}