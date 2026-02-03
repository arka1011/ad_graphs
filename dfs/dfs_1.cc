#include <iostream>
#include <vector>

using namespace std;

void dfs (int st, vector<vector<int>>& adj, vector<bool>& visited) {
    cout << st << " ";
    visited[st] = true;
    for (int n:adj[st]) {
        if (!visited[n]) {
            dfs(n,adj,visited);
        }
    }
}

int main () {
    vector<vector<int>> adj = {
        {1, 2},    // neighbors of 0
        {0, 3, 4}, // neighbors of 1
        {0},       // neighbors of 2
        {1},       // neighbors of 3
        {1}        // neighbors of 4
    };

    vector<bool> visited(adj.size(),false);

    dfs(0, adj, visited);
}