// Function Objects: Function wrapped in a class so that it available like an object
#include <iostream>
#include <functional> // Header file to use the functional object.
#include <algorithm>
using namespace std;

int main()
{
    int arr[]={1,5,2,3,4};
    sort(arr,arr+5); // sort in array is used by using the variable name index pointer by giving the starting and ending point
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    sort(arr,arr+5,greater<int>()); //greater<int>() function object third argument is used to sort the array, list or vector in the decending order.
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}