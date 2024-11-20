// https://naukri.com/code360/problems/bridges-in-graph_893026?leftPanelTab=0&leftPanelTabValue=SUBMISSION
// T.C. = O(V+E)
// S.C. = O(V)

#include <bits/stdc++.h>
using namespace std;

void dfs(unordered_map<int,list<int>> &adjList, vector<int> &parent, vector<bool> &visited, vector<int> &dist, vector<int> &low, int node, int &counter, vector<vector<int>> &ans) {
            dist[node] = counter;
            low[node] = counter;
            visited[node] = true;
            counter++;

            for (auto neighbour : adjList[node]) {

                if (!visited[neighbour]) {
                    parent[neighbour] = node;
                    dfs(adjList, parent, visited, dist, low, neighbour, counter, ans);
                }
                if (parent[node] == neighbour) {
                    continue;
                }
                
                low[node] = min(low[node],low[neighbour]);
                
                if (dist[node] < low[neighbour]) {
                    vector<int> temp{node,neighbour};
                    ans.push_back(temp);
                }
            }

        }

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // Write your code here
    unordered_map<int,list<int>> adjList;

    for (int i=0;i<edges.size();i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<int> parent(v,-1);
    vector<bool> visited(v,0);
    vector<int> dist(v,INT_MAX);
    vector<int> low(v,INT_MAX);

    vector<vector<int>> ans;

    int counter = 0;
    dfs(adjList,parent,visited,dist,low,0,counter,ans);

    return ans;
}