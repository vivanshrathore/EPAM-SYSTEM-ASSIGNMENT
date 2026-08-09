#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, long long xorr, long long K,
         long long &count, vector<long long> &keys,
         vector<vector<int>> &adj) {

    // Check current node
    if (xorr >= K)
        count++;

    // Visit all adjacent nodes
    for (int ngb : adj[node]) {
        if (ngb != parent) {
            
            dfs(ngb, node, xorr ^ keys[ngb],
                K, count, keys, adj);
        }
    }
}

int main() {
    int N;
    long long K;

    cin >> N >> K;

    vector<long long> keys(N + 1);
    vector<vector<int>> adj(N + 1);

    // Input security keys
    for (int i = 1; i <= N; i++) {
        cin >> keys[i];
    }

    // Input tree edges
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    long long count = 0;

    // Root is node 1, so start XOR with keys[1]
    dfs(1, -1, keys[1], K, count, keys, adj);

    cout << count << endl;

    return 0;
}