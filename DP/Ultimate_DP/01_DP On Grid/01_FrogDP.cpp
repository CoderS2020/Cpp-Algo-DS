// https://atcoder.jp/contests/dp/tasks/dp_a
#include<bits/stdc++.h>
using namespace std;

//Top-Down /Memoization
int f(int ind,vector<int> & heights,vector<int>& dp){
    if(ind==0)return 0;
    if(dp[ind]!=-1)return dp[ind];
    int left=f(ind-1,heights,dp)+abs(heights[i-1]-heights[i]);
    int rights=INT_MAX;
    if(ind>1){
        right=f(ind-2,heights,dp)+abs(heights[i-2-heights[ind]]);
    }

    return min(left,right);
};

int frogJump(int n,vector<int> & heights){
    vector<int> dp(n+1,-1);
    return f(n-1,heights,dp);
}

//Bottomup/ Tabulation
int frogJump(int n,vector<int> & heights){
    vector<int>dp(0);
    dp[0]=0; //base condition initialised
    for(int i=1;i<n;i++){
        //Conditions same as that of memoization
        int firstOption=dp[ind-1]+abs(heights[i]-heights[i-1]);
        int secondOption=INT_MAX;
        if(i>1){
            secondOption=dp[ind-2]+abs(heights[i]-heights[i-2]);
        }
        dp[i]=min(firstOption,secondOption);
    }

    return dp[n-1];
}

//Reducing space in tabulation method
int frogJump(int n,vector<int> & heights){
    int prev=0,prev2=0;
    for(int i=1;i<n;i++){
        //Conditions same as that of memoization
        int firstOption=prev+abs(heights[i]-heights[i-1]);
        int secondOption=INT_MAX;
        if(i>1){
            secondOption=prev2+abs(heights[i]-heights[i-2]);
        }
        int curr=min(firstOption,secondOption);
        prev2=prev;
        prev=curr;
    }

    return prev;//for i==n (ie. end of for loop)ans will be stored in prev
}