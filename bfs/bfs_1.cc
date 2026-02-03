// bfs with adj list

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs (int st, const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n,false);

    queue<int> Q;

    Q.push(st);
    visited[st] = true;

    while (!Q.empty()) {
        int node = Q.front();
        Q.pop();

        cout << node << " ";

        for (int nei:adj[node]) {
            if (!visited[nei]) {
                visited[nei] = true;
                Q.push(nei);
            }
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

    bfs(0, adj);
}