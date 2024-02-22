#include <iostream>
using namespace std;

int main(){
    
    int n;
    cout<<"Enter the no. you want to check-";
    cin>>n;

    int count=0;

    while (n>0){
        n=(n&(n-1));
        count++;
    }

    cout<<count<<endl;

    return 0;
}