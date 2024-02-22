#include <iostream>
using namespace std;

template <class T>
class MyVector
{
    T arr[400];
    int size=0;
    public:
    MyVector()
    {
        int i=0;
        int n=1;
        while(n!=0)
        {
            cout<<"Enter the element: ";
            cin>>arr[i];
            i++;
            size=size+1;
            cout<<"Enter 0 to exit entering the elements: ";
            cin>>n;
        }
    }
    void vectorsize()
    {
        cout<<"Size of vector is "<<size<<endl;
    }
    void push_back()
    {
        int i=size;
        cout<<"Enter the element you want to enter: ";
        cin>>arr[i];
        size++;
    }
    void pop_back()
    {
        size=size-1;
    }
    void display()
    {
        for(int i=0;i<size;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main()
{
    MyVector<int> a;
    a.vectorsize();
    a.display();
    a.push_back();
    a.display();
    a.pop_back();
    a.display();
    return 0;
}