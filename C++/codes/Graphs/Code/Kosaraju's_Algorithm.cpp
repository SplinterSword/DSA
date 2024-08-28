#include <bits/stdc++.h>
using namespace std;

void TopoLogicalSort(unordered_map<int, list<int>> &adjList, vector<bool> &visited, int node, stack<int> &s) {
    visited[node] = true;

    for (auto neighbour: adjList[node]) {
        if (!visited[neighbour]) {
            TopoLogicalSort(adjList, visited, neighbour, s);
        }
    }

    s.push(node);
}

void dfs(unordered_map<int, list<int>> &adjList, vector<bool> &visited, int node) {
    visited[node] = true;

    for (auto neighbour: adjList[node]) {
        if (!visited[neighbour]) {
            dfs(adjList, visited, neighbour);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges) {
    unordered_map<int, list<int>> adjList;

    // Build the original graph
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
    }

    // TopoLogical Sort using a stack
    stack<int> s;
    vector<bool> visited(v, false);

    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            TopoLogicalSort(adjList, visited, i, s);
        }
    }

    // Transpose the graph
    unordered_map<int, list<int>> transposeAdjList;

    for (int i = 0; i < v; i++) {
        for (auto neighbour : adjList[i]) {
            transposeAdjList[neighbour].push_back(i);
        }
    }

    // Reset visited to use again
    fill(visited.begin(), visited.end(), false);

    // Perform DFS on the transposed graph in the order defined by the stack
    int ans = 0;

    while (!s.empty()) {
        int node = s.top();
        s.pop();

        if (!visited[node]) {
            dfs(transposeAdjList, visited, node);
            ans++;
        }
    }

    return ans;
}
