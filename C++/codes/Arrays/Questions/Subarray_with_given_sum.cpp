#include <iostream>
using namespace std;

int main(){

    int n;
    cout<<"Enter the size of the array-";
    cin>>n;

    int arr[n];
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }

    int s;
    cout<<"Enter the sum you want the subarray to have-";
    cin>>s;

    int i=0, j=0, st=-1, en=-1, sum=0;
    
    while(j<n and sum+arr[j]<=s){
        sum=sum+arr[j];
        j++;
    }

    if(sum==s){
      cout<<i+1<<" "<<j<<endl;
      return 0;
    }

    while(j<n){

        sum=sum+arr[j];
        while(sum>s){
            sum-=arr[i];
            i++;
        }

        if (sum==s){
            st=i+1;
            en=j+1;
            break;
        }
        j++;
    }

    cout<<st<<" "<<en<<endl;

    return 0;

}