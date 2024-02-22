#include <iostream>
using namespace std;

int gcd(int a,int b){
    while(b!=0){
        int rem=a%b;
        a=b;
        b=rem;
    }
    return a;
}

int main(){

    int n1;
    int n2;
    cout<<"Enter the numbers you want find the hcf-";
    cin>>n1>>n2;

    //My way
    int hcf;

    for (int i=2;i<=min(n1,n2)/2;i++){
        if (n1%i==0 and n2%i==0){
            hcf=i;
        }
    }

    cout<<hcf<<endl;

    //Their way

    gcd(n1,n2);

    return 0;
}