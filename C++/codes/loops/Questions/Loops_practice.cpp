#include <iostream>
using namespace std;
int main(){
  int a;
  int b;
  cout<<"Enter the positive numbers with spaces-";
  cin>>a>>b;
  while(a<=b){
    int i;
    for(i=2;i<=a;i=i+1){
      if (a%i==0){
        break;
      }
    }
    if (i==a){
      cout<<a<<endl;
    }
    a=a+1;
  }
  return 0;
}