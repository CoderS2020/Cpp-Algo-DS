//Given array, return max sum of subsequence with constraints that no two elements are adjacent in given arrays
#include<bits/stdc++.h>
using namespace std;

int f(int ind,vector<int> nums,vector<int> & dp){
    if(ind==0)return nums[ind];
    if(ind<0)return 0;

    if(dp[ind]!=-1)return dp[ind];

    int pick=nums[ind]+f(ind-2,nums,dp);

    int notpick=0+f(ind-1,nums,dp);

    return dp[ind]=max(pick,notpick);
}

int maxNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    vector<int> dp(n+1,-1);
    return f(n-1,nums,dp);
}

//Tabulation/BottomUp

int maxNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    int dp[n+1];
    dp[0]=a[0];
    int neg=0;
    for(int i=1;i<n;i++){
        pick=a[ind];
        if(i>1)pick+=dp[i-2];
        notpick=0+dp[i-1];
        dp[i]=max(pick,notpick);
    }
}

//Tabulation Space Complexity optimization

int maxNonAdjacentSum(vector<int> &nums){
        int prev=nums[0];
        int prev2=0;
        int neg=0;
        for(int i=1;i<n;i++){
            int pick=nums[i];
            if(i>1)pick+=prev2;
            int notpick=0+prev;
            int curr=max(pick,notpick);
            prev2=prev;
            prev=curr;
        }
        return prev;
}
