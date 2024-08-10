// https://www.naukri.com/code360/problems/minimum-spanning-tree_631769?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&leftPanelTabValue=PROBLEM
// T.C. = O(ElogE + ElogV)


#include <bits/stdc++.h>

bool cmp(vector<int> &a,vector<int> &b) {
  return a[2] < b[2];
}

int findParent(vector<int> &parent, int node) {
  if (parent[node] == node) {
    return node;
  }
  return parent[node] = findParent(parent, parent[node]);
}

void unionSet (int u,int v, vector<int> &parent, vector<int> &rank) {
  u = findParent(parent, u);
  v = findParent(parent, v);

  if (rank[u] < rank[v]) {
    parent[u] = v;
    rank[v]++;
  }
  else if (rank[v] < rank[u]) {
    parent[v] = u;
    rank[u]++;
  }
  else {
    parent[v] = u;
    rank[u]++;
  }
}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  sort(edges.begin(),edges.end(),cmp);
  vector<int> parent(n);
  vector<int> rank(n);

  // Initialising Parent Array
  for (int i=0 ;i<n; i++) {
    parent[i] = i;
  }
  
  int minWeight = 0;

  for(int i=0;i<edges.size();i++) {
    int u = edges[i][0];
    int v = edges[i][1];
    int w = edges[i][2];

    u = findParent(parent, u);
    v = findParent(parent, v);

    if (u != v) {
      minWeight += w;
      unionSet(u, v, parent, rank);
    }
  }

  return minWeight;
}