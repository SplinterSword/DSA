#include <iostream>
#include <cmath>
using namespace std;
bool prime(int n1){
    for (int i=2;i<=sqrt(n1);i++){
        if (n1%i==0){
            return false;
            break;
        }
    }
    return true;
}
int main(){
    int a,b;
    cout<<"Enter the 2 no. with a space-";
    cin>>a>>b;
    for(int i=a;i<=b;i++){
        if (prime(i)){
            cout<<i<<' ';
        }
    }
    return 0;
}