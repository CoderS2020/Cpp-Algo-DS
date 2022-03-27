#include<bits/stdc++.h>
using namespace std;

/*
Given n*m matrix filled with integer numbers, find the max sum that can be obtained from a path starting 
from any cell in the first row to any cell in the last row. From a cell in a row, you can move to another 
cell directly below that row or diagonally below left or right(down, down left , down right)
*/

//Memoization
/*
int f(int i,int j,vector<vector<int>> &matrix,vector<vector<int>> &dp){
    if(i<0 || j>=matrix[0].size() )return -1e8;
    if(i==0)return matrix[0][j];

    if(dp[i][j]!=-1)return dp[i][j];

    int up=matrix[i][j]+f(i-1,j,m,matrix,dp);
    int upleft=matrix[i][j]+f(i-1,j-1,matrix,dp);
    int upright=matrix[i][j]+f(i-1,j+1,matrix,dp);

    return dp[i][j]= max(up,max(upleft,upright));
}

int getMaxPathSum(vector<vector<int>> & matrix){
    int n=matrix.size();
    int m=matrix[0].size();
    vector<vector<int>> dp(n,vector<int>(m,-1));

    int maxi=-1e8;
    for(int j=0;j<m;j++){
        maxi=max(maxi,f(n-1,j,matrix,dp));
    }
    return maxi;
}*/

//Tabulation
int getMaxPathSum(vector<vector<int>> & matrix){
    int n=matrix.size();
    int m=matrix[0].size();
    vector<vector<int>> dp(n,vector<int>(m,-1));


    for(int j=0;j<m;j++){
        dp[0][j]=matrix[0][j];
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            int up=matrix[i][j]+dp[i-1][j];
            int upleft=matrix[i][j],upright=matrix[i][j];
            if(j-1>=0)upleft+=dp[i-1][j-1];
            else upleft+=-1e8;
            if(j+1<m)upright+=dp[i-1][j+1];
            else upright+=-1e8;
            dp[i][j]=max(up,max(upleft,upright));
        }
    }
    int maxi=INT_MIN;
    for(int j=0;j<m;j++){
        maxi=max(maxi,dp[n-1][j]);
    }

    return maxi;

}

//Space Optimized
int getMaxPathSum(vector<vector<int>> & matrix){
    int n=matrix.size();
    int m=matrix[0].size();
    vector<int> prev(m,0),cur(m,0);


    for(int j=0;j<m;j++){
        prev[j]=matrix[0][j];
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            int up=matrix[i][j]+prev[j];
            int upleft=matrix[i][j],upright=matrix[i][j];
            if(j-1>=0)upleft+=prev[j-1];
            else upleft+=-1e8;
            if(j+1<m)upright+=prev[j+1];
            else upright+=-1e8;
            cur[j]=max(up,max(upleft,upright));
        }
        prev=cur;
    }
    int maxi=INT_MIN;
    for(int j=0;j<m;j++){
        maxi=max(maxi,prev[j]);
    }

    return maxi;

}