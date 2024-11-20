#include <iostream>
#include <algorithm> // header file to use sorting and searching algorithm
using namespace std;

void show(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return;
}
int main()
{
    int arr[10]={1,2,4,5,2,6,5,5,9,7};
    show(arr,10);
    sort(*arr,*(arr+9)); // sort(starting point iterator,ending point iterator) is used to sort an array,list or a vector.
    show(arr,10);
}