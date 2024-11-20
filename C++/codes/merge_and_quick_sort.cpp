#include <iostream>
using namespace std;

void merge(int *arr,int s,int e)
{
    int mid=(s+e)/2;

    int len1=mid-s+1;
    int len2=e-mid;

    int *first = new int[len1];
    int *second= new int[len2];

    //copy values
    int mainArrayIndex=s;
    for(int i=0;i<len1;i++)
    {
        first[i]=arr[mainArrayIndex++];
    }

    mainArrayIndex=mid+1;
    for(int i=0;i<len2;i++)
    {
        second[i]=arr[mainArrayIndex++];
    }

    //merge 2 sorted arrays
    int index1=0;
    int index2=0;
    mainArrayIndex=s;

    while (index1<len1 && index2<len2)
    {
        if(first[index1]<second[index2])
        {
            arr[mainArrayIndex++]=first[index1++];
        }
        else
        {
            arr[mainArrayIndex++]=second[index2++];
        }
    }

    while (index1 < len1)
    {
        arr[mainArrayIndex++]=first[index1++];
    }

    while (index2 < len2)
    {
        arr[mainArrayIndex++]=second[index2++];
    }

    delete []first;
    delete []second;
}

void mergeSort(int arr[],int start,int end){
    if (start >= end){
        return;
    }

    int mid = (start+end)/2;

    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);

    merge(arr,start,end);
}

void quickSort(int arr[], int start, int end) {
    if (start >= end) {
        return;
    }

    int pivot = end;
    int i = start;
    int j = end;

    while (i != j){
        if (arr[i] < arr[pivot]) {
            i++;
            continue;
        }

        j--;
        swap(arr[i],arr[j]);
    }

    swap(arr[j],arr[pivot]);

    //left part
    quickSort(arr,start,i-1);
    
    //right part
    quickSort(arr,i+1,end); 
    return;
}


void print(int arr[]) {
    for (int i=0;i<5;i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[5] = {2,3,55,46,8};
    mergeSort(arr,0,4);
    print(arr);

    int arr2[5] = {55,3,1,5,4};
    quickSort(arr2,0,4);
    print(arr2);

    return 0;
}