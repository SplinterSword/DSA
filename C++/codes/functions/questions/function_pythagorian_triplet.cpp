#include <iostream>
#include <cmath>
using namespace std;
bool pytha(int p,int q,int r){
    if (pow(p,2)==pow(q,2)+pow(r,2)){
        return true;
    }else{
        return false;
    }
}
bool check(int x,int y,int z){
    if (x>y and x>z){
        return pytha(x,y,z);
    }else if(y>x and y>z){
        return pytha(y,x,z);
    }else{
        return pytha(z,y,x);
    }
}
int main(){
    int a,b,c;
    cout<<"Enter the sides of the triangle with spaces-";
    cin>>a>>b>>c;
    if (check(a,b,c)){
        cout<<"Pythagorian Triplet\n";
    }else{
        cout<<"Not a Pythagorian Triplet"<<endl;
    }
    return 0;
}