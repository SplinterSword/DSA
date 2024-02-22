//Sorting is nothing but ordering of the elements of an array in an ascending or decending sort
//selection sort-Find the minimum element in unsorted array and swap it with element at begining.
#include <iostream>
using namespace std;

int main(){

    int n;
    cout<<"Enter the size of the array-";
    cin>>n;
    
    int array1[n];
    for(int i=0;i<n;i++){
        cin>>array1[i];
    }
    
    for (int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j=j+1){
            if(array1[j]<array1[i]){
                int temp=array1[j];
                array1[j]=array1[i];
                array1[i]=temp;
            }
        }
    }

    for(int i=0;i<n;i++){
        cout<<array1[i]<<" ";
    }
    
    return 0;
}