// bfs with adj matrix

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs (int st, const vector<vector<int>>& adj) {
    vector<bool> visited(adj.size(), false);
    queue<int> q;

    visited[st] = true;
    q.push(st);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int i=0; i<adj.size(); i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    vector<vector<int>> adj = {
        //0  1  2  3  4
        { 0, 1, 1, 0, 0 }, // 0
        { 1, 0, 0, 1, 1 }, // 1
        { 1, 0, 0, 0, 0 }, // 2
        { 0, 1, 0, 0, 0 }, // 3
        { 0, 1, 0, 0, 0 }  // 4
    };

    bfs(0, adj);
}