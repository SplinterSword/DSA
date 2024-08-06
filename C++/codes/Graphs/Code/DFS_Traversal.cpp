// Depth first Search
// https://www.codingninjas.com/studio/problems/dfs-traversal_630462?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

// T.C. = O(n)
// S.C. = O(n)

#include <unordered_map>
#include <queue>
#include <vector>

void makeAdjList(int E, vector<vector<int>> &edges, unordered_map<int,list<int>> &adjList){
    for (int i=0 ;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

void makeAdjMatrix(vector<vector<int>> &adjMatrix, vector<vector<int>> &edges){

    for (int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

}

void dfsList(unordered_map<int,list<int>> &adjList,unordered_map<int,bool> &visited, int node, vector<int> &curr){
    curr.push_back(node);
    visited[node] = true;

    for (auto neighbour : adjList[node]){
        if (!visited[neighbour]){
            dfsList(adjList, visited, neighbour, curr);
        }
    }
    return;
}

void dfsMatrix(vector<vector<int>> &adjMatrix,unordered_map<int,bool> &visited, int node, vector<int> &curr){
    curr.push_back(node);
    visited[node] = true;

    for (int i=0;i<adjMatrix.size();i++){
        if (adjMatrix[node][i] == 1){
            if (!visited[i]){
                dfsMatrix(adjMatrix, visited, i, curr);
            }
        }
    }
    return;
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    unordered_map<int,list<int>> adjList;
    vector<vector<int>> adjMatrix (V,vector<int>(V,0));

    makeAdjList(E,edges,adjList);
    makeAdjMatrix(adjMatrix,edges);

    // To check whether the graph is visited or not
    unordered_map<int,bool> visited;

    vector<vector<int>> ans;

    // Using Adjacency List (better approach)
    // for (int i=0;i<V;i++){
    //     // To store each component of a graph
    //     if (!visited[i]){
    //         vector<int> curr;
    //         dfsList(adjList,visited,i,curr);
    //         ans.push_back(curr);
    //     }
    // }

    // Using Adjacency Matrix
    for (int i=0;i<V;i++){
        // To store each component of a graph
        if (!visited[i]){
            vector<int> curr;
            dfsMatrix(adjMatrix,visited,i,curr);
            ans.push_back(curr);
        }
    }

    return ans;
}