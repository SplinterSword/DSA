// Prim's Algorithm is used to find the minimum spanning tree in the graph
// Mininum Spanning Tree has 2 conditions :-
// there should be n nodes and n-1 edges
// you can reach any node from any other node

// https://www.naukri.com/code360/problems/prim-s-mst_1095633?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&leftPanelTabValue=PROBLEM

#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int,list<pair<int,int>>> adjList;

    // Adjacency List
    for (int i=0;i<m; i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adjList[u].push_back(make_pair(v,w));
        adjList[v].push_back(make_pair(u,w));
    }

    vector<int> key(n+1,INT_MAX);
    vector<bool> mst(n+1,0);
    vector<int> parent(n+1,-1);
    set<pair<int,int>> minh;

    // Algo
    key[1] = 0;
    parent[1] = -1;
    minh.insert(make_pair(key[1],1));

    while(!minh.empty()) {
        auto curr = *(minh.begin());

        int mini = curr.first;
        int u = curr.second;

        minh.erase(minh.begin());

        // mark min node as true
        mst[u] = true;

        // check its adjacent nodes;

        for (auto it: adjList[u]) {
            int v = it.first;
            int w = it.second;

            if (mst[v] == false && w < key[v]) {
                parent[v] = u;
                key[v] = w;
                minh.insert(make_pair(key[v],v));
            }
        }
    }    

    vector<pair<pair<int,int>, int>> result;
    for (int i=2; i<=n; i++) {
        result.push_back(make_pair(make_pair(parent[i],i),key[i]));
    }

    return result;
}
