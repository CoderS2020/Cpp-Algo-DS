//Given 2d matrix, 1 represents land, 0 represents water.
//Find the nearest '1' from every '0' i.e. find nearest land from every water
//From these distances, find the max
//Manhattan distance: |y2-y1|+|x2-x1|

//Important Concept
//1. You can travel all the elements of matrix and then once you encounter
// any 0 then run bfs function untill the nearest 1 is acheived , however time complexity will be compromised.

//2. Do reverse, run bfs from 1 and once you encounter 0 mark it as 1,
// Make use of 2 while loops and queue to store positions of 1's

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj;
    int val;
    queue<pair<int,int>> q;

    for(int i=0;i<n;i++){
        vector<int> temp;
        for(int j=0;j<m;j++){
            cin>>val;
            temp.push_back(val);
            if(val==1){
                q.push(make_pair(i,j));
            }
        }
        adj.push_back(temp);
        temp.clear();
    }

    if(q.size()==0 || q.size()==n*m){
        cout<<"-1"<<endl;
        return 0;
    }
    int level=-1; //it runs for extra one more time and then it realizes that the condition is false so in order to avoid ourselves from decreasing 1 after the loop is over , it is better to initialize it with -1 instead of 0
    while(!q.empty()){
        level++;
        int size=q.size();
        while(size--){
            int i1=q.front().first;
            int j1=q.front().second;
            q.pop();
            if(i1-1>=0){
                if(adj[i1-1][j1]==0){
                    adj[i1-1][j1]=1;
                    q.push(make_pair(i1-1,j1));
                }
            }
            if(i1+1<n){
                if(adj[i1+1][j1]==0){
                    adj[i1+1][j1]=1;
                    q.push(make_pair(i1+1,j1));
                }
            }
            if(j1-1>=0){
                if(adj[i1][j1-1]==0){
                    adj[i1][j1-1]=1;
                    q.push(make_pair(i1,j1-1));
                }
            }
            if(j1+1<n){
                if(adj[i1][j1+1]==0){
                    adj[i1][j1+1]=1;
                    q.push(make_pair(i1,j1+1));
                }
            }
        }
    }
    cout<<level<<endl;




   return 0;
}