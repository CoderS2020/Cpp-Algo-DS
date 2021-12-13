#include<bits/stdc++.h>
using namespace std;

// 1. Adjacency Matrix -> adj[u][v]=1 and adj[v][u]=1: Used only if value of 'n' is small.
//Space Complexity: n*n

//2. Adjacency List: At every index we store a vector containing all its adjacent elements
//Space Complexity: n+2m (n indexes and every edge is stored twice)


//1. Adjacency Matrix
/*int main(){
    //n-> no of vertices and m->no of edges
    int n,m;
    cin>>n>>m;

    //declare the adjacent matrix
    int adj[n+1][n+1];

    //take edges as input
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;

    }


   return 0;
}*/


//2. Adjacency List
int main(){
    int n,m;
    cin>>n>>m;

    vector<int> adj[n+1]; // IF it is weighted then vector<pair<int,int>> adj[n+1] and also take w along with u,v
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);

    }
    return 0;
}