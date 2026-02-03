#include <iostream>
#include <vector>

using namespace std;

bool dfs (int st, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[st] = true;

    for (int n:adj[st]) {
        if (!visited[n]) {
            if (dfs(n,st,adj,visited)) {
                return true;
            }
        } else if (n != parent) {
            return true;
        }
    }
    return false;
}

bool hasCycle(vector<vector<int>>& adj) {
    int V = adj.size();
    vector<bool> visited(V,false);

    for (int i=0; i<V; i++) {
        if (!visited[i]) {
            if (dfs(i,-1,adj,visited)) {
                return true;
            }
        }
    }
    return false;
}
 
int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj(V);

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // because undirected
    }

    if (hasCycle(adj))
        cout << "Graph contains a cycle\n";
    else
        cout << "Graph does NOT contain a cycle\n";

    return 0;
}