//an array of characters
#include <iostream>
using namespace std;
int main(){

    char arr[10]="apple"; //size of array is taken as n+1 because of the presence of \0 (null character).
    int i=0;

    //this is for outputting different characters of an array
    while(arr[i]!='\0'){ // \0 is a null character
        cout<<arr[i]<<endl;
        i++;
    }

    //Taking an input
    int n;
    cout<<"Enter the size of the letter (array) you want to input-";
    cin>>n;

    char arr1[n+1];

    cin>>arr1; //just put in the letter or the sentence you want to input

    //Taking output

    cout<<arr1; //give us the whole array (word or sentence) and not the individual elements (words or spaces)

    return 0;
}