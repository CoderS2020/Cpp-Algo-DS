//Depth First Search (DFS): Goes in depth and not towards adjacent element like BFS
//Time Complexity: O(n+e) and space complexity: O(n+e)+O(n)+O(n)
#include<bits/stdc++.h>
using namespace std;

class Solution{
    void dfs(int node,vector<int> &vis,vector<int> adj[],vector<int> &storeDfs){
        storeDfs.push_back(node);
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj,storeDfs);
            }
        }

    };
    public:
        vector<int> dfsOfGraph(int v, vector<int> adj[]){
            vector<int> storeDfs;
            vector<int> vis(v+1,0);

            for(int i=1;i<=v;i++){
                if(!vis[i]){
                    dfs(i,vis,adj,storeDfs);
                }
            }
            return storeDfs;
        }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int v,e;
        cin>>v>>e;

        vector <int> adjList[v+1];
        for(int i=1;i<=e;i++){
            int first,second;
            cin>>first>>second;
            adjList[first].push_back(second);
            adjList[second].push_back(first);
            
        }
        Solution obj;
        vector<int> dfsAns=obj.dfsOfGraph(v,adjList);

        for(auto it=dfsAns.begin();it!=dfsAns.end();it++){
            cout<<*it<<" ";
        }

        
        
    }


    return 0;
}