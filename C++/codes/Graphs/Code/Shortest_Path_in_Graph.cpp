// Unidirected Graph
// https://www.codingninjas.com/studio/problems/shortest-path-in-an-unweighted-graph_981297?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
// T.C. = O(n+e)
// S.C. = O(n+e)

#include <unordered_map>
#include <queue>
#include <list>

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	unordered_map<int,list<int>> adj;

	for(int i=0; i<edges.size(); i++)
	{
		int u = edges[i].first;
		int v = edges[i].second;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// do bfs
	unordered_map<int,bool> visited;
	unordered_map<int,int> parent;
	queue<int> q;
	q.push(s);
	parent[s] = -1;
	visited[s] = true;

	while(!q.empty())
	{
		int front = q.front();
		q.pop();

		for(auto i: adj[front])
		{
			if(!visited[i])
			{
				visited[i] = true;
				parent[i] = front;
				q.push(i);
			}
		}
	}
	
	// prepare shortest path
	vector<int> ans;
	int currentNode = t;
	ans.push_back(t);

	while(currentNode != s)
	{
		currentNode = parent[currentNode];
		ans.push_back(currentNode);
	}

	reverse(ans.begin(),ans.end());

	return ans;
}


// Directed Graph
//C++ program to find the Shortest Path in a DAG

#include <bits/stdc++.h>

using namespace std;

 

// Graph class implemented using an adjacency list

class Graph{
public:
    int V;  // Number of Vertices
    int E;  // Number of Edges
    vector<pair<int, int>> *adj; // adjacency list

    Graph(int num_vertices, int num_edges){
        this->V = num_vertices;
        this->E = num_edges;
        this->adj = new vector<pair<int, int>>[num_vertices];
    }

    // function to add Edge
    void addEdge(int u, int v, int w){
        adj[u].push_back({v, w});
    }

    // function that returns the topSort ordering of nodes in a graph
    vector<int> topSort(int src){
        //inDegree vector
        vector<int> indegree(V, 0);
        // update the indegree of each node in the graph
        for(int i=0;i<V;++i){
            for(pair<int, int> node:this->adj[i]){
                indegree[node.first]++;
            }
        }
        // queue 
        queue<int> q;
        // push all nodes with 0 in degree in the queue
        for(int i=0;i<V;++i){
            if(indegree[i]==0)
                q.push(i);
        }
        // vector to store topSortOrdering        
        vector<int> topSortOrdering;
        // run until queue is empty
        while(!q.empty()){
            // pop the front node
            int u = q.front();
            q.pop();
            // since it has 0 indegree it will occur before all elements 
            // with non-0 indegree currently
            topSortOrdering.push_back(u);
            // decrement the indegree of adjacent nodes of the popped node 
            // by 1
            for(pair<int, int> node:this->adj[u]){
                indegree[node.first]--;
                // if the indegree of the node is 0
                if(indegree[node.first]==0){
                    // push it to the queue
                    q.push(node.first);
                }
            }
        }
        // return the topSortOrdering        
        return topSortOrdering;
    }

    void findShortestPathInDAG(int src){
        
        vector<int> distances(V, INT_MAX);
        vector<int> topSortOrdering = topSort(src);
        distances[src]=0;

        for(int x:topSortOrdering){
            if(distances[x]!=INT_MAX){
                for(pair<int, int> adjNode : this->adj[x]){
                    if(distances[adjNode.first] > distances[x]+adjNode.second){
                        distances[adjNode.first] = distances[x]+adjNode.second;
                    }
                }   
            }
        }

        cout<<"The distances from the src node are: ";
        for(int i=0;i<V;++i){
            if(distances[i]==INT_MAX) cout<<"INF ";
            else cout<<distances[i]<<" ";
        }
    }
};

int main() {
    int num_vertices = 6;
    int num_edges = 9;

    Graph G(num_vertices, num_edges);

    G.addEdge(1, 3, 6);
    G.addEdge(1, 2, 2);
    G.addEdge(0, 1, 5);
    G.addEdge(0, 2, 3);
    G.addEdge(3, 4, -1);
    G.addEdge(2, 4, 4);
    G.addEdge(2, 5, 2);
    G.addEdge(2, 3, 7);
    G.addEdge(4, 5, -2);

    int src = 1;
    G.findShortestPathInDAG(src);

    return 0;
}
