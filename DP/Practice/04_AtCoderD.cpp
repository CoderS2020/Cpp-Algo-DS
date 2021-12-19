//https://atcoder.jp/contests/dp/tasks/dp_d


#include <bits/stdc++.h> 
using namespace std; 
#define ll long long

ll N,W,w[109],v[109];
ll dp[109][100009];

ll solve(int id,int wt){
    if(id==N)return 0;

    if(dp[id][wt]!=-1)return dp[id][wt];

    ll ans=solve(id+1,wt);

    if(w[id]+wt<=W)
        ans=max(ans,solve(id+1,wt+w[id])+v[id]);

    return dp[id][wt]=ans;
}


int main(){
    
    cin>>N>>W;
    for(int i=0;i<N;i++){
        cin>>w[i]>>v[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<solve(0,0);
}