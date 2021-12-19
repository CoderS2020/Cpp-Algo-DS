// https://atcoder.jp/contests/dp/tasks/dp_c
#include<bits/stdc++.h>
using namespace std;

int n,k;
int happiness[100005][4];
int dp[100005][4];
int solve(int day,int prevChoice){

    //base condition
    if(day==n) return 0;

    //since both day and prevChoice changes and have unique values for their combination ,hence dp will have both of them
    if(dp[day][prevChoice]!=-1 && prevChoice!=-1)return dp[day][prevChoice]; //if prevChoice==-1 then dp[day][prevChoice] will give dummy ans

    int ans=0;
    for(int i=0;i<3;i++){
        if(prevChoice!=i){
            ans=max(ans,happiness[day][i]+solve(day+1,i));
        }
    }

    return dp[day][prevChoice]=ans;
    
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>happiness[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));
    cout<<solve(0,-1);

   return 0;
}