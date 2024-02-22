#include <iostream>
using namespace std;

class TwoStack
{
public:
    int *arr;
    int top1, top2;
    int size;

    TwoStack(int size)
    {
        this->size = size;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    void push1(int element)
    {
        if (top2 - top1 > 1)
        {
            top1++;
            arr[top1] = element;
        }
        else 
        {
            cout << "Stack Overflow" <<endl;
        }
    }

    void push2(int element)
    {
        if (top2 - top1 > 1)
        {
            top2--;
            arr[top2] = element;
        }
        else 
        {
            cout << "Stack Overflow" <<endl;
        }
    }

    int pop1()
    {
        if (top1 >= 0)
        {
            top1--;
            return arr[top1+1];
        }
        else 
        {
            cout << "Stack Underflow\n";
            return -1;
        }
    }

    int pop2()
    {
        if (top2 < size)
        {
            top2++;
            return arr[top2-1];
        }
        else 
        {
            cout << "Stack Underflow\n";
            return -1;
        }
    }
}

int main()
{
    
    return 0;
}