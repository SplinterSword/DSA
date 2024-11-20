// https://www.codingninjas.com/studio/problems/topological-sort_982938?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
// T.C. = O(N+E) (linear)
// S.C. = O(N)   (linear)

#include <bits/stdc++.h>
using namespace std;

void makeAdjList(vector<vector<int>> &edges, unordered_map<int,list<int>> &adjList){
    for (int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
    }
}

void dfs (unordered_map<int,list<int>> &adjList, stack<int> &topo, int node, vector<bool> &visited){
    visited[node] = true;

    for (auto neighbour:adjList[node]){
        if (!visited[neighbour]){
            dfs(adjList,topo,neighbour,visited);
        }
    }

    topo.push(node);
    return;
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int,list<int>> adjList;

    makeAdjList(edges,adjList);

    stack<int> topo;
    vector<bool> visited(v);

    for (int i=0;i<v;i++){
        if (!visited[i]){
            dfs(adjList,topo,i,visited);
        }
    }

    vector<int> ans;

    while (!topo.empty()){
        ans.push_back(topo.top());
        topo.pop();
    }

    return ans;
}