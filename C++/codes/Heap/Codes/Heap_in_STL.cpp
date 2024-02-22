#include <iostream>
#include <queue> // header file to include heap
using namespace std;

int main()
{
    cout << "using Priority Queue here" << endl;
    cout << "Now MAX HEAP\n";
    priority_queue<int> pq; // this is max heap.

    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    cout << "element at Top " << pq.top() << endl;
    pq.pop();
    cout << "element at Top " << pq.top() << endl;
    cout << "Size is " << pq.size() << endl;
    cout <<  pq.empty() << endl;

    cout << "Now MIN HEAP\n";
    priority_queue<int,vector<int>,greater<int>> minheap; // This is min heap.

    minheap.push(4);
    minheap.push(2);
    minheap.push(5);
    minheap.push(3);

    cout << "element at Top " << minheap.top() << endl;
    minheap.pop();
    cout << "element at Top " << minheap.top() << endl;
    cout << "Size is " << minheap.size() << endl;
    cout <<  minheap.empty() << endl;
    
    return 0;
}