#include <iostream>
using namespace std;

template <class T>
class stack
{
public:
    T top;
    T *arr;
    T size;

    stack(T size)
    {
        this->size = size;
        arr = new T[size];
        top = -1;
    }

    void push(T element)
    {
        if (top >= size)
        {
            cout << "Stack overflow" << endl;
            return;
        }

        top++;
        arr[top] = element;
    }

    T pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            return top;
        }

        top--;
        return arr[top + 1];
    }

    T peek()
    {
        return arr[top];
    }

    bool empty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    stack<int> a(5);
    a.push(1);
    a.push(2);
    cout << a.peek() << endl;
    a.pop();
    cout << a.peek() << endl;
    cout << a.empty() << endl;
    return 0;
}