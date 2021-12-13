// https://cses.fi/problemset/task/1679

#include<bits/stdc++.h>
using namespace std;

vector<int>v;
void dfs(int s,vector<int> & vis,vector<int> adj[]){
    if (vis[s]) return;
    vis[s]=1;
    for (auto i: adj[s]) dfs(i,vis,adj);
    v.push_back(s);
}

int v1[100005];
bool cycle(int s,vector<int> adj[]){
    v1[s]=1;
    for (auto i: adj[s]){
        if (!v1[i]){
            if (cycle(i,adj)) return 1;
        }
        else if (v1[i]==1) return 1; //cycle exists
    }
    v1[s] = 2;
    return 0;
}

int main(){

    int n,m;
    cin>>n>>m;
    vector<int> adjList[n+1];
    while(m--){
        int a,b;
        cin>>a>>b;
        adjList[a].push_back(b);
    }
    vector<int> vis(100005,0);
    for(int i=1;i<=n;i++){
        if (!v1[i] && cycle(i,adjList)){
            cout<<"IMPOSSIBLE"; return 0;
        }
        if (!vis[i]) dfs(i,vis,adjList);
    }
    reverse(v.begin(),v.end());
   for (auto i: v){
       cout<<i<<" ";
   }

   return 0;
}