#include <iostream>
#include <string>
using namespace std;

void remove_duplicates(string str){

    if (str.length()==0){
        return;
    }
    char ros=str[0];
    if(str[1]==ros){
        remove_duplicates(str.substr(1));
    } else {
        cout<<ros;
        remove_duplicates(str.substr(1));
    }
    return;
    
}

int main(){
    
    string a="aaaabbbeeecdddd";
    remove_duplicates(a);

    return 0;
}