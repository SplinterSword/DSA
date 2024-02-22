#include <iostream>
using namespace std;
int main(){
  int n;
  int sum=0;
  cout<<"Enter your no.-";
  cin>>n;
  for(int condition=1;condition<=n;condition=condition+1){ //The first argument is for declaring an iterating variable, second argument is for the condition, and the third argument is change in condition
// for loop is used when you know how much do you want to iterate
    sum=sum+condition;
  }
  cout<<"The sum of first n natural no. is="<<sum<<endl;
  cin>>n;
  while (n>0){ //while loop is used when there is no way of knowing how many times will the loop run. Also unlike do while loop will only execute when the conditions are meet.
    cout<<"hello world"<<endl;
    n=n-1;
  }
  cout<<"Enter the no.-";
  cin>>n;
  do{ // do while unlike while loop will at least run one time even if the conditions aren't meet
    cout<<n<<endl;
    n=n-1;
  }while(n>0);
  int pocket=1000;
  for(int day=1;day<=30;day=day+1){
    if (day%2==0){
      continue; // continue is used to skip to the next iteration
    }
    if (pocket==0){
      break; //break is used to end the loop there itself or terminate it
    }
    cout<<day<<" So you can go today\n";
    pocket=pocket-300;
  }
  return 0;
}