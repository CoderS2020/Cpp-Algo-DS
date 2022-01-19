/*
Mr. X is a professional robber planning to rob houses along a street. Each house has a certain amount of money hidden. All houses along this street are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.
You are given an array/list of non-negative integers 'ARR' representing the amount of money of each house. Your task is to return the maximum amount of money Mr. X can rob tonight without alerting the police.s

Variation of non adjacent sum except here first and last are adjacent to each other
*/
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

long long int houseRobber(vector<int>& valueInHouse){
    vector<int> temp1,temp2;
    int n=valueInHouse.size();
    if(n==1)return valueInHouse[0];
    for(int i=0;i<n;i++){
        if(i!=0)temp1.push_back(valueInHouse[i]);
        if(i!=n-1)temp2.push_back(valueInHouse[i]);
    }

    return max(maxNonAdjacentSum(temp1),maxNonAdjacentSum(temp2));
}