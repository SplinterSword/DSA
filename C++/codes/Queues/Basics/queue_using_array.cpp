#include <iostream>
using namespace std;

class queue
{
    int *arr;
    int front, rear;
    int size;

public:
    queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    void push(int data)
    {
        if (rear == size)
        {
            cout << "Queue is full\n";
            return;
        }

        arr[rear] = data;
        rear++;
    }

    void pop()
    {
        if (rear == front)
        {
            cout << "Queue is empty\n";
            return;
        }

        arr[front] = -1;
        front++;

        if (rear == front)
        {
            rear = 0;
            front = 0;
        }
    }

    bool isempty()
    {
        if (rear == front)
        {
            return 1;
        }
        return 0;
    }

    int frontelement()
    {
        if (rear == front)
        {
            cout << "Queue is empty\n";
            return -1;
        }

        return arr[front];
    }
};

int main()
{
    queue a(10);
    a.push(5);
    cout << a.frontelement() << endl;
    a.pop();
    cout << a.frontelement() << endl;
    return 0;
}