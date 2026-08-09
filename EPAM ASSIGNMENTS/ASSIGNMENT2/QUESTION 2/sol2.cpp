#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
void bfs(int st,vector<vector<int>>&adj,vector<int>&vis,int d){
      queue<int>q;
      q.push(st);
      int cnt=0;
      while(!q.empty()){
        if(cnt==d) break;
        cnt++;
        int size=q.size();
        for(int k=0;k<size;k++){
            int i=q.front();
            q.pop();
            vis[i]=1;
            for(int j=0;j<adj[i].size();j++){
                   if(!vis[adj[i][j]]){
                    q.push(adj[i][j]);
                    vis[adj[i][j]]=1;
                   }
            }
        }
      }
}
int main(){
    int n;
    cout<<"Enter n=";
    cin>>n;
    int m;
    cout<<"Enter m=";
    cin>>m;
    int d;
    cout<<"Enter d=";
    cin>>d;
    int a,b;
    int ans=0;
    vector<vector<int>>adj(n+1);
    cout<<"Enter edges:";
    vector<int>vis(n+1,0);
    for(int i=0;i<m;i++){
        cin>>a>>b;
        if(a!=b){
        adj[a].push_back(b);
        adj[b].push_back(a);
        }
    }
    bfs(1,adj,vis,d);
    for(int i=1;i<=n;i++){
           if(vis[i]==1) ans++;
    }
    cout<<"output="<<ans;
}