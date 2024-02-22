#include <iostream>
#include <string>
using namespace std;

int main(){

    cin.ignore();
    string x;
    getline(cin,x);
    cin.ignore();

    cout<<"the difference btw lower and upper ascii value is-"<<'a'-'A'<<endl;

    for (int i=0;i<x.length();i++){
        if (x[i]>='a' and x[i]<='z'){
            x[i]=x[i]-32;
        } else if (x[i]>='A' and x[i]<='Z'){
           x[i]=x[i]+32; 
        } else {
            continue;
        }
    }
    cout<<x<<endl;

    return 0;
}