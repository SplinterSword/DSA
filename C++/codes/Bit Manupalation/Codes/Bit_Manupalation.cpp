#include <iostream>
using namespace std;

int clearBit(int n,int pos){
    return (n & (~(1<<pos)));
}

int setBit(int n,int pos){
    return (n | (1<<pos));
}

int getBit(int n, int pos){
    return ((n & (1<<pos))!=0);
}

int updateBit(int n,int pos,int value){
    int mask=~(1<<pos);
    n=n&mask;
    return (n | (value<<pos));
}


int main(){

    cout<<getBit(5,2)<<endl;
    cout<<setBit(5,1)<<endl;
    cout<<clearBit(5,2)<<endl;
    cout<<updateBit(5,1,1)<<endl;

    return 0;
}