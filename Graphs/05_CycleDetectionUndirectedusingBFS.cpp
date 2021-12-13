//Detect a cycle in Undirected Graph using BFS
//Time complexity:O(n+e), Space complexity: O(n+e)+O(n)+O(n)
#include<bits/stdc++.h>
using namespace std;


class Solution{

    bool checkForCycle(int s,int v,vector<int> adj[],vector<int> &vis){
        queue<pair<int,int>> q; //The current value and its parent/previous value
        vis[s]=1;
        q.push({s,-1}); //First element does not have any parent

        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();

            for(auto it:adj[node]){
                if(!vis[it]){
                    q.push({it,node});
                    vis[it]=1;
                }
                else if(parent!=it){ // if it is already visited and it is not equal to the parent (check if edges in both directions i.e. u->v , v->u)
                    return true;
                }
            }
        }
        return false;

    }

    public:
        bool isCycle(int v,vector<int> adjList[]){
            vector<int> vis(v+1,0);
            for(int i=1;i<=v;i++){
                if(!vis[i]){
                    //Although it is disconnected , but even if we get one cycle then also it returns true i.e. cycle exists
                    if(checkForCycle(i,v,adjList,vis)) return true;
                }
            }
            return false;
        }
};

int main(){
    int v,e;
    cin>>v>>e;
    vector<int> adjList[v+1];
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    Solution obj;
    if(obj.isCycle(v,adjList)){
        cout<<"Cycle exists";
    }
    else{
        cout<<"Cycle does not exist";
    }
   return 0;
}