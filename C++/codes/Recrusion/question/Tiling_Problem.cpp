#include <iostream>
#include <string>
using namespace std;

int tilePath(int n){
    if(n==1){
        return 1;
    }
    if (n==0){
        return 0;
    }

    return tilePath(n-1)+tilePath(n-2);
}

int main(){
    
    cout<<tilePath(4)<<endl;

    return 0;
}