#include <iostream>
#include <string>
using namespace std;

void reverse(string str){

    if (str.length()==0){
        return;
    }

    cout<<str[str.length()-1];
    str.erase(str.length()-1,1);
    reverse(str);
    return;
    
}

int main(){
    
    string a="Binod";
    reverse(a);

    return 0;
}