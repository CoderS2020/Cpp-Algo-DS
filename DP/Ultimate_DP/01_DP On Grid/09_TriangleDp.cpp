//https://leetcode.com/problems/triangle

#include<bits/stdc++.h>
using namespace std;
//Memoization
class Solution {
public:
    int f(int i,int j,vector<vector<int>>& triangle,int n,vector<vector<int>>& dp){
        if(i==n-1)return triangle[n-1][j];
        if(dp[i][j]!=-1)return dp[i][j];
        
        int d=triangle[i][j]+f(i+1,j,triangle,n,dp);
        int diag=triangle[i][j]+f(i+1,j+1,triangle,n,dp);
        
        
        return dp[i][j]=min(d,diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(0,0,triangle,n,dp);
    }
};

//Tabulation
class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[n-1][i]=triangle[n-1][i];
        }
        
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down=triangle[i][j]+dp[i+1][j];
                int diag=triangle[i][j]+dp[i+1][j+1];
                dp[i][j]=min(down,diag);
            }
        }
        return dp[0][0];        
    }
};

//Space Optimized Tabulation
class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        
        vector<int> next(n,0);
        for(int i=0;i<n;i++){
            next[i]=triangle[n-1][i];
        }
        
        for(int i=n-2;i>=0;i--){
            vector<int> curr(n,0);
            for(int j=i;j>=0;j--){
                int down=triangle[i][j]+next[j];
                int diag=triangle[i][j]+next[j+1];
                curr[j]=min(down,diag);
            }
            next=curr;
        }
        return next[0];
        
  }
};
