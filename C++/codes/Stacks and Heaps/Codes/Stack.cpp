//Stack is a fix memory block where when a function is called it goes into in a sequencial order and when returned or gets poped it is removed in a sequencial order. When it is filled, it results in a condition called Stack Overflow.
//Stack does allocating and deallocating memory automatically and in a sequencial order.
#include <iostream>
using namespace std;

int func3(int a){ //fourth, function func3 is put into the stack
    a++;
    return a; //First, func3 is poped out of the stack
}


int func2(int a){ //third, function func2 is put into the stack
    a=func3(a);
    return a; //Second, func2 is poped out of the stack
}


int func1(int a){ //second, function func1 is put into the stack
    a=func2(a);
    return a; //Third, func1 is poped out of the stack
}

int main(){ //First, function main is put into the stack
    
    int a=10;
    cout<<func1(a);

    return 0; //Fourth, main is poped out of the stack
}