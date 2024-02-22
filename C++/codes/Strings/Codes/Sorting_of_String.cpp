#include <iostream>
#include <string>
#include <algorithm> //algorithm is header file which used to use sort() to sort the string and other algorithms. 
using namespace std;

int main(){

    string x="adfhsfasdkfsddghuioejfdhdfkl";
    sort(x.begin(),x.end()); //sort() is used to sort the string in ascending order with respect to ascii values. string.begin() and string.end() used to find the first and last iterator respectively.
    cout<<x<<endl;

    return 0;
}