#include <iostream>
#include <cmath>
using namespace std;
int add(int num1,int num2){
    int sum=num1+num2;
    return sum;
}
int main(){
    int n;
    int a,b;
    cout<<"Enter the 2 no. with a space-";
    cin>>a>>b;
    cout<<"Enter the no. of steps-";
    cin>>n;
    cout<<a<<','<<b;
    for(int i=1;i<=(n-2);i=i+1){
        cout<<','<<add(a,b);
        int c=add(a,b);
        a=b;
        b=c;
    }
    return 0;
}