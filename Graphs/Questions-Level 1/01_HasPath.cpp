#include<bits/stdc++.h>
using namespace std;

//You are given a graph , src vertex and destination vertex, 
//find if a path exists between src and destination

//Method 1
bool dfs(int node,int dest,vector<int> & vis,vector<pair<int,int>> adjList[]){
    vis[node]=1;
    if(vis[dest]){
        return true;
    }
    for(auto it:adjList[node]){
        int nextNode=it.first;
        int nextWeight=it.second;
        if(!vis[nextNode]){
            dfs(nextNode,dest,vis,adjList);
        }
    }
    if(node=vis.size()-1 && vis[dest]==0){ //if it is last element and still the vis[dest]=0, it means path does not exist
        return false;
    }
    return true; //this function uses recursion so for other recursion calls we return true
    
}
//Method 2
bool hasPath1(int src,int dest,vector<int> & vis,vector<pair<int,int>> adjList[]){
    if(src==dest){
        return true;
    }

    vis[src]=true;
    for(auto it:adjList[src]){
        if(!vis[it.first]){
            bool isAdjElemVis=hasPath1(it.first,dest,vis,adjList);
            if(isAdjElemVis){
                return true;
            }
        }
    }
    return false;

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

    int src,dest;
    cin>>src>>dest;
    vector<int> vis(v,0);

    // cout<<dfs(src,dest,vis,adjList);
    cout<<hasPath1(src,dest,vis,adjList);


   return 0;
}