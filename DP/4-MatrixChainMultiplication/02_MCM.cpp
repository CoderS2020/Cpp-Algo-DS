/*
//https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/
Given a sequence of matrices, find the most efficient way to multiply these matrices together. 
The problem is not actually to perform the multiplication but merely to decide in which order
to perform the multiplications.

solve(arr,1,n-1);

//Recursive
int solve(int arr[],int i,int j){
    if(i>=j) return 0;
    int min=MAX_ANS;
    for(int k=i;k<j;k++){
        int tempAns=solve(arr,i,k)+ solve(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
        if(tempAns<min) min=tempAns;
    }
    return min;
}

//Memoized
int t[i+1][j+1];
memset(t,-1,sizeof(t));
int solve(int arr[],int i,int j){
    if(i>=j) return 0;
    if(t[i][j]!=-1) return t[i][j];

    int min=MAX_ANS;
    for(int k=i;k<j;k++){
        int tempAns=solve(arr,i,k)+ solve(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
        if(tempAns<min) min=tempAns;
    }
    return t[i][j]=min;
}

int dp[101][101];
class Solution{
public:
    int solve(int arr[],int i,int j)
    {
        if(i>=j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int mini=INT_MAX;
        
        for(int k=i;k<j;k++)
        {
            int temp=solve(arr,i,k)+solve(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
            mini=min(mini,temp);
        }
        return dp[i][j]=mini;
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        memset(dp,-1,sizeof(dp));
        return solve(arr,1,N-1);
    }
};

*/