// This is queue and stack in one data structure.
#include <iostream>
using namespace std;

class deque
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

    void push_front(int data)
    {
        if ((rear == size && front == 0) || (rear == (front - 1) % (size - 1))) // queue is full
        {
            cout << "Queue is full\n";
            return;
        }

        if (front == -1)
        {
            rear = 0;
            front = 0;
        }
        else if (front == 0)
        {
            front = size - 1;
        }
        else
        {
            front--;
        }
        arr[front] = data;
    }

    void push_rear(int data)
    {
        if ((rear == size && front == 0) || (rear == (front - 1) % (size - 1) && front != 0)) // queue is full
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

    int pop_front()
    {
        if (front == -1 && rear == -1) // to check where the queue is empty
        {
            cout << "Queue is empty\n";
            return -1;
        }

        int ans = arr[front];

        if (front == size - 1)
        {
            front = 0;
        }
        else if (front == rear) // single element is present
        {
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0; // to maintain cyclic nature
        }
        else
        {
            front++;
        }

        return ans;
    }

    int pop_rear()
    {
        if (front == -1 && rear == -1) // to check where the queue is empty
        {
            cout << "Queue is empty\n";
            return -1;
        }

        int ans = arr[rear];

        if (front == rear)
        {
            front = rear = -1;
        }
        else if (rear == 0)
        {
            rear = size - 1;
        }
        else
        {
            rear--;
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
        if (front == -1)
        {
            cout << "Queue is empty\n";
            return -1;
        }

        return arr[front];
    }

    int rearelement()
    {
        if (rear == -1)
        {
            cout << "Queue is empty\n";
            return -1;
        }

        return arr[rear];
    }
};

int main()
{
    deque a(10);
    a.push_front(5);
    cout << a.frontelement() << endl;
    cout << a.pop_rear() << endl;
    cout << a.frontelement() << endl;
    return 0;
}