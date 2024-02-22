//Bubble Sort-Reapetedly Swap two adjacent elements if they are in wrong order,
#include <iostream>
using namespace std;

int main(){

    int n;
    cout<<"Enter the size of the array-";
    cin>>n;
    
    int array1[n];
    for(int i=0;i<n;i++){
        cin>>array1[i];
    }

    int counter=1;

    while (counter<=n-1){
        for(int i=0;i<n-counter;i++){
            if(array1[i]>array1[i+1]){
                int temp=array1[i];
                array1[i]=array1[i+1];
                array1[i+1]=temp;
            }
        }
        counter=counter+1;
    }

    for(int i=0;i<n;i++){
        cout<<array1[i]<<" ";
    }
    
    return 0;
}