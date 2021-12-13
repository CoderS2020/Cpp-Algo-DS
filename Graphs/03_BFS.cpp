//Breadth First Search (Adjacent element first)
//Time complexity: O(n+e) and space complexity: O(n+e)+(n)+O(n)
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> bfsOfGraph(int v,vector<int> adj[]){
        vector<int> bfs;
        vector<int> vis(v+1,0); //visited array of size v+1 and initialize it to 0 and it is 1 based indexing so v+1
        for(int i=1;i<=v;i++){
            if(vis[i]==0){ //To check if it is unvisited

                //bfs
                queue<int> q; //Declare a queue 
                q.push(i); //Push the element in the queue and mark it as visited
                vis[i]=1; 

                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    bfs.push_back(node);

                    for(auto it:adj[node]){
                        if(!vis[it]){
                            q.push(it);
                            vis[it]=1;
                        }
                    }
                }


            }
        }
        return bfs;
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int v,e;
        cin>>v>>e;

        vector<int> adjList[v+1];
        for(int i=0;i<e;i++){
            int first,second;
            cin>>first>>second;
            adjList[first].push_back(second);
            adjList[second].push_back(first);
        }

        Solution obj;
        vector<int> bfsAnswer =obj.bfsOfGraph(v,adjList);

        for(auto it=bfsAnswer.begin();it!=bfsAnswer.end();it++){
            cout<<*it<<" ";
        }


    }

    return 0;
}

