// Undirected Graph
// https://www.codingninjas.com/studio/problems/cycle-detection-in-undirected-graph_1062670?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

// T.C. = O(n)
// S.C. = O(n)

#include <unordered_map>
#include <list>
#include <queue>
#include <vector>
#include <string>

using namespace std;

#include <unordered_map>
#include <list>
#include <queue>


void makeAdjList(vector<vector<int>>& edges, unordered_map<int,list<int>> &adjList){
    for (int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

bool bfs(unordered_map<int,list<int>> &adjList, unordered_map<int,bool> &visited, int node){
    unordered_map<int,int> parent;
    
    parent[node] = -1;
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty()){
        int front = q.front();
        q.pop();

        for (auto neighbour:adjList[front]){
            if (visited[neighbour] && neighbour != parent[front]){
                return true;
            }
            else if (!visited[neighbour]){
                visited[neighbour] = true;
                parent[neighbour] = front;
                q.push(neighbour);
            }
        }

    }
    return false;
}

bool dfs(unordered_map<int,list<int>> &adjList, unordered_map<int,bool> &visited, int node , int parent){

    visited[node] = true;

    for (auto neighbour:adjList[node]){

        if (visited[neighbour] && neighbour != parent){
            return true;
        }
        else if (!visited[neighbour]){
            bool ans = dfs(adjList, visited, neighbour, node);
            if (ans == 1){
                return true;
            }
        }
    }

    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int,list<int>> adjList;
    makeAdjList(edges,adjList);

    unordered_map<int,bool> visited;

    // Using BFS
    // for (int i=0;i<n;i++){
    //     if (!visited[i]){
    //         bool isCyclic = bfs(adjList,visited,i);
    //         if (isCyclic){
    //             return "Yes";
    //         }
    //     }
    // }


    // Using DFS
    for (int i=0;i<n;i++){
        if (!visited[i]){
            bool isCyclic = dfs(adjList,visited,i,-1);
            if (isCyclic){
                return "Yes";
            }
        }
    }

    return "No";
}


// Directed Graph
// https://www.codingninjas.com/studio/problems/detect-cycle-in-a-directed-graph_1062626?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

#include <unordered_map>
#include <list>

bool dfs(unordered_map<int,bool> &visited, unordered_map<int,bool> &dfsVisited, unordered_map<int,list<int>> &adjList, int node){
    visited[node] = true;
    dfsVisited[node] = true;

    for (auto neighbour : adjList[node]){
        if (!visited[neighbour]){
            bool ans = dfs(visited, dfsVisited, adjList, neighbour);
            if (ans == 1){
                return true;
            }
        }
        else if (dfsVisited[neighbour]){
            return true;
        }
    }

    dfsVisited[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    unordered_map<int,list<int>> adjList;
    // Adjacency List
    for (auto edge:edges){
        int u = edge.first;
        int v = edge.second;

        adjList[u].push_back(v);
    }

    // Using DFS
    unordered_map<int,bool> visited;
    unordered_map<int,bool> dfsVisited;

    for (int i=0 ;i<n;i++){
        if (!visited[i]){
            bool isCyclic = dfs(visited,dfsVisited,adjList,i);
            if (isCyclic){
                return true;
            }
        }
    }

    return false;
}