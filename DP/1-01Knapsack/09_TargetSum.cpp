/*
Given an array, assign +/- to elements of array such that the sum of all elements of array equals to given number

The elements with -sign will result in subtraction and those with + sign will result in addition
Thus s1-s2=no
Exactly similar to prev problem.


*/

class Solution {
  public:
    int findTargetSumWays(vector<int>&nums ,int target) {

        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)sum+=nums[i];
        if(target+sum<0 or (target+sum)%2!=0)return 0;
        sum=(sum+target)/2;
        int t[n+1][sum+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(i==0) t[i][j]=0;
                if(j==0) t[i][j]=1;
            }
        }
        
        
            
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(nums[i-1]<=j){
                    t[i][j]= t[i-1][j-nums[i-1]] + t[i-1][j];
                }
                else{
                    t[i][j]=t[i-1][j];
                }
            }
        }

      return t[n][sum];

    }
};




*/

/*
Leetcode 494
class Solution {
public:
        int countSubsets(vector<int>& nums, int n, int M)
    {
        int t[n + 1][M + 1];
        
       for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= M; j++)
            {
                if(i == 0)
                    t[i][j] = 0;
                if(j == 0)
                    t[i][j] = 1;
            }
        }
        
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j <= M; j++)
            {
                if(nums[i - 1] <= j)
                 t[i][j] = t[i - 1][j - nums[i - 1]] + t[i - 1][j];
                else
                  t[i][j] = t[i - 1][j];
            }
        }
        
        return t[n][M];  
    }
    
    int findTargetSumWays(vector<int>& nums, int target)
     {
         target = abs(target); //dont miss the constraints
         int n = nums.size();
         int sum = 0;
         for(int i = 0; i < n; i++)
             sum += nums[i];
         
        int M = (sum + target)/2;
        if(sum < target || (sum + target) % 2 != 0)
            return 0;
         return countSubsets(nums, n, M);
     }
};