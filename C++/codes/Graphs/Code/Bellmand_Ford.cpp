// Shortest Path algorithm like Digkstra's Algorithms
// Unlike Digkstra's Algorithm also works on negetive weights
// But doesn't work with negetive cycle so it can be used to wheter the negetive cycle exist or not
// T.C. = O(V*E)

#include <bits/stdc++.h>

vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
        
    vector<int> distance(n+1,1e9);
    distance[src] = 0;

    for (int i=1;i<=n;i++) {
        // traverse on edge list
        for (int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            if (distance[u] != 1e9 && ((distance[u] + w) < distance[v])) {
                distance[v] = distance[u] + w;
            }
        }
    }

    // Now to check for the negetive cycle
    bool flag = 0;
    for (int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            if (distance[u] != 1e9 && ((distance[u] + w) < distance[v])) {
                flag = true;
                distance[v] = distance[u] + w;
            }
        }
    
    if (flag) {
        return NULL;
    }
    return distance;
}