#include <iostream>
#include <math.h> //like cmath
using namespace std;
int main(){
    int n;
    cout<<"Enter the no. you want to check-";
    cin>>n;
    int a=n;
    int b=1;
    while(a>0){
        int lastdigit=a%10;
        b=b+pow(lastdigit,3); //pow() function helps us to find the power of the given no.(1st argument). It raises the no. to the power of second argument.
        a=a/10;
    }
    if (b==n){
        cout<<n<<" is an armstrong no."<<endl;
    }else{
        cout<<n<<" is not an armstrong no.\n";
    }
    return 0;
}