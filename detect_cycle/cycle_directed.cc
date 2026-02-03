#include <iostream>
#include <vector>

using namespace std;

bool dfs(int st, vector<vector<int>>& adj, vector<bool>& recStack) {

}

bool hasCycle(vector<vector<int>>& adj) {

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