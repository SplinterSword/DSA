#include <iostream>
#include <string>
using namespace std;

string keypadarr[]={"","","abc","def","ghi","ghi","jkl","mno"};

void keypad(string s, string ans){
    if(s.length()==0){
        cout<<ans<<endl;
    }

    char ch=s[0];
    string code= keypadarr[ch-'0'];
    string ros= s.substr(1);

    for(int i=0;i<code.length();i++){
        keypad(ros,ans+code[i]);
    }
}

int main(){
    
    keypad("23","");

    return 0;
}