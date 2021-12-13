//https://cses.fi/problemset/task/1667

#include<bits/stdc++.h>
using namespace std;

void bfs(int start,int end,vector<int> adjList[], vector<bool> & vis, vector<int> & parent){
    vis[start]=true;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto it: adjList[u]){
            if(!vis[it]){
                q.push(it);
                vis[it]=true;
                parent[it]=u;
            }
        }
    }
}

int main(){

    int n,m;
    cin>>n>>m;
    vector<int> adjList[n+1];

    while(m--){
        int a,b;
        cin>>a>>b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    vector<bool>vis(n+1,false);
    vector<int> par(n+1,-1);
    bfs(1,n,adjList,vis,par);

    if(par[n] == -1)
	{
		cout <<  "IMPOSSIBLE";
		return 0;
	}

    // /From end to start
    int current_node=n;
    stack<int> st;
    while(current_node!=-1){
        st.push(current_node);
        current_node=par[current_node];
    }
    cout<<st.size()<<endl;
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

   return 0;
}