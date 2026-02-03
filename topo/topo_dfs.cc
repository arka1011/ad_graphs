#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool dfs(int u,
         vector<vector<int>>& adj,
         vector<int>& state,
         vector<int>& topo) {
    state[u] = 1; // visiting

    for (int v : adj[u]) {
        if (state[v] == 0) {
            if (!dfs(v, adj, state, topo))
                return false;
        }
        else if (state[v] == 1) {
            // back-edge found → cycle
            return false;
        }
    }

    state[u] = 2; // done
    topo.push_back(u);
    return true;
}

vector<int> topoSort(vector<vector<int>>& adj) {
    int V = adj.size();
    vector<int> topo;
    vector<int> state(V, 0);

    for (int i = 0; i < V; i++) {
        if (state[i] == 0) {
            if (!dfs(i, adj, state, topo)) {
                // cycle detected
                return {};
            }
        }
    }

    reverse(topo.begin(), topo.end());
    return topo;
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
        adj[u].push_back(v);
    }

    vector<int> topo = topoSort(adj);

    if (topo.empty()) {
        cout << "Cycle detected! Topological sort not possible.\n";
    } else {
        cout << "Topological order:\n";
        for (int x : topo)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}
