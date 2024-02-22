#include <iostream>
#include <string>
using namespace std;

int main(){

    string x="789";
    cout<<stoi(x)+2<<endl; //stoi(string_variable) converts integer which is a string to integer.

    int y=789;
    cout<<to_string(y)+"2\n"; //to_string(integer_variable) converts integer to integer which is a string.

    return 0;
}