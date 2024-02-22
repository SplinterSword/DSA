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

    int current=2;
    int ans=2;
    int pd=arr[1]-arr[0];

    for(int i=2;i<n;i++){
        if (pd==arr[i]-arr[i-1]){
            current++;
        }else{
            pd=arr[i]-arr[i-1];
            current=2;
        }
        ans=max(ans,current);
    }

    cout<<ans<<endl;

    return 0;
}