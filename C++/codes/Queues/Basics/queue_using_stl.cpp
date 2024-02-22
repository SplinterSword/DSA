#include <iostream>
#include <queue> //header stl file for queue.
using namespace std;

int main()
{
    queue<int> a;
    a.push(5);
    a.push(10);
    cout<<a.size()<<endl;
    cout<<a.front()<<endl;
    a.pop();
    cout<<a.size()<<endl;
    cout<<a.front()<<endl; //returns the front element of the queue
    cout<<a.empty()<<endl; //returns 1 if queue is empty.
    return 0;
}