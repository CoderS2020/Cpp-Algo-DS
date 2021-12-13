#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	vector<pair<int,int> > adj[n]; 

	int a,b,wt;
	for(int i = 0; i<m ; i++){
		cin >> a >> b >> wt;
		adj[a].push_back(make_pair(b,wt));
		adj[b].push_back(make_pair(a,wt));
	}	

   vector<int> key(n,INT_MAX);
   vector<int> parent(n,-1);
   vector<bool> mstSet(n,false);

   key[0]=0;
   priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>> > pq;
   pq.push(make_pair(0,0));//(key[index],index)

   while(!pq.empty()){
        int node=pq.top().second;
        pq.pop();
        mstSet[node]=true;

        for(auto it:adj[node]){
            int v=it.first;
            int weight=it.second;
            if(mstSet[v]==false && key[v]>weight){
                key[v]=weight;
                parent[v]=node;
                pq.push(make_pair(key[v],v));
            }
        }
   }

   for(int i=1;i<n;i++){
       cout<<parent[i]<<" -> "<<i<<endl;
   }

    

   return 0;
}