//cses: counting rooms
#include<bits/stdc++.h>
using namespace std;

void bfs(int i,int j,vector<vector<char>> &arr,int n,int m){
   queue<pair<int,int>> q;
   q.push({i,j});
   
   while(!q.empty()){
        int i1=q.front().first;
        int j1=q.front().second;
        
               
        q.pop();

        if(i1+1<n){
            if(arr[i1+1][j1]=='.'){
                q.push({i1+1,j1});
                arr[i1+1][j1]='#';
            }
        }
        if(i1-1>=0){
            if(arr[i1-1][j1]=='.' ){
                q.push({i1-1,j1});
                arr[i1-1][j1]='#';
            }
        }
        if(j1+1<m){
            if(arr[i1][j1+1]=='.' ){
                q.push({i1,j1+1});
                arr[i1][j1+1]='#';
            }
        }
        if(j1-1>=0){
            if(arr[i1][j1-1]=='.'){
                q.push({i1,j1-1});
                arr[i1][j1-1]='#';
            }
        }
   }
    
    

};

int main(){


    int n,m;
    cin>>n>>m;
    vector<vector<char>> arr;
    char ch;
    for(int i=0;i<n;i++){
        vector<char> temp;
        for(int j=0;j<m;j++){
            cin>>ch;
            temp.push_back(ch);
        
        }
        arr.push_back(temp);
        temp.clear();

    }
    long long int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]=='.'){
                bfs(i,j,arr,n,m);
                count++;
            }
        }
    }

    cout<<count<<"\n";

   return 0;
}