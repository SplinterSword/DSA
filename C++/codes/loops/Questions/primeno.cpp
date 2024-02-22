#include <iostream>
#include <cmath> //A header file which include different mathematical functions like square root function
using namespace std;
int main(){
    int a;
    cout<<"Enter the no. you want to check-";
    cin>>a;
    bool flag=0;
    for(int i=2;i<=sqrt(a);i=i+1){ //sqrt() is used to find the square root of the given no. (argument)
        if (a%i==0){
            cout<<"Not a prime no."<<endl;
            flag=1;
            break;
        }
    }
    if (flag==0){
        cout<<a<<" is a prime no.\n";
    }
    return 0;
}