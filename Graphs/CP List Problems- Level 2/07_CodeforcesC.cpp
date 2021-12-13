// https://codeforces.com/problemset/problem/20/C
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
         adjList[b].push_back({a,wt});
    }

    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> > pq;
    vector<ll> distTo(n+1,LONG_LONG_MAX);

    distTo[1]=0;
    pq.push({0,1});

    vector<int> parent(n+1,-1);

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
                parent[next]=elem;
               pq.push({distTo[next],next});;
            }
         }

      }

    if(distTo[n]==LLONG_MAX){
        cout<<"-1\n";
        return 0;
    }

    vector<int> ans;
    int final=n;
    while(final!=1){
        ans.push_back(final);
        final=parent[final];
    }
    ans.push_back(1);

    reverse(ans.begin(),ans.end());

    for(auto it:ans){
        cout<<it<<" ";
    }
    
    
   return 0;
}