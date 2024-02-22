#include <iostream>
#include <climits>
using namespace std;

int main(){

    int n;
    cout<<"Enter the size of the array-";
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int mx=INT_MIN;

    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j=j+1){
            sum=sum+arr[j];
            if (sum>mx){
                mx=sum;
            }
        }
    }

    cout<<mx<<endl;
    
    return 0;
}