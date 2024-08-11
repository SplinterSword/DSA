// https://www.naukri.com/code360/problems/count-strongly-connected-components-kosaraju-s-algorithm_1171151?leftPanelTab=0
// T.C. = O(V+E)
// S.C. = O(V+E)

#include <bits/stdc++.h>

void TopoLogicalSort(unordered_map<int,list<int>> &adjList,vector<bool> &visited, int node, queue<int> &q) {
	visited[node] = true;

	for (auto neighbour: adjList[node]) {
		if (!visited[neighbour]) {
			TopoLogicalSort(adjList, visited, neighbour, q)
		}
	}

	q.push(node);
} 

void dfs(unordered_map<int,list<int>> &adjList,vector<bool> &visited, int node) {
	visited[node] = true;

	for (auto neighbour: adjList[node]) {
		if (!visited[neighbour]) {
			TopoLogicalSort(adjList, visited, neighbour, q)
		}
	}
}  

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	unordered_map<int,list<int>> adjList;

	for (int i=0;i<edges.size();i++) {
		int u = edges[i][0];
		int v = edges[i][1];

		// Directed Graph
		adjList[u].push_back(v);
	}

	// TopoLogical Sort
	// we are using queue instead of stack to avoid transposing the graph later on
	queue<int> q;
	vector<bool> visited(v,0);

	for (int i=0;i<v;i++){
		if (!visited[i]) {
			TopoLogicalSort(adjList,visited,i,q);
		}
	}

	// Reset the visited to use again
	for (int i=0;i<v;i++){
		visited[i] = 0;
	}

	// Dfs Reversed;
	int ans = 0;

	while (!q.empty()) {
		int front = q.front();
		q.pop();

		if (!visited[front]) {
			dfs(adjList, visited, node);
			ans++;
		}
	}

	return ans;
}