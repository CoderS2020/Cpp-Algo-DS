/*
A thief wants to rob a store. He is carrying a bag of capacity W. The store has ‘n’ items of infinite supply. Its weight is given by the ‘wt’ array and its value by the ‘val’ array. He can either include an item in its knapsack or exclude it but can’t partially have it as a fraction. We need to find the maximum value of items that the thief can steal. He can take a single item any number of times he wants and put it in his knapsack.
*/

#include<bits/stdc++.h>
using namespace std;
//Memoized
/*
Time Complexity: O(N*W)

Reason: There are N*W states therefore at max ‘N*W’ new problems will be solved.

Space Complexity: O(N*W) + O(N)

Reason: We are using a recursion stack space(O(N)) and a 2D array ( O(N*W)).
*/
int knapsackUtil(vector<int>& wt, vector<int>& val, int ind, int W, vector<vector
<int>>& dp){

    if(ind == 0){
        return ((int)(W/wt[0])) * val[0];
    }
    
    if(dp[ind][W]!=-1)
        return dp[ind][W];
        
    int notTaken = 0 + knapsackUtil(wt,val,ind-1,W,dp);
    
    int taken = INT_MIN;
    if(wt[ind] <= W)
        taken = val[ind] + knapsackUtil(wt,val,ind,W-wt[ind],dp);
        
    return dp[ind][W] = max(notTaken,taken);
}


int unboundedKnapsack(int n, int W, vector<int>& val,vector<int>& wt) {
    
    vector<vector<int>> dp(n,vector<int>(W+1,-1));
    return knapsackUtil(wt, val, n-1, W, dp);
}

//Tabulation
/*
Time Complexity: O(N*W)

Reason: There are two nested loops

Space Complexity: O(N*W)

Reason: We are using an external array of size ‘N*W’. Stack Space is eliminated.
*/

int unboundedKnapsack(int n, int W, vector<int>& val,vector<int>& wt) {
    
    vector<vector<int>> dp(n,vector<int>(W+1,0));
    
    //Base Condition
    
    for(int i=wt[0]; i<=W; i++){
        dp[0][i] = ((int) i/wt[0]) * val[0];
    }
    
    for(int ind =1; ind<n; ind++){
        for(int cap=0; cap<=W; cap++){
            
            int notTaken = 0 + dp[ind-1][cap];
            
            int taken = INT_MIN;
            if(wt[ind] <= cap)
                taken = val[ind] + dp[ind][cap - wt[ind]];
                
            dp[ind][cap] = max(notTaken, taken);
        }
    }
    
    return dp[n-1][W];
}


//Space Optimized Tabulation
/*
Time Complexity: O(N*W)

Reason: There are two nested loops.

Space Complexity: O(W)

Reason: We are using an external array of size ‘W+1’ to store only one row.
*/

int unboundedKnapsack(int n, int W, vector<int>& val,vector<int>& wt) {
    
    vector<int> cur(W+1,0);
    
    //Base Condition
    
    for(int i=wt[0]; i<=W; i++){
        cur[i] = ((int)i/wt[0]) * val[0];
    }
    
    for(int ind =1; ind<n; ind++){
        for(int cap=0; cap<=W; cap++){
            
            int notTaken = cur[cap];
            
            int taken = INT_MIN;
            if(wt[ind] <= cap)
                taken = val[ind] + cur[cap - wt[ind]];
                
            cur[cap] = max(notTaken, taken);
        }
    }
    
    return cur[W];

}