#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

void dijkstra (int st, vector<vector<pair<int,int>>>& adj, vector<int>& dist) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq; // dist node

    pq.push({0,st});
    dist[st] = 0;

    while (!pq.empty()) {
        auto [d,u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [v,w]:adj[u]) {
            if (dist[u]+w < dist[v]) {
                dist[v] = dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }
}


int main() {
    int V = 5;

    // Adjacency list: {neighbor, weight}
    vector<vector<pair<int,int>>> adj(V);

    // Undirected weighted graph
    adj[0].push_back({1, 5});
    adj[1].push_back({0, 5});

    adj[0].push_back({2, 1});
    adj[2].push_back({0, 1});

    adj[1].push_back({3, 2});
    adj[3].push_back({1, 2});

    adj[1].push_back({4, 3});
    adj[4].push_back({1, 3});

    vector<int> dist(V, INT_MAX);

    dijkstra(0, adj, dist);

    cout << "Shortest distances from node 0:\n";
    for (int i = 0; i < V; i++) {
        cout << "0 -> " << i << " = " << dist[i] << "\n";
    }

    return 0;
}
