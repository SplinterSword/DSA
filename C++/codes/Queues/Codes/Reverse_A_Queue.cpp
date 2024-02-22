#include <iostream>
#include <queue>
using namespace std;

queue<int> reverse(queue<int> query)
{
    if (query.empty())
    {
        return query;
    }

    int temp = query.front();
    query.pop();

    query = reverse(query);

    query.push(temp);

    return query;
}

int main()
{
    queue<int> query;
    query.push(1);
    query.push(2);
    query.push(3);
    query.push(4);
    query.push(5);
    query = reverse(query);
    cout << query.front() << endl;
    return 0;
}