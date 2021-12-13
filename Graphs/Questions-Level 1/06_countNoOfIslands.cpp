#include<bits/stdc++.h>
using namespace std;

//This code is right however because it is a 2d array it is causing problem in parameter passing in funtion

//Given 2D array where 0's represent land and 1's represent water. Assume every cell 
//is linked to N,E,W,S cell, you are required to find and count the number of islands
void findNoIslands(vector<vector<int>> adjList, int i, int j, vector<vector<int>> vis){
    //if it is out of the matrix it is water return
    if(i<0 || j<0 || i>=adjList.size() || j>=adjList[0].size() || adjList[i][j]==1 ){
        return;
    }
    vis[i][j]=1;
    findNoIslands(adjList,i,j+1,vis); //right
    findNoIslands(adjList,i,j-1,vis);//left
    findNoIslands(adjList,i-1,j,vis); //top
    findNoIslands(adjList,i+1,j,vis); //down
}

int main(){
    int u,v;
    cin>>u>>v;
    vector<vector<int>> adjList;
    vector<vector<int>> visited;

    for(int i=0;i<u;i++){
        for(int j=0;j<v;j++){
            int temp;
            cin>>temp;
            adjList[i][j]=temp;
            visited[i][j]=0;
        }
    }

    //   for(int i=0;i<u;i++){
    //     for(int j=0;j<v;j++){
            
    //         cout<<adjList[i][j];
            
    //     }
    // }


    int count=0;
    for(int i=0;i<u;i++){
        for(int j=0;j<v;j++){
            if(adjList[i][j]==0 && visited[i][j]==0){ // it is land and unvisited
                findNoIslands(adjList,i,j,visited);
                count++;
            } 
        }
    }
    cout<<count<<endl; //no of times findNoIslands was called i.e. no of disconnected components


    


    

   return 0;
}