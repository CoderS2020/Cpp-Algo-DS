//https://atcoder.jp/contests/dp/tasks/dp_a

#include<bits/stdc++.h>
using namespace std;

//Since ind is changing so dp table will be wrt ind- Bcz of memoization TC becomes O(n)
int dp[100005];
int height[100005];
int n=0;
int func(int ind){
    //base condition
    if(ind==n-1) return 0;
    if(ind>=n)return INT_MAX;
    
    if(dp[ind]!=-1)return dp[ind];

    int left=INT_MAX,right=INT_MAX;
    if(ind+1<n){
        left=abs(height[ind]-height[ind+1])+func(ind+1);
    }

    if(ind+2<n){
        right=abs(height[ind]-height[ind+2])+func(ind+2);
    }
    
    return dp[ind]=min(left,right);

}

int main(){

    
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>height[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<func(0);

   return 0;
}