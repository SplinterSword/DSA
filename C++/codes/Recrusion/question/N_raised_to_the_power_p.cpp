//When a function calls itself to make the problem smaller, it is called recrusion.
#include <iostream>
using namespace std;

int power(int n,int p){

    if (p==0){
        return 1;
    }

    int prevSum=power(n,p-1);
    return n*prevSum;

}

int main(){

    int n,p;
    cin>>n>>p;
    cout<<power(n,p)<<endl;
    
    return 0;
}