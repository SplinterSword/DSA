// https://www.naukri.com/code360/problems/create-a-graph-and-print-it_1214551?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&leftPanelTabValue=SUBMISSION

#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
using namespace std;

class graph {
    private:
        unordered_map<int,list<int>> adjList;
    public:
        void addEdgeList(int u,int v,bool direction){
            // direction = 0 for undirected
            // direction = 1 for directd graph
            adjList[u].push_back(v);
            if (direction == 0){
                adjList[v].push_back(u);
            }
        }

        void printGraph(){

            // List Part
            for (auto i:adjList){
                cout << i.first << "->";
                for (auto j:i.second){
                    cout << j << ", ";
                }
                cout << endl;
            }

        }
};

int main() {
    int vertices;
    cout << "Enter the number of vertices: ";
    cin >> vertices;

    int edges;
    cout << "Enter the number of Edges: ";
    cin >> edges;

    vector<vector<int>> adjMatrix(vertices,vector<int>(vertices,0));
    cout << "Enter the edges:\n";
    graph g;

    for (int i=0;i<edges;i++){
        int u,v;
        cin >> u >> v;
        g.addEdgeList(u,v,0);
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    g.printGraph();

    // Matrix Part
        for (int i=0;i<adjMatrix.size();i++){
            cout << i << "->";
            for (int j=0;j<adjMatrix.size();j++){
                if (adjMatrix[i][j] == 1){
                    cout << j << ", ";
                }
            }
            cout << endl;
        }
}