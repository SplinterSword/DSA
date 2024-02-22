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
    int currsum=0;

    for(int i=0;i<n;i++){
        currsum=currsum+arr[i];
        if (currsum<0){
            currsum=0;
        }
        mx=max(mx,currsum);
    }

    cout<<mx<<endl;
    
    return 0;
}