#include <iostream>
#include <string>
using namespace std;

string move_end(string str){

    if (str.length()==0){
        return "";
    }
    char ch=str[0];
    string ans=move_end(str.substr(1));
    if (ch=='x'){
        return ans+ch;
    }
    return ch+ans;
}

int main(){
    
    string a="axxbdxcefxhix";
    cout<<move_end(a)<<endl;

    return 0;
}