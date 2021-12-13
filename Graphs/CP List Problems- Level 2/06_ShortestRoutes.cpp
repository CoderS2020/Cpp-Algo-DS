// https://cses.fi/problemset/task/1671
#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int main(){
      ll n,m;
      cin>>n>>m;
      vector<pair<ll,ll>> adjList[n+1];
      while(m--){
         ll a,b;
         ll wt;
         cin>>a>>b>>wt;
         adjList[a].push_back({b,wt});
      }

      priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> > pq;
      vector<ll> distTo(n+1,LONG_LONG_MAX);

      distTo[1]=0;
      pq.push({0,1});

      while(!pq.empty()){
         ll dist=pq.top().first;
         ll elem=pq.top().second;
         pq.pop();
         if(distTo[elem] < dist) continue;
         
         for(auto it=adjList[elem].begin();it!=adjList[elem].end();it++){
            ll next=it->first;
            ll nextDist=it->second;
            if(distTo[next]<=distTo[elem]+nextDist) continue;
            else{
               distTo[next]=distTo[elem]+nextDist;
               pq.push({distTo[next],next});;
            }
         }

      }

      for(ll it=1;it<=n;it++){
         cout<<distTo[it]<<" ";
      }



   return 0;
}