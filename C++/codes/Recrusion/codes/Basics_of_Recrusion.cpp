//When a function calls itself to make the problem smaller, it is called recrusion.
#include <iostream>
using namespace std;

int Sum(int n){

    if (n==0){
        return 0;
    }

    int prevSum=Sum(n-1);
    return n+prevSum;

}

int main(){

    int n;
    cin>>n;
    cout<<Sum(n)<<endl;
    
    return 0;
}