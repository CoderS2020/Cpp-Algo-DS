#include<bits/stdc++.h>
using namespace std;

//method 1
//path array consists our answer
// void printPathdfs(int src,int dest,vector<int> & vis,vector<pair<int,int>> adjList[],vector<int> &path,int path_index){
//     vis[src]=1;
//     path[path_index]=src;
//     path_index++;

//     if(src==dest){
//         for(int i=0;i<path_index;i++){
//             cout<<path[i]<<" ";
//         }
//     }
//     else{
//         for(auto it:adjList[src]){
//             if(!vis[it.first]){
//                 printPathdfs(it.first,dest,vis,adjList,path,path_index);
//             }
//         }
//     }

//     path_index--;
//     vis[src]=0;
// }

//method 2
void printAllPaths(int src, int dest,vector<int> &vis,vector<pair<int,int>> adjList[], string psf){
    if(src==dest){
        cout<<psf<<"\n";
        return;
    }
    vis[src]=true;
    for(auto it: adjList[src]){
        if(!vis[it.first]){
            printAllPaths(it.first,dest,vis,adjList,psf+ to_string(it.first));
        }
    }
    vis[src]=false;
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
    vector<int> path(v,0);
    int path_index=0;

    // printPathdfs(src,dest,vis,adjList,path,path_index);
    string pathsofar=to_string(src);
    printAllPaths(src,dest,vis,adjList,pathsofar);
    return 0;
}