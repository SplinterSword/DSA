#include <iostream>
#include <string>
using namespace std;

void subseq(string str,string ans){

    if(str.length()==0){
        cout<<ans<<endl;
        return;
    }

    char ch=str[0];
    int code=ch;
    string ros=str.substr(1);

    subseq(ros,ans);
    subseq(ros,ans+ch);
    subseq(ros, ans+to_string(code));
}

int main(){
    
    subseq("ABC","");

    return 0;
}