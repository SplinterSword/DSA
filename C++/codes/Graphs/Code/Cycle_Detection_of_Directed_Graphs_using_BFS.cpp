// https://www.codingninjas.com/studio/problems/detect-cycle-in-a-directed-graph_1062626?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
// Time and Space Complexity = O(linear)

#include <unordered_map>
#include <list>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

bool bfs(unordered_map<int, list<int>> &adjList, vector<int> &indegree, queue<int> &q, int &count) {
    // BFS
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        count++;

        for (auto neighbour : adjList[front]) {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0) {
                q.push(neighbour);
            }
        }
    }

    // count not equal to the number of vertices then return false
    return (count == indegree.size());
}

bool detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges) {
    unordered_map<int, list<int>> adjList;
    // Adjacency List
    for (auto edge : edges) {
        int u = edge.first-1;
        int v = edge.second-1;
        adjList[u].push_back(v);
    }

    // Using BFS / Kahn's Algorithm
    vector<int> indegree(n, 0);
    
    // Find all the indegree of each vertex
    for (auto i : adjList) {
        for (auto j : i.second) {
            indegree[j]++;
        }
    }

    queue<int> q;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    return !bfs(adjList, indegree, q, count);  // Return true if a cycle is detected
}
