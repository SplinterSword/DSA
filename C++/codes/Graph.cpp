#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class graph
{
    public:
    unordered_map<int,list<int>> adj;

    void addEdge(int u,int v,bool direction)
    {
        adj[u].push_back(v);
        
        if (direction == 0)
        {
           adj[v].push_back(u); 
        }
    }

    void printAdjList()
    {
        for(auto i:adj)
        {
            cout << i.first << " ";
            for (auto j:i.second)
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

int main()
{
    graph p;
    p.addEdge(5,2,0);
    p.printAdjList();
}