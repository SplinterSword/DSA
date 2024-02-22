#include <iostream>
#include <climits>
using namespace std;

bool pairsum(int arr[],int n,int k){

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j=j+1){
            if (arr[i]+arr[j]==k){
                cout<<i<<" "<<j<<endl;
                return true;
            }
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