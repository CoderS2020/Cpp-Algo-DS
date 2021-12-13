//Given no of friends having an id 0to n-1; you are given a no k representing no of clubs
//In next k lines two nos are given separated by space, nos are ids of students belonging to same club
//You have to find in how many ways can we select a pair of students such that both students are from different clubs
#include<bits/stdc++.h>
using namespace std;

void noOfStudentsDFS(int node,vector<int> adjList[],vector<int> &vis,vector<vector<int>> &finalAns,int count){
    vis[node]=1;
    finalAns[count].push_back(node);
    for(auto it:adjList[node]){
        if(!vis[it]){
            noOfStudentsDFS(it,adjList,vis,finalAns,count);
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
        
    }
    vector<int> vis(v,0);
    int count=0;
    vector<vector<int>> finalAns(v+1);
   
    for(int i=0;i<v;i++){
        if(!vis[i]){
            noOfStudentsDFS(i,adjList,vis,finalAns,count);
            count++;
        }
    }

    //Method 1
    // vector<int> ansNumber;
    // for(auto it:finalAns){
    //     ansNumber.push_back(it.size());
        
    // }
    // int answer=0;
    // for(int i=0;i<ansNumber.size();i++){
    //     for(int j=i+1;j<ansNumber.size();j++){
    //         answer+=ansNumber[i]*ansNumber[j];
    //     }
    // }
    // cout<<answer<<endl;

    //Method 2
    int answer=0;
    for(int i=0;i<finalAns.size();i++){
        for(int j=i+1;j<finalAns.size();j++){
            answer+=finalAns[i].size()*finalAns[j].size();
        }
    }
    cout<<answer<<endl;


   return 0;
}
