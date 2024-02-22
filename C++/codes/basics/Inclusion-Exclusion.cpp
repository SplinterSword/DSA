#include <iostream>
using namespace std;

int main(){

    int n1=0;
    int n2=0;
    int n3=0;

    for (int i=1;i<=40;i++){
        if (i%5==0){
            n1++;
        } else if (i%7==0) {
            n2++;
        } else if (i%7==0 and i%5==0){
            n3++;
        } else {
            continue;
        }
    }

    cout<<"The total no. of digits divisible by 5 and 7 is "<<n1+n2-n3<<endl;

    return 0;
}