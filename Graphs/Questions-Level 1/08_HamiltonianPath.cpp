#include<bits/stdc++.h>
using namespace std;

// Given a graph and a source, print Hamiltonian path and represent path with . and cycle with *
//Hamiltonian Path: A path starting from source and visiting all the vertices without visiting it more than once
//Hamiltonian Cycle: When a Hamiltonian Path's first and last vertex have an edge 

//Something is wrong , but intuition is correct
void hamiltonian(vector<pair<int,int>>ajdList[],int src,map<int,int> &visited,string psf,int originalSource){
    if(visited.size()==ajdList->size()-1){
        cout<<psf<<" ";
        bool closingEdgeFound=false;
        for(auto it:ajdList[src]){
            if(it.first==src){
                closingEdgeFound=true;
            }
        }

        if(closingEdgeFound){
            cout<<"*"<<endl;
        }
        else{
            cout<<"."<<endl;
        }
        return;
    }
    
    
    visited[src]=1;
    for(auto it:ajdList[src]){
        if(visited.find(it.first)==visited.end()){
            hamiltonian(ajdList,it.first,visited,psf+to_string(it.first),originalSource);
        }
    }
    visited.erase(src);
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

    int src;
    cin>>src;
    map<int,int> visited;
    hamiltonian(adjList,src,visited,to_string(src),src);

   return 0;
}