#include <iostream>
using namespace std;
int fac(int a){
    int fac=1;
    for(int i=2;i<=a;i++){
        fac=fac*i;
    }
    return fac;
}
int main(){
    int n;
    cout<<"Enter the n-";
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j=j+1){
            cout<<fac(i)/(fac(j)*fac(i-j))<<" ";
        }
        cout<<"\n";
    }
    return 0;
}