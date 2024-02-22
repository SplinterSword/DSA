#include <iostream>
using namespace std;

int main(){
    
    int n;
    cout<<"Enter the no. you want to check-";
    cin>>n;

    if ((n&(n-1))==0 or n==0){
        cout<<n<<" is a power of 2\n";
    } else {
        cout<<n<<" is not a power of 2"<<endl;
    }

    return 0;
}