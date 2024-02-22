#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){

    string x;
    cout<<"Enter the no.-";
    cin>>x;

    sort(x.begin(),x.end(),greater<int>()); //greater<int>() is used to sort the string in decreasing order.
    cout<<x<<endl;
    
    for(int i=x.length()-1;i>=0;i--){ //code for reverse order of the initial string it recieves
        cout<<x[i];
    }

    return 0;
}