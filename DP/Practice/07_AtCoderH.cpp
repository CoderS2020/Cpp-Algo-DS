//https://atcoder.jp/contests/dp/tasks/dp_h

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll n,h,w;
vector<vector<char>> v;
vector<vector<int>> dp;
ll mod=1e9+7;

bool check(ll r, ll c){
    if(r>=h || c>=w || v[r][c]=='#') return 0;
    else return 1;
}

int ways(ll i,ll j){
    if(i==h-1 && j==w-1) return 1;
    if(!check(i,j)) return 0;

    if(dp[i][j]!=-1) return dp[i][j];
    ll ans=0;
    // cout<<i<<" "<<j<<endl;
    ans=(ways(i+1,j)+ways(i,j+1))%mod;

    return dp[i][j]=ans;
}

int main() {
   
    cin>>h>>w;
    v.resize(h,vector<char>(w,0));
    dp.resize(h,vector<int>(w,-1));
    
    for(ll i=0;i<h;i++){
        for(ll j=0;j<w;j++){
            char temp;
            cin>>temp;
            v[i][j]=temp;
        }
    }
    cout<<ways(0,0)<<endl;
 
}