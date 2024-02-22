#include <iostream>
#include <climits> //used to use INT_MAX and INT_MIN
using namespace std;
int main(){
    int array[4]={10,20,30,40}; // This is how you declare an array. The size of is nesscessary to mention
    cout<<array[3]<<endl; // we can traverse an array using indexes where first element has the index 0.
    
    //now how to take user input for arrays
    int n;
    int arrayj[n];
    cout<<"Enter the size of the array-";
    cin>>n;
    cout<<"Now Enter the inputs-";
    for(int i=0;i<n;i++){
        cin>>arrayj[i];
    }
    //Now a question based no it (To find the min and the max no. of the array)
    int max1=INT_MIN; //INT_MIN is the lowest possible integer possible in c++
    int min1=INT_MAX; //INT_MAX is the highest possible integer possible in c++
    for(int i=0;i<n;i++){
        max1=max(arrayj[i],max1); //max function is a built-in function which takes 2 values and returns the highest value.
        min1=min(arrayj[i],min1); //min function is a built-in function which takes 2 values and returns the lowest value.
    }
    cout<<max1<<endl<<min1<<endl;
    return 0;
}