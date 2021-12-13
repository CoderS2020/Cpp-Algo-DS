#include<bits/stdc++.h>
using namespace std;

//If in one go all are visited then it is a connected graph else not

void checkConnecteddfs(int node,vector<pair<int,int>> adjList[], vector<int> & vis){
    vis[node]=1;
    for(auto it: adjList[node]){
        if(!vis[it.first]){
            checkConnecteddfs(it.first,adjList,vis);
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
    checkConnecteddfs(0,adjList,vis);
    
    for(int i=0;i<v;i++){
        if(!vis[i]){
            cout<<"Disconnected graph"<<endl;
            break;
        }

        if(i==v-1){ // for the last i if it is still not disconnected then it has to be connected
            cout<<"Connected Graph"<<endl;
        }
    }

   return 0;
}