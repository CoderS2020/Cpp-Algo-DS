//Given 2d matrix: there are 2 islands , we may change 0's to 1's so as to 
//connect to islands together to form 1 island. Return the smallest number
//of 0's that must be flipped
//Logic is correct, something wrong with code
//Logic Steps: 11. Find the first island through dfs, update visited elements to true and push indexes to queue
//2. Once we get the first island in queue and vis, now do a bfs on entire matrix and if it is 0 then update to 1
//if it is 1 then check if it is a part of visited island (vis vector) or not,
// if it is not a part , this means we have come to the second island (i.e. the two islands have been connected)

#include<bits/stdc++.h>
using namespace std;

void dfs(int i,int j,vector<vector<int>> adj,vector<vector<bool>> &vis,queue<pair<int,int>> &q){
    vis[i][j]=true;
    q.push(make_pair(i,j));

    if(i+1<adj.size()){
        if(adj[i+1][j]==1)
            dfs(i+1,j,adj,vis,q);
    }
    if(i-1>=0){
        if(adj[i-1][j]==1)
            dfs(i-1,j,adj,vis,q);
    }
    if(j+1<adj[0].size()){
        if(adj[i][j+1]==1)
            dfs(i,j+1,adj,vis,q);
    }
    if(j-1>=0 ){
        if(adj[i][j-1]==1)
            dfs(i,j-1,adj,vis,q);
    }

}

int main(){

    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj;
    vector<vector<bool>> vis;
    int temp=0;
    for(int i=0;i<n;i++){
        vector<int> tempVec;
        vector<bool> tempVis;
        for(int j=0;j<m;j++){
            cin>>temp;
            tempVec.push_back(temp);
            tempVis.push_back(false);
            
        }
        adj.push_back(tempVec);
        vis.push_back(tempVis);
        tempVec.clear();
        tempVis.clear();
    }
    queue<pair<int,int>> q;
    
    //we want dfs to be run only once because we want only one island
    bool onlyonce=false; 
    for(int i=0;i<n && !onlyonce;i++){
        for(int j=0;j<m && !onlyonce;j++){
            if(adj[i][j]==1){
                dfs(i,j,adj,vis,q);
                onlyonce=true;
            }
        }
    }

    int level=0;
    while(!q.empty()){
        int size=q.size();
        while(size--){
            int i1=q.front().first;
            int j1=q.front().second;
            q.pop();

            if(i1+1<adj.size()){
                if(adj[i1+1][j1]==0){
                    q.push(make_pair(i1+1,j1));
                    adj[i1+1][j1]=1;
                }
                else if(vis[i1+1][j1]==0){ //if adj[i1+1][j1]]==0 && vis[i1+1][j1]==1
                    cout<<level<<endl;
                    return 0;
                }

            }
            if(i1-1>=0 ){
                if(adj[i1-1][j1]==0){
                    q.push(make_pair(i1-1,j1));
                    adj[i1-1][j1]=1;
                }
                else if(vis[i1-1][j1]==0){ 
                    cout<<level<<endl;
                    return 0;
                }
            }
            if(j1+1<adj[0].size() ){
                if(adj[i1][j1+1]==0){
                    q.push(make_pair(i1,j1+1));
                    adj[i1][j1+1]=1;
                }
                else if(vis[i1][j1+1]==0){ 
                    cout<<level<<endl;
                    return 0;
                }
            }
            if(j1-1>=0 ){
                if(adj[i1][j1-1]==0){
                    q.push(make_pair(i1,j1-1));
                    adj[i1][j1-1]=1;
                }
                else if(vis[i1][j1-1]==0){ 
                    cout<<level<<endl;
                    return 0;
                }
            }

        }
        level++;
    }



   return 0;
}