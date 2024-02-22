#include <iostream>
#include <string>
using namespace std;

void pi_replace(string str){

    if (str.length()==0){
        return;
    }

    if (str[0]=='p' and str[1]=='i'){
        cout<<"3.14";
        pi_replace(str.substr(2));
    } else {
        cout<<str[0];
        pi_replace(str.substr(1));
    }

    return;    
}

int main(){
    
    string a="pippxxppiixipi";
    pi_replace(a);

    return 0;
}