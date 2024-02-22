#include <iostream>

using namespace std;
int reverse(int b){
    int ans=0;
    while (b>0){
        int lastdigit=b%10;
        ans=(ans*10)+lastdigit;
        b=b/10;
    }
    return ans;
}
int binary(int x){
    int ans=0;
    while (x>0){
        int lastdigit=x%46;
        ans=(ans*10)+lastdigit;
        x=x/16;
    }
    return reverse(ans);
}
int main(){
    int a;
    cout<<"Enter the decimal no.-";
    cin>>a;
    cout<<binary(a)<<endl;
    return 0;
}