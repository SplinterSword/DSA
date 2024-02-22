#include <iostream>
using namespace std;

int linearsearch(int arr[],int n,int key){
    for(int i;i<n;i++){
        if (key==arr[i]){
            return i;
        }
    }
    return -1;
}

int binarysearch(int arr[],int n,int key){
    int s=0;
    int e=n;
    while (s<=e){
        int mid=(s+e)/2;

        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]>key){
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
    cout<<"Enter the size of array-";
    cin>>n;

    int array1[n];
    for (int i=0;i<n;i++){
        cin>>array1[i];
    }

    for(int i;i<n;i++){
        int current=array1[i];
        int j=i-1;
        while(array1[j]>current and j>=0){
            array1[j+1]=array1[j];
            j=j-1;
        }
        array1[j+1]=current;
    }
    
    int key;
    cout<<"Enter the element you want to search-";
    cin>>key;

    cout<<linearsearch(array1,n,key)<<endl<<binarysearch(array1,n,key);

    return 0;
}