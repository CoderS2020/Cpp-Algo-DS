#include<bits/stdc++.h>
using namespace std;

class Solution{

    bool checkDFS(int node,int parent,vector<int> &vis,vector<int> adjList[]){
        vis[node]=1;

        for(auto it:adjList[node]){
            if(!vis[it]){
                vis[it]=1;
                if(checkDFS(it,node,vis,adjList))return true;
            }
            else if(parent!=it){
                return true;
            }
        }
        return false;
    }

    public:
        bool checkCycleDFS(vector<int> adjList[],int v){
            vector<int> vis(v+1,0);

            for(int i=1;i<=v;i++){
                if(!vis[i]){
                    if(checkDFS(i,-1,vis,adjList)) return true;
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
        int n,m;
        cin>>n>>m;

        adjList[n].push_back(m);
        adjList[m].push_back(n);
    }

    Solution obj;
    if(obj.checkCycleDFS(adjList,v)){
        cout<<"Cycle exists\n";
    }
    else{
        cout<<"Cycle does not exist\n";
    }


   return 0;
}