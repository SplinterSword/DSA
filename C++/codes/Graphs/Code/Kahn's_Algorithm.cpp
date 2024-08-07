// It is the bfs way to find the topological sort of the graph
// T.C. = O(N+E) (linear)
// S.C. = O(N)   (linear)

#include <bits/stdc++.h> 

void makeAdjList(vector<vector<int>> &edges, unordered_map<int,list<int>> &adjList, vector<int> &indegree){
    for (int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        // Finding all the indegrees
        indegree[v]++;
    }
}

void bfs(unordered_map<int,list<int>> &adjList, vector<int> &ans, vector<int> &indegree, queue<int> &q){

    while (!q.empty()){
        int front = q.front();
        ans.push_back(front);
        q.pop();

        for (auto neighbour : adjList[front]){
            indegree[neighbour]--;
            // Pushing the node only when the indegree is 0
            if (indegree[neighbour] == 0){
                q.push(neighbour);
            }
        }
    }

    return;
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Using Kahn's Algorithm(BFS Trivarsal)

    // Fort Storing the indegree of each node
    vector<int> indegree(v,0);

    unordered_map<int,list<int>> adjList;
    makeAdjList(edges,adjList,indegree);
    vector<int> ans;

    queue <int> q;
    for (int i = 0; i<v;i++){
        if (indegree[i] == 0){
            q.push(i);
        }
    }

    bfs(adjList,ans,indegree,q);
    

    return ans;
}