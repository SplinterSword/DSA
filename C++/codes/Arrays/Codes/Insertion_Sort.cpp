//Insertion Sort-Insert an element from unsorted array to its correct position in sroted array.
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

    for (int i=1;i<n;i++){
        int current=array1[i];
        int j=i-1;
        while (array1[j]>current and j>=0){
            array1[j+1]=array1[j];
            j=j-1;
        }
        array1[j+1]=current;
    }

    for(int i=0;i<n;i++){
        cout<<array1[i]<<" ";
    }
    
    return 0;
}