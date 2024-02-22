#include <iostream>
using namespace std;
int factorial(int a){
    int fac=1;
    for(int i=2;i<=a;i++){
        fac=fac*i;
    }
    return fac;
}
int main(){
    int n;
    cout<<"Enter the no.-";
    cin>>n;
    cout<<factorial(n)<<endl;
    return 0;
}