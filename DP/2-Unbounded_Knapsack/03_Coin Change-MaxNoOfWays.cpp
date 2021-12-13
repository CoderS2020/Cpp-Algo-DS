/*
Given an array of coins and sum(any random no not necessarily sum of elements).
Count no of ways to choose coins such that their sum equals to sum
array: [1,2,3]
sum=5

There can be 5 ways to choose elements from array such that their sum equals to sum(5).
Multiple occurences are allowed

Initialization: 
int t[n+1][sum+1];
for(int i=0;i<n+1;i++){
    for(int j=0;j<sum+1;j++){
        if(i==0) t[i][j]=0;
        if(j==0) t[i][j]=1;//take nothing ie 1 way 
    }
}

int unBoundedknapsack(int coin[], int sum,int n){
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(coin[i-1]<=j){
                t[i][j]=t[i][j-coin[i-1]] + t[i-1][j]; 
            }
            else if(coin[i-1]>j){
                t[i][j]=t[i-1][j];
            }
        }
    }

  return t[n][sum];
};

*/