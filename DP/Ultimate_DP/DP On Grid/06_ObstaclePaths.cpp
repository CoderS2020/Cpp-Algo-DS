#include<bits/stdc++.h>
using namespace std;

//Given N*M maze you have to go from top left to bottom right
//The maze has some obstacle represented by -1 and others by 0
//Allowed moves are either right or down.

// Top Down memoization
/*
int f(int i,int j,vector<vector<int>>& dp,vector<vector<int>> mat){
    if(i>=0 and j>=0 and mat[i][j]!==-1)return 0;
    if(i==0 and j==0)return 1;
    if(i<0 or j<0 )return 0;

    if(dp[i][j]!=-1)return dp[i][j];
    int up=f(i-1,j,dp,mat);
    int left=f(i,j-1,dp,mat);
    return dp[i][j]=up+left;
}

int uniquePaths(int m,int n,vector<vector<int>> mat){
    vector<vector<int>> dp(m,vector<int>(n,-1));
    return f(m-1,n-1,dp,mat);
}*/

//Bottom Up-Tabulation
/*
int uniquePaths(int m,int n){
    int dp[m][n];
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==-1)dp[i][j]=0;
            else if(i==0 and j==0)dp[i][j]=1;
            else{
                int up=0,left=0;
                if(i>0)up=dp[i-1][j];
                if(j>0)left=dp[i][j-1];
                dp[i][j]=up+left;
            }
        }
    }
    return dp[m-1][n-1];
}
*/

//Space Optimization
/*
int uniquePaths(int m,int n){
    vector<int> prev(n,0);
    for(int i=0;i<m;i++){
        vector<int> curr(n,0);
        for(int j=0;j<n;j++){
            if(mat[i][j]!=-1)curr[j]=0;
            if(i==0 and j==0)curr[j]=1;
            else{
                int up=0,left=0;
                if(i>0)up=prev[j];
                if(j>0)left=curr[j-1];
                curr[j]=up+left;
            }
        }
        prev=curr;
    }
    return prev[n-1];
}
*/