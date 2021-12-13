//Given a graph representing people and their connectivity
// Also given a src person who got infected anf time t
// Find how many people will get infected in time t, if the infection spreads to neighbors of infected person in 1 unit of time
//We used bfs here because infection spreaded through side adjacent edges
//Self made

#include<bits/stdc++.h>
using namespace std;

void spreadInfectionBFS(int node,vector<int> adjList[],vector<int> & vis,int count,int & ans){
   queue<pair<int,int>> q;
   q.push(make_pair(node,1));
   vis[node]=1;

   while(!q.empty()){
      int elem=q.front().first;
      int time=q.front().second;
      if(time<=count){
         ans++;
      }
      q.pop();
      for(auto it:adjList[elem]){
        if(!vis[it]){
           vis[it]=1;
           q.push(make_pair(it,time+1));
        }
      }
   }

}

int main(){
   int v,e;
    cin>>v>>e;
    vector<int> adjList[v];
    for(int i=0;i<e;i++){
        int src,dest;
        cin>>src>>dest;
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }

    int src,timeforChecking;
    cin>>src>>timeforChecking;
   vector<int> vis(v,0);
   int ans=0;
    spreadInfectionBFS(src,adjList,vis,timeforChecking,ans);
    cout<<ans<<endl;

   return 0;
}