#include <iostream>
#include <vector>
using namespace std;

class heap
{
public:
    int v[100];
    int size;

    heap()
    {
        v[0] = -1;
        size = 0;
    }

    void insert(int data)
    {
        size++;
        v[size] = data;
        int index = size;

        while (index > 1)
        {
            int parent = index / 2;

            if (parent >= 1 && v[parent] < v[index])
            {
                swap(v[parent], v[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void deletion()
    {
        if (size == 0)
        {
            cout << "There is nothing to add :" << endl;
            return;
        }

        swap(v[1], v[size]);
        size--;

        int i = 1;
        while (i < size)
        {
            int leftchild = 2 * i;
            int rightchild = 2 * i + 1;

            if (leftchild <= size && v[leftchild] > v[i])
            {
                swap(v[i], v[leftchild]);
                i = leftchild;
            }
            else if (rightchild <= size && v[rightchild] > v[i])
            {
                swap(v[i], v[rightchild]);
                i = rightchild;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
};

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left < n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right < n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapsort(int arr[],int size)
{
    swap(arr[1], arr[size]);
    size--;
    heapify(arr,size,1);
}

int main()
{
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, 1);
    }
    heap a;
    a.insert(2);
    a.insert(3);
    a.insert(4);
    a.insert(5);
    a.print();
    a.deletion();
    a.print();

    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    heapsort(arr,n);

    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}