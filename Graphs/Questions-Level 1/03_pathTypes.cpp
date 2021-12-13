#include<bits/stdc++.h>
using namespace std;

//Find smallest path(smallest weight), largest path, ceil (just bigger than 40), floor( just smaller than 40)

int weightSoFar=0,smallestWeight=INT_MAX,largestWeight=INT_MIN,ceilpathWeight=INT_MAX,floorpathWeight=INT_MIN; //just for simplicity these have been defined globally, otherwise the no of parameters in the function will be too many,but in actual programming do that instead of this
string spath,lpath,cpath,fpath;
int criteria=12; //in program take this as input and pass it as parameter in funtion

//For finding kth largest/smallest element -> for such type of questions use priority_queue because it sorts them in ascending/descending order already so you dont have to sort it separately.
priority_queue<pair<int,string>> pq;
int k=3;

void multisolver(int src, int dest,vector<int> &vis,vector<pair<int,int>> adjList[], string psf, int wsf){
    if(src==dest){
        // cout<<psf<<" "<<wsf<<"\n";
        if(wsf<smallestWeight){ //smaller
            smallestWeight=wsf;
            spath=psf;
        }
        if(wsf>largestWeight){ //larger
            largestWeight=wsf;
            lpath=psf;
        }
        //ceil: for eg. ceil(42) will be the smallest in nos greater than 42
        //floor: for eg.floor(42) will be the largest in nos smaller than 42
        if(wsf>criteria && wsf<ceilpathWeight ){
            ceilpathWeight=wsf;
            cpath=psf;
        }
        if(wsf<criteria && wsf>floorpathWeight){
            floorpathWeight=wsf;
            fpath=psf;
        }

        if(pq.size()<k){
            pq.push(make_pair(wsf,psf));
        }
        else{
            if(wsf>pq.top().first){
                pq.pop();
                pq.push(make_pair(wsf,psf));
            }
        }

        return;
    }
    vis[src]=1;
    for(auto it:adjList[src]){
        if(!vis[it.first]){
            multisolver(it.first,dest,vis,adjList,psf+to_string(it.first),wsf+it.second);
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

    int src,dest;
    cin>>src>>dest;
    vector<int> vis(v,0);
    string pathsofar=to_string(src);
    multisolver(src,dest,vis,adjList,pathsofar,weightSoFar);

    cout<<spath<<'@'<<smallestWeight<<endl;
    cout<<lpath<<'@'<<largestWeight<<endl;
    cout<<cpath<<'@'<<ceilpathWeight<<endl;
    cout<<fpath<<'@'<<floorpathWeight<<endl;


    return 0;
}