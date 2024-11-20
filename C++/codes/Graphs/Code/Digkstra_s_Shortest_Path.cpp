// https://www.codingninjas.com/studio/problems/dijkstra-s-shortest-path_920469?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
// T.C. = O(ElogV) where E = edges and v = vertices
// S.C. = O(N+E)

#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    unordered_map<int,list<pair<int,int>>> adjList;

    // Adjacency List
    for (int i=0;i<vec.size();i++) {
        int u = vec[i][0];
        int v = vec[i][1];
        int weight = vec[i][2];

        adjList[u].push_back(make_pair(weight,v));
        adjList[v].push_back(make_pair(weight,u));
    }

    set<pair<int,int>> min;
    vector<int> distance(vertices,INT_MAX);
    distance[source] = 0;
    min.insert(make_pair(0,source));

    while(!min.empty()) {

        // Top record
        auto curr = *(min.begin());

        int node = curr.second;
        int nodeDistance = curr.first;

        // Erasing the top record
        min.erase(min.begin());

        for (auto neighbour:adjList[node]) {
            if (distance[neighbour.second] > neighbour.first+nodeDistance) {

                auto record = min.find(make_pair(distance[neighbour.second],neighbour.second));

                // If record found in the set
                if (record != min.end()) {
                    min.erase(record);
                }

                // Update the record
                distance[neighbour.second] = neighbour.first + nodeDistance;

                // Insert new record in the set
                min.insert(make_pair(distance[neighbour.second],neighbour.second)); 
            }
        }

    }

    return distance;
}
