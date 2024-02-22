#include <iostream>
using namespace std;
//only works on sorted array

int binarysearch(int array[],int n,int key){
    int s=0;
    int e=n;
    while (s<=e){
        int mid=(s+e)/2;

        if(array[mid]==key){
            return mid;
        }
        else if(array[mid]>key){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return -1;
}

int main(){

    int n;
    cout<<"Enter the size of the array-";
    cin>>n;
    
    int array1[n];
    for(int i=0;i<n;i++){
        cin>>array1[i];
    }
    
    int key;
    cout<<"Enter the element you want to find-";
    cin>>key;
    
    cout<<binarysearch(array1,n,key)<<endl;

    return 0;
}