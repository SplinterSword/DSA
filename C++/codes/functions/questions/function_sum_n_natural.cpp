#include <iostream>
using namespace std;
int naturalsum(int a){
    int b=1;
    for(int i=2;i<=a;i++){
        b=b+i;
    }
    return b;
}
int main(){
    int n;
    cout<<"Enter the no.-";
    cin>>n;
    cout<<naturalsum(n)<<endl;
    return 0;
}