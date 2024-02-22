#include <iostream>
#include <queue> //header stl file for double ended queue.
using namespace std;

int main()
{
    deque<int> d; //deque for double ended queue.
    d.push_front(12);
    d.push_back(14);

    cout << d.front() << endl;
    cout << d.back() << endl;

    d.pop_front();

    cout << d.front() << endl;
    cout << d.back() << endl;

    d.pop_back();
    
    cout << d.empty() << endl;
    return 0;
}