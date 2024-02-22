#include <iostream>
#include <cmath>
using namespace std;
int fac(int a){
    int fac=1;
    for(int i=2;i<=a;i++){
        fac=fac*i;
    }
    return fac;
}
int main(){
    int n,r;
    cout<<"Enter the n and r with space-";
    cin>>n>>r;
    cout<<fac(n)/(fac(r)*fac(n-r))<<endl;
    return 0;
}