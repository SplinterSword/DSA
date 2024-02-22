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
        front = -1;
        rear = -1;
    }

    void push(int data)
    {
        if ((rear == size && front == 0) || (rear == (front - 1) % (size - 1))) //queue is full
        {
            cout << "Queue is full\n";
            return;
        }

        if (front == -1)
        {
            rear = 0;
            front = 0;
            arr[rear] = data;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
            arr[rear] = data;
        }
        else
        {
            rear++;
            arr[rear] = data;
        }
    }

    int pop()
    {
        if (front == -1 && rear == -1) //to check where the queue is empty
        {
            cout << "Queue is empty\n";
            return -1;
        }

        int ans = arr[front];

        if (front == size - 1)
        {
            front = 0;
        }
        else if (front == rear) //single element is present
        {
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0; //to maintain cyclic nature
        }
        else
        {
            front++;
        }

        return ans;
    }

    bool isempty()
    {
        if (front == -1 && rear == -1)
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