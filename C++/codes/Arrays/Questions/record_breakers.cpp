#include <iostream>
using namespace std;

int main(){

    int n;
    cout<<"Enter the size of the array-";
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int max=arr[0];

    for(int i=0;i<n;i++){
        if (i==0){
            if (arr[i]>arr[i+1]){
                max=arr[i];
                cout<<i+1<<endl;
            }
        } else if (i==n-1){
            if (arr[i]>max){
                max=arr[i];
                cout<<i+1<<endl;
            }
        } else {
            if (arr[i]>max and arr[i]>arr[i+1]){
                max=arr[i];
                cout<<i+1<<endl;
            }
        }
    }

    return 0;
}