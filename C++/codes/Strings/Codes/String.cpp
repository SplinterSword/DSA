#include <iostream>
#include <string> //This <string> header file is required to use strings. It allows us to use the string as a datatype.
using namespace std;

int main(){

    string x; //string is declared as anyother datatype (like int, bool ,char,float,etc).
    cout<<"Enter the String or the word-";
    cin>>x; //you can only input words using this input method.
    cout<<x<<endl;

    //other ways to declare a string.
    string y(5,'n'); //1st way. 1st Argument is the size of the string and second is the repeating letter in char datatype
    cout<<y<<endl;
    string str="Apni Kaksha"; //2nd way. You can take sentences this way
    cout<<str<<endl;
    //Notice there is not space in word because in c++ string the space is terminating

    //Now how to string input as sentences
    cin.ignore(); //Clear the buffer. Necessary Before getline or else getline won't work
    string str1;
    cout<<"Enter the String or the sentence-";
    getline(cin,str1); //getline(cin,string_variable_name) function is used to get sentence input.
    cout<<str1<<endl;
    cin.ignore();

    return 0;
}