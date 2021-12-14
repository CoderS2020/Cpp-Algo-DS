/*
Given a string , a partitioning of the string is a palindrome partitioning if every substring of the partition
is a palindrome. 
//Recursive

int solve(string s, int i,int j){
    if(i>=j) return 0;

    if(isPalindrome(s,i,j)==true) return 0;

    int mini=INT_MAX;

    for(int k=i;k<j;k++){
        int temp=1+solve(s,i,k)+ solve(s,k+1,j);

        if(temp<mini){
            mini=temp;
        }
    }


    return mini;
};

bool isPalindrome(string s,int i,int j){
    if(i==j) return true;
    if(i>j) return true; //empty string
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++,j--;
    }
    return true;
}


//Memoized- Bottom up
int static t[i+1][j+1];
memset(t,-1,sizeof(t));

int solve(string s,int i,int j){
    if(i>=j) return 0;

    if(isPalindrome(s,i,j)==true) return 0;

    if(t[i][j]!=-1) return t[i][j];
    int mini=INT_MAX;
    for(int k=i;k<j;k++){
        
        int left,right;
        if(t[i][k]!=-1) left=t[i][k];
        else left=solve(s,i,k);

        if(t[k+1][j]!=-1) right=t[k+1][j];
        else right=solve(s,k+1,j);

        temp=1+left+right;        
        mini=min(temp,mini);
    }

    return t[i][j]=mini;
}

//Optimized Memoized
*/

int dp[501][501];
class Solution{
public:

bool isPal(string s,int i,int j)
{
   while(i<=j)
   {
       if(s[i]!=s[j])
       {
           return 0;
       }
       i++;j--;
   }
   return 1;
}
int util(string s,int i,int j)
{
   if(i>=j)return 0;

   if(dp[i][j]!=-1)return dp[i][j];

   if(isPal(s,i,j))return dp[i][j]=0;

   int temp,mn=INT_MAX;
   for(int k=i;k<=j-1;k++)
   {
       int l,r;
       if(dp[i][k]==-1){
           l=util(s,i,k);
       }
       else{
           l=dp[i][k];
        }
       if(dp[k+1][j]==-1){
           r=util(s,k+1,j);
       }
       else{
           r=dp[k+1][j];
        }
       temp=l+r+1;
       mn=min(mn,temp);
   }
   
   dp[i][j]=mn;
   return dp[i][j];
}
   int palindromicPartition(string s)
   {
       int n=s.size();
       memset(dp,-1,sizeof(dp));
       return util(s,0,n-1);
   }
};
