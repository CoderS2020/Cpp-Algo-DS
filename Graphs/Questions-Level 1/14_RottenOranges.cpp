//0:Empty Cell , 1: Fresh Orange, 3: Rotten Oranges
//It takes 1 hr for a rotten orange to rot fresh oranges adjacent to it
//Print total time required to rot all the oranges, if it is not possible to rot all oranges then print -1
//BFS

//Very Important: Many questions revolve around this
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj;
    int val=0;
    int fresh=0; //fresh stores the no of fresh oranges(1-->fresh orange)
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        vector<int> temp;
        for(int j=0;j<m;j++){
            cin>>val;
            temp.push_back(val);
            if(val==2){
                q.push(make_pair(i,j));
            }
            if(val==1) fresh++;
        }
        adj.push_back(temp);
    }
    int timer=-1; //at the end when it runs for exta one more time , timer gets one extra , so to take care of that do just -1

    if(fresh==0){ //if there are no fresh oranges already then no need to code further
        cout<<"0"<<endl;
        return 0;
    }

    while(!q.empty()){
        timer++; 
        int qsize=q.size();
        
        while(qsize--){
            int i1=q.front().first;
            int j1=q.front().second;
            q.pop();
            if(i1-1>=0){ //top
                if(adj[i1-1][j1]==1){
                    adj[i1-1][j1]=2;
                    q.push(make_pair(i1-1,j1));
                    fresh--;
                }                
            }
            if(j1-1>=0){ //left
                if(adj[i1][j1-1]==1){
                    adj[i1][j1-1]=2;
                    q.push(make_pair(i1,j1-1));
                    fresh--;
                }
            }
            if(i1+1<adj.size()){ //bottom
                if(adj[i1+1][j1]==1){
                    adj[i1+1][j1]=2;
                    q.push(make_pair(i1+1,j1));
                    fresh--;
                }
            }
            if(j1+1<adj[0].size()){ //right
                if(adj[i1][j1+1]==1){
                    adj[i1][j1+1]=2;
                    q.push(make_pair(i1,j1+1));
                    fresh--;
                }
            }
        }
    
       
    }

   
   if(fresh==0){
       cout<<timer<<endl;
   }
   else{
       cout<<-1<<endl;
   }

   return 0;
}