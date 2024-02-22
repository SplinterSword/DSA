//Basically visualise it as a matrice
#include <iostream>
using namespace std;

int main(){

    int n,m;
    cin>>n>>m;
    int arr[n][m]; //declaration of 2-d array. where first bracket is rows and second bracket is column

    //Taking Input
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j=j+1){
            cin>>arr[i][j];
        }
    }

    //Taking Output
    cout<<"The Matrice is-"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j=j+1){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }

    //Searching in a Matrice (brute force)
    int x;
    cout<<"Enter the element you want to search in the 2-D matrice-";
    cin>>x;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j=j+1){
            if (arr[i][j]==x){
                cout<<i<<" "<<j<<endl;
                return 0;
            }
        }
    }
    
    cout<<"Element is not found";

    return 0;
}