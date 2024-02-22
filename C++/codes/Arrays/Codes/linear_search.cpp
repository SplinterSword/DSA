#include <iostream>
using namespace std;
int linearsearch(int array[],int n,int a){
    for(int i=0;i<n;i++){
        if (array[i]==a){
            return i;
        }
    }
    return -1;
}
int main(){
    
    int n;
    cout<<"Enter the size of the array-";
    cin>>n;
    
    int array1[n];
    for(int i=0;i<n;i++){
        cin>>array1[i];
    }
    
    int key;
    cout<<"Enter the element you want to find-";
    cin>>key;
    
    cout<<linearsearch(array1,n,key)<<endl;
    
    return 0;
}