#include <iostream>
#include <string>
using namespace std;

int main(){

    string x;
    cout<<"Enter the string-";
    cin>>x;

    int freq[26];
    for(int i=0;i<26;i++){
        freq[i]=0;
    }

    for(int i=0;i<x.length();i++){
        freq[x[i]-'a']++;
    }

    char ans='a';
    int maxF=0;

    for(int i=0;i<26;i++){
        if (freq[i]>maxF){
            maxF=freq[i];
            ans=i+'a';
        }
    }
    cout<<maxF<<" "<<ans<<endl;

    return 0;
}