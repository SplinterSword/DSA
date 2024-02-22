#include <iostream>
using namespace std;
int main(){
  char button;
  cout<<"enter the input-";
  cin>>button;
  switch(button){ //used in place of multiple if else statements. The Argument is the thing you want to compare with the cases. It is more efficient than multiple if_ else statements
    case 'a':  // case tells us the code to be executed if variable==specified thing. Also don't forget the :.
      cout<<"Hello"<<endl;
      break; //break is used to terminate the switch function. If it is not there it will execute everything after that point
    case 'b':
      cout<<"Salute"<<endl;
      break;
    case 'c':
      cout<<"Ola"<<endl;
      break;
    case 'd':
      cout<<"Namaste"<<endl;
      break;
    case 'e':
      cout<<"gg"<<endl;
      break;
    default: //default is used when variable doesn't match all the other cases
      cout<<"I am still learning\n";
      break;
  }
  return 0;
}