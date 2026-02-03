#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> topoSort (vector<vector<int>>& adj) {
    vector<int> res;
    queue<int> q;

    int V = adj.size();
    vector<int> indegree(V,0);

    for (int i=0; i<V; i++) {
        for (int v:adj[i]) {
            indegree[v]++;
        }
    }

    for (int i=0; i<V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        res.push_back(u);

        for (int v:adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    if (res.size() != V) {
        return {};
    }

    return res;
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