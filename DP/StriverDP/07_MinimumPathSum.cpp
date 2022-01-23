#include<bits/stdc++.h>
using namespace std;

//Given N*M grid. Each point in the grid has some cost associated with it,
//Find path from top left to bottom right that minimizes the sum of the cost to travel among all possible costs.
//Memoization-Top Down Approach
/*
int f(int i,int j,vector<vector<int>> & grid,vector<vector<int>> & dp){
    if(i==0 and j==0)return grid[0][0];
    if(i<0 or j<0)return INT_MAX;

    if(dp[i][j]!=-1)return dp[i][j];
    int up=grid[i][j]+f(i-1,j,grid,dp);
    int left=grid[i][j]+f(i,j-1,grid,dp);

    return dp[i][j]=min(left,up);
}

int minSumPath(vector<vector<int>> & grid){
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> dp(m,vector<int>(m,-1));
    return f(n-1,m-1,grid,dp);
}
*/

//Bottom Up/Tabulation
/*int minSumPath(vector<vector<int>> & grid){
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> dp(m,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 and j==0)dp[i][j]=grid[i][j];
            else{
                int up=grid[i][j];
                if(i>0)up+=dp[i-1][j];
                else up+=1e9;

                int left=grid[i][j];
                if(j>0)left+=grid[i][j-1];
                else left+=1e9;

                dp[i][j]=min(left,up);
            }
        }
    }
    return dp[n-1][m-1];
}*/

//Space Optimized
/*
int minSumPath(vector<vector<int>> & grid){
    int n=grid.size();
    int m=grid[0].size();
    vector<int> prev(m,0);

    for(int i=0;i<n;i++){
        vector<int> cur(m,0);
        for(int j=0;j<m;j++){
            if(i==0 and j==0)cur[j]=grid[i][j];
            else{
                int up=grid[i][j];
                if(i>0)up+=prev[j];
                else up+=1e9;

                int left=grid[i][j];
                if(j>0)left+=cur[j-1];
                else left+=1e9;

                cur[j]=min(left,up);
            }
        }
        prev=cur;
    }
    return prev[n-1][m-1];
}*/