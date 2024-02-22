#include <iostream>
using namespace std;

bool checksort(int arr[],int n){

    if(n==1){
        return true;
    }
    
    bool restArray=checksort(arr+1,n-1);
    return (arr[0]<arr[1] and restArray);

}

int main(){

    int arr[7]={1,2,3,4,5,6,7};

    cout<<checksort(arr,7)<<endl;

    return 0;
}