#include <iostream>
using namespace std;
int main(){

    int n;
    cout<<"Enter the size of the letter (array) you want to input-";
    cin>>n;

    char arr[n+1];
    cin>>arr;

    bool check=true;

    for(int i=0;i<n;i++){
        if (arr[i] != arr[n-1-i]){
            check=false;
            break;
        }
    }

    if (check){
        cout<<"It is a Palindrome\n";
    } else {
        cout<<"It is not a Palindrome"<<endl;
    }

    return 0;
}