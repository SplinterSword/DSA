// Breadth first Search
// https://www.codingninjas.com/studio/problems/bfs-in-graph_973002?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

// T.C. = O(n)
// S.C. = O(n)

void bfs(vector<vector<int>> &adj, unordered_map<int, bool> &visited, int node, vector<int> &ans){
    queue<int> q;
    q.push(node);

    // Breath first search triversal
    while(!q.empty()){
        int front = q.front();
        ans.push_back(front);
        visited[front] = true;
        q.pop();

        // Checking each neighbour of the current element
        for (int i=0;i<adj[front].size();i++){
            int neighbour = adj[front][i];
            if (!visited[neighbour]){
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
}
vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    
    vector<int> ans;
    unordered_map<int, bool> visited;

    // Checking each node and then applying bfs
    for (int i=0;i<n;i++){
        if (!visited[i]){
            bfs(adj,visited,i,ans);
        }
    }

    return ans;
}