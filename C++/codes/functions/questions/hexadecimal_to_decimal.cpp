#include <iostream>
#include <cmath>
using namespace std;
int decimal(int x){
    int ans=0;
    int n=0;
    while (x>0){
        int lastdigit=x%10;
        ans=ans+(lastdigit*pow(16,n));
        n=n+1;
        x=x/10;
    }
    return ans;
}
int main(){
    int a;
    cout<<"Enter the octal no.-";
    cin>>a;
    cout<<decimal(a)<<endl;
    return 0;
}