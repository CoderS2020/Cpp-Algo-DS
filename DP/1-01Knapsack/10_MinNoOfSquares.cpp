/*
Min no of squares
eg. 26=4^2+3^2+1^2 or 26=5^2+1^2 so min is 2
*/
#include<bits/stdc++.h>
using namespace std;
int dp[10000];
int minSquare(int n){
    if(n==1 || n==2 || n==3 || n==0)return n; //4is min whose sqr root is 2 , before 4 all will be expressed in terms of 1^2 eg 3^2=1^2+1^2+1^2(3 min no of squares hence for 3-> ans is 3)
    if(dp[n]!=-1)return dp[n];
    int ans=INT_MAX;
    for(int i=1;i*i<=n;i++){
        ans=min(ans,1+minSquare(n-i*i));
    }

    return dp[n]=ans;

}

int main(){
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;

    cout<<minSquare(n);

   return 0;
}