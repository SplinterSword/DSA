// Articulation points are the points in the graph which when removed divides the graph into 2 or more components
// https://www.naukri.com/code360/library/articulation-points-in-a-graph
// T.C. = O(V+E)
// S.C. = O(V+E)
// Same as the bridge question but only in the if condition checking the for the articulation point / bridge edge
// Also added another condition after the loop ended to handle the condition of the source node (parent = -1)

#include <bits/stdc++.h>
using namespace std;

class ArticulationPoint {
    private:
        void dfs(unordered_map<int,list<int>> &adjList, vector<int> &parent, vector<bool> &visited, vector<int> &dist, vector<int> &low, int node, int &counter, vector<int> &ans) {
            visited[node] = true;
            dist[node] = counter;
            low[node] = counter;
            counter++;

            for (auto neighbour:adjList[node]) {
                if (!visited[neighbour]) {
                    parent[neighbour] = node;
                    dfs(adjList,parent,visited,dist,low,neighbour,counter,ans);
                }
                if (parent[node] == neighbour){
                    continue;
                }

                low[node] = min(low[node],low[neighbour]);
                
                if (dist[node] <= low[neighbour] && parent[node] != -1) {
                    ans.push_back(node);
                }
            }

            if (parent[node] == -1 && adjList[node].size() > 1){
                ans.push_back(node);
            }
        }


    public: 
        vector<int> FindArticulationPoints(vector<vector<int>> &edges, int v, int e) {
            unordered_map<int,list<int>> adjList;

            for (int i=0;i<edges.size();i++) {
                int u = edges[i][0];
                int v = edges[i][1];

                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }

            vector<int> dist(v,INT_MAX);
            vector<int> low(v,INT_MAX);
            vector<bool> visited(v,0);
            vector<int> parent(v,-1);

            vector<int> ans;

            int counter = 0;

            dfs(adjList,parent,visited,dist,low,0,counter,ans);

            return ans;
        }
};