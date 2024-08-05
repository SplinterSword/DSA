// https://www.naukri.com/code360/problems/create-a-graph-and-print-it_1214551?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&leftPanelTabValue=SUBMISSION

#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

class graph {
    public:
    unordered_map<int,list<int>> adj;

    void addEdge(int u,int v, bool direction) {
        // direction = 0 -> undirected
        // direction = 1 -> directed graph

        // create an edge from u to v
        adj[u].push_back(v);
        if (direction == 0){
            adj[v].push_back(u);
        }
    }

    void printAdjList() {
        for (auto i:adj){
            cout << i.first << "->";
            for (auto j: i.second) {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

int main(){
    
    int vertices;
    cout << "Enter the number of vertices: ";
    cin >> vertices;

    int edges;
    cout << "Enter the number of edges: ";
    cin >> edges;
    vector<vector<int>> adjMatrix(vertices,vector<int>(vertices,0));
    graph g;

    for (int i=0;i<edges;i++){
        int u, v;
        cin >> u >> v;

        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;

        // Creating an undirected graph (adjList)
        g.addEdge(u,v,0);
    }

    //printing a graph
    g.printAdjList();

    // printing adjcency matrix
    for (int i=0;i<vertices;i++){
        cout << i << "-> ";
        for (int j=0;j<vertices;j++){
            if (adjMatrix[i][j] == 1){
                cout << j << ", ";
            }
        }
        cout << endl;
    }
}