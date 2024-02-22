#include <iostream>
using namespace std;

/*
Time Complexity
avg case=O(nlogn)
best case=O(nlogn)
worst case=O(n^2)
*/

//space complexity=O(n);

int partition(int *arr,int s,int e)
{
    int pivot=arr[s];

    int count=0;
    for(int i=s+1;i<=e;i++)
    {
        if(arr[i]<=pivot)
        {
            count++;
        }
    }

    //place pivot in the right index
    int pivotIndex=s+count;
    swap(arr[pivotIndex],arr[s]);

    //left and right wala part smbhal leta hai
    int i=s,j=e;
    while(i<pivotIndex && j>pivotIndex)
    {
        while(arr[i]<pivot)
        {
            i++;   
        }
        while(arr[j]>pivot)
        {
            j--;   
        }
        while(i<pivotIndex && j>pivotIndex)
        {
            swap(arr[i++],arr[j--]);
        }
    }

    return pivotIndex;
}

void quicksort(int *arr,int s,int e)
{
    //base case
    if (s>=e)
    {
        return ;
    }

    //partition kara
    int p=partition(arr,s,e);

    //left wala part
    quicksort(arr,s,p-1);

    //right wala part
    quicksort(arr,p+1,e);
}

int main()
{
    int arr[6]={3,5,1,8,2,4};
    quicksort(arr,0,5);
    for(int i=0;i<6;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}