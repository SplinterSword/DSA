#include <iostream>
#include <string>
using namespace std;

int Friends(int n){
    if (n==0 or n==1 or n==2){
        return n;
    }

    return Friends(n-1)+Friends(n-2)*(n-1);
}

int main(){
    
    cout<<Friends(4)<<endl;

    return 0;
}