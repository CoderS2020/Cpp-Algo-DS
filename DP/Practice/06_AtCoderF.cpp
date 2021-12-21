//https://atcoder.jp/contests/dp/tasks/dp_f

#include<bits/stdc++.h>
using namespace std;

int main(){
    string a,b;
    cin>>a>>b;
    int n = a.length();
    int m = b.length();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if (i==0 or j ==0){
                    dp[i][j] = 0;
                }
                else if (a[i-1] == b[j-1]){
                    dp[i][j] = 1+ dp[i-1][j-1]; 
                }
                else{
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }

    }

    string res = "";
    int i = n,j=m;
    while (i>0 and j>0){
        if (a[i-1] == b[j-1]){
            res.push_back(a[i-1]);
            i--;
            j--;
        }
        else if (dp[i-1][j] > dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    reverse(res.begin(),res.end());
    cout<<res<<endl;


   return 0;
}