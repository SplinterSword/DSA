//Only for sorted matrice
#include <iostream>
using namespace std;

int main(){

    int n,m;
    cin>>n>>m;
    int arr[n][m];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j=j+1){
            cin>>arr[i][j];
        }
    }

    int key;
    cout<<"Enter the element you want to find-";
    cin>>key;
    
    int check=0;
    int i=0;
    int j=m-1;

    while (i<n and j>=0){
        if (arr[i][j]==key){
            cout<<i<<" "<<j<<"\ntrue"<<endl;
            return 0;
        } else if (arr[i][j]>key){
            j=j-1;
            check++;
        } else {
            i++;
            check++;
        }
    }

    cout<<"Element not found"<<endl<<"false\n";
    return 0;
}