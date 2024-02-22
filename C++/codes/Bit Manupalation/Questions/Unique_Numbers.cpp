#include <iostream>
using namespace std;

int setBit(int n,int pos){
    return (n|(1<<pos));
}

int getBit(int n, int pos){
    return ((n & (1<<pos))!=0);
}

int unique3(int arr[],int n){

    int result=0;

    for (int i=0;i<64;i++){
        int sum=0;
        for (int j=0;j<n;j=j+1){
            if(getBit(arr[j],i)){
                sum++;
            }
        }
        if (sum%3!=0){
            result=setBit(result,i);
        }
    }
    return result;
}

void unique2(int arr[],int n){

    int xorsum=0;
    for(int i=0;i<n;i++){
        xorsum=xorsum^arr[i];
    }

    int tempxor=xorsum;
    int pos=0;
    int setbit=0;

    while(setbit!=1){
        setbit=xorsum & 1;
        pos++;
        xorsum = xorsum>>1;
    } 

    int newxor=0;

    for(int i=0;i<n;i++){
        if(getBit(arr[i],pos-1)){
            newxor=newxor^arr[i];
        }
    }  

    cout<<newxor<<endl;
    cout<<(tempxor^newxor)<<endl;
}

int unique(int arr[], int n){
    int xorsum=0;
    for(int i=0;i<n;i++){
        xorsum=xorsum^arr[i];
    }
    return xorsum;
}

int main(){
    
    int arr[7]={2,4,6,3,4,6,2};
    cout<<unique(arr,7)<<endl;
    cout<<endl;

    int arr1[8]={2,4,6,7,4,5,6,2};
    unique2(arr1,8);
    cout<<endl;

    int arr2[10]={1,3,2,3,4,2,1,1,3,2};
    cout<<unique3(arr2,10)<<endl;
    cout<<endl;

    return 0;
}