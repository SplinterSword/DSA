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
    
    bool check=false;

    for(int i=0;i<n-1;i++){
       for (int j=i+1;j<n;j=j+1){
            if (arr[i]==arr[j]){
                cout<<i+1<<endl;
                check=true;
                break;
            }
       } 
       if (check){
            break;
       }
    }

    return 0;
}

//const before declaring means that no one can change the value of the variable