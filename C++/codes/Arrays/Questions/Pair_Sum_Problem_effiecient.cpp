//Only for sorted array. If not sorted use insertion sort algorithm to sort the array(or anyother sorting algorithm also sort it in ascending order for simplicity)
#include <iostream>
#include <climits>
using namespace std;

bool pairsum(int arr[],int n,int k){

    int low=0;
    int high=n-1;

    while(low<high){
        if(arr[low]+arr[high]==k){
            cout<<low<<" "<<high<<endl;
            return true;
        }else if(arr[low]+arr[high]>k){
            high=high-1;
        }else{
            low++;
        }
    }

    return false;
}

int main(){

    int n;
    cout<<"Enter the size of the array-";
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int k;
    cout<<"Enter the sum you want to check-";
    cin>>k;

    cout<<pairsum(arr,n,k)<<endl;
    
    return 0;
}