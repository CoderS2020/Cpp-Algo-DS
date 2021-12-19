//https://atcoder.jp/contests/dp/tasks/dp_b
#include<bits/stdc++.h>
using namespace std;

int n,k;
int height[100005];
int dp[100005];
int solve(int ind,int k){

    //base condition
    if(ind==n-1)return 0;
    if(ind>=n)return INT_MAX;

    if(dp[ind]!=-1)return dp[ind];
    int ans=INT_MAX;
    for(int i=1;i<=k;i++){ //start from 1, from 0 gives errors
        if(ind+i>=n)break;
        ans=min(ans,abs(height[ind]-height[ind+i])+solve(ind+i,k));
    }

    return dp[ind]=ans;
}

int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>height[i];
    memset(dp,-1,sizeof(dp));
    cout<<solve(0,k);

   return 0;
}