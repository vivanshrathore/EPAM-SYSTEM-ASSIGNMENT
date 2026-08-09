#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, int xorr, int& k, int& count, 
    vector<int>& keys, vector<vector<int>>& adj) {
        if(xorr >= k) count++;
        for(int& ngb : adj[node])
            if(ngb != parent)
                dfs(ngb, node, xorr^keys[ngb], k, count, keys, adj);
}

int main() {
    int N, k, count = 0; cin>>N>>k;
    vector<int> keys(N+1, 0); 
    vector<vector<int>> adj(N+1);
    for(int i=1; i<=N; i++) cin>>keys[i];
    for(int i=1; i<=N-1; i++) {
        int src, dst; cin>>src>>dst;
        adj[src].push_back(dst);
        adj[dst].push_back(src);
    }
    dfs(1, -1, 0, k, count, keys, adj);
    cout << count << endl;
    return 0;
}
