#include <iostream>
#include <vector>

using namespace std;

bool dfs(int st, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& recStack) {
    visited[st] = true;
    recStack[st] = true;

    for (int n:adj[st]) {
        if (!visited[n]) {
            if (dfs(n,adj,visited,recStack)) {
                return true;
            }
        } else if (recStack[n]) {
            return true;
        }
    }

    recStack[st] = false;
    return false;
}

bool hasCycle(vector<vector<int>>& adj) {
    int V = adj.size();
    vector<bool> visited(V,false);
    vector<bool> recStack(V,false);

    for (int i=0; i<V; i++) {
        if (!visited[i]) {
            if (dfs(i,adj,visited,recStack)) {
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

    cout << "Enter edges (u v) where u -> v:\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // directed edge
    }

    if (hasCycle(adj))
        cout << "Graph contains a cycle\n";
    else
        cout << "Graph does NOT contain a cycle\n";

    return 0;
}