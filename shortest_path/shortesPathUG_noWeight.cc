#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void shortestPathUG (int st, vector<vector<int>>& adj, vector<int>& dist) {
    int n = adj.size();
    queue<int> q;

    q.push(st);
    dist[st] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int i=0; i<n; i++) {
            if (adj[node][i] != 0 && dist[i] == -1) {
                dist[i] = dist[node]+1;
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

    vector<int> dist(adj.size(),-1);

    shortestPathUG(0, adj, dist);

    for (int d : dist) cout << d << " ";
}