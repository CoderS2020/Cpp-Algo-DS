/*
Memoization
int knapsackUtil(vector<int>& wt, vector<int>& val, int ind, int W, vector<vector<int>>& dp){

    if(ind == 0){
        if(wt[0] <=W) return val[0];
        else return 0;
    }
    
    if(dp[ind][W]!=-1)
        return dp[ind][W];
        
    int notTaken = 0 + knapsackUtil(wt,val,ind-1,W,dp);
    
    int taken = INT_MIN;
    if(wt[ind] <= W)
        taken = val[ind] + knapsackUtil(wt,val,ind-1,W-wt[ind],dp);
        
    return dp[ind][W] = max(notTaken,taken);
}


int knapsack(vector<int>& wt, vector<int>& val, int n, int W){
    
    vector<vector<int>> dp(n,vector<int>(W+1,-1));
    return knapsackUtil(wt, val, n-1, W, dp);
}
Time Complexity: O(N*W)

Reason: There are N*W states therefore at max ‘N*W’ new problems will be solved.

Space Complexity: O(N*W) + O(N)

Reason: We are using a recursion stack space(O(N)) and a 2D array ( O(N*W)).
*/

/*
Tabulation
int knapsack(vector<int>& wt, vector<int>& val, int n, int W){
    
    vector<vector<int>> dp(n,vector<int>(W+1,0));
    
    //Base Condition
    
    for(int i=wt[0]; i<=W; i++){
        dp[0][i] = val[0];
    }
    
    for(int ind =1; ind<n; ind++){
        for(int cap=0; cap<=W; cap++){
            
            int notTaken = 0 + dp[ind-1][cap];
            
            int taken = INT_MIN;
            if(wt[ind] <= cap)
                taken = val[ind] + dp[ind-1][cap - wt[ind]];
                
            dp[ind][cap] = max(notTaken, taken);
        }
    }
    
    return dp[n-1][W];
}
Time Complexity: O(N*W)

Reason: There are two nested loops

Space Complexity: O(N*W)

Reason: We are using an external array of size ‘N*W’. Stack Space is eliminated.
*/


/*
Space Optimized
int knapsack(vector<int>& wt, vector<int>& val, int n, int W){
    
    vector<int> prev(W+1,0);
    
    //Base Condition
    
    for(int i=wt[0]; i<=W; i++){
        prev[i] = val[0];
    }
    
    for(int ind =1; ind<n; ind++){
        for(int cap=W; cap>=0; cap--){
            
            int notTaken = 0 + prev[cap];
            
            int taken = INT_MIN;
            if(wt[ind] <= cap)
                taken = val[ind] + prev[cap - wt[ind]];
                
            prev[cap] = max(notTaken, taken);
        }
    }
    
    return prev[W];
}

Time Complexity: O(N*W)

Reason: There are two nested loops.

Space Complexity: O(W)

Reason: We are using an external array of size ‘W+1’ to store only one row.
*/