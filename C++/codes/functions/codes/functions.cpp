#include <iostream>
using namespace std;
//visualise the functions in a program as a stack, the function which is called first gets pushed to the stack(in this case the main function) , and the function which returns gets popped from the stack
void print(int n){ //void data type means no data type like char, int, etc
    cout<<n<<endl;
    return;
}
int add(int num1,int num2){ //first we need to define the data type which is returned by the function. Then if there are arguments to be made then we have to declare them like any other variable in the function call 
    print(num1);
    print(num2);
    int sum=num1+num2;
    return sum; //if data type is mentioned in a function then it as to return something to the main function. when we reach return the function immediately ends no matter what.
}
int main(){
    int a=5;
    int b=3;
    cout<<add(a,b)<<endl; //during function call the order of arguments is necessary and should be kept in mind
    return 0;
}