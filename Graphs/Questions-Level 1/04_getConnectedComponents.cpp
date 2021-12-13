#include<bits/stdc++.h>
using namespace std;

void getConnectedComponentsdfs(int node,vector<pair<int,int>> adjList[], vector<int> & vis, vector<int> &ans){
    vis[node]=1;
    ans.push_back(node);
    for(auto it:adjList[node]){
        if(!vis[it.first]){
            getConnectedComponentsdfs(it.first,adjList,vis,ans);
        }
    }
}

int main(){
    int v,e;
    cin>>v>>e;
    vector<pair<int,int>> adjList[v];
    for(int i=0;i<e;i++){
        int src,dest,weight;
        cin>>src>>dest>>weight;
        adjList[src].push_back(make_pair(dest,weight));
        adjList[dest].push_back(make_pair(src,weight));
    }
    vector<int> vis(v,0);
    vector<vector<int>> finalans;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            vector<int> ans;
            getConnectedComponentsdfs(i,adjList,vis,ans);
            finalans.push_back(ans);
        }
    }
    //2 ways to print vector of vectors
    // for(int i=0;i<finalans.size();i++){
    //     for(int j=0;j<finalans[i].size();j++){
    //         cout<<finalans[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    for(auto it:finalans){
        for(auto it1:it){
            cout<<it1<<" ";
        }
        cout<<endl;
    }

   return 0;
}