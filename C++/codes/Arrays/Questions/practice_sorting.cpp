#include <iostream>
using namespace std;

int main(){

    int n;
    cout<<"Enter the size of array-";
    cin>>n;

    int array1[n];
    for (int i=0;i<n;i++){
        cin>>array1[i];
    }

    //Bubble sort
    for (int i=0;i<n;i++){
        for (int j=0;j<(n-i);j=j+1){
            if (array1[j]>array1[j+1]){
                int temp=array1[j+1];
                array1[j+1]=array1[j];
                array1[j]=temp;
            }
        }
    }
    
    for (int i=0;i<n;i++){
        cout<<array1[i]<<" ";
    }

    int array2[n];
    for (int i=0;i<n;i++){
        cin>>array2[i];
    }
    
    //Selection Sort
    for (int i=0;i<(n-1);i++){
        for (int j=i+1;j<=n;j=j+1){
            if (array2[i]>array2[j]){
                int temp=array2[i];
                array2[i]=array2[j];
                array2[j]=temp;
            }
        }
    } 

    for (int i=0;i<n;i++){
        cout<<array2[i]<<" ";
    }

    int array3[n];
    for (int i=0;i<n;i++){
        cin>>array3[i];
    }
    
    //Insertion Sort
    for (int i=0;i<n;i++){
        int current=array3[i];
        int j=i-1;
        while(array3[j]>current and j>=0){
            array3[j+1]=array3[j];
            j=j-1;
        }
        array3[j+1]=current;
    } 

    for (int i=0;i<n;i++){
        cout<<array3[i]<<" ";
    }


    return 0;
}