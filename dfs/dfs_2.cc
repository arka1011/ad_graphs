#include <iostream>
#include <vector>

using namespace std;

void dfs (int st, vector<vector<int>>& adj, vector<bool>& visited) {
    cout << st << " ";
    visited[st] = true;
    for (int i=0; i<adj.size(); i++) {
        if (adj[st][i] == 1 && !visited[i]) {
            dfs(i,adj,visited);
        }
    }
}

int main () {
    vector<vector<int>> adj = {
        //0  1  2  3  4
        { 0, 1, 1, 0, 0 }, // 0
        { 1, 0, 0, 1, 1 }, // 1
        { 1, 0, 0, 0, 0 }, // 2
        { 0, 1, 0, 0, 0 }, // 3
        { 0, 1, 0, 0, 0 }  // 4
    };

    vector<bool> visited(adj.size(),false);

    dfs(0, adj, visited);
}