#include <bits/stdc++.h>
using namespace std;

int bfs(vector<vector<int>>& adj, int& d) {
    int count = 0, level = 0;
    deque<int> deque;
    vector<bool> inserted(adj.size(), false);
    deque.push_back(1);
    inserted[1] = true;
    
    while(!deque.empty()) {
        if(level > d) break;
        int size = deque.size();
        count += size;
        for(int i=0; i<size; i++) {
            int temp = deque.front(); deque.pop_front();
            for(int& ngb : adj[temp])
                if(!inserted[ngb]) {
                    deque.push_back(ngb);
                    inserted[ngb] = true;
                }
        } level++;
    } return count;
}

int main() {
    int n, m, d; cin>>n>>m>>d;
    vector<vector<int>> adj(n+1);
    for(int i=1; i<=m; i++) {
        int src, dst; cin>>src>>dst;
        adj[src].push_back(dst);
        adj[dst].push_back(src);
    }
    cout << bfs(adj, d) << endl;
    return 0;
}
