#include <iostream>
#include <climits>
using namespace std;

int main(){

    int n;
    cout<<"Enter the size of the letter (array) you want to input-";
    cin>>n;
    cin.ignore();

    char arr[n+1];
    cin.getline(arr, n); //cin.getline() function allows us to take sentences as inputs. It takes 2 arguments arr, and size of the array.
    cin.ignore(); //cin.ignore() function is necessary to clear the buffer of the program

    int mx=INT_MIN;
    int sum=0;
    int st=0, maxst=0;

    for(int i=0;i<n;i++){
        if(arr[i]!=' ' or arr[i]!='\0'){
            sum=sum+1;
        } else {
            mx=max(sum,mx);
            maxst=max(maxst,st);
            sum=0;
            st=i+1;
        }
    }

    cout<<mx<<endl;

    for(int i=0; i<mx; i++){
        cout<< arr[i+ maxst];
    }

    return 0;
}