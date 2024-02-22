#include <iostream>
using namespace std;

int main(){

    //Squrare matrice
    int n;
    cin>>n;
    int arr[n][n];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j=j+1){
            cin>>arr[i][j];
        }
    }

    int a[n][n];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j=j+1){
            a[j][i]=arr[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j=j+1){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}