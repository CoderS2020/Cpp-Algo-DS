/*


Find the count of numbers between L and R which have a sum of digits=X.

1<=L<=R<=10^18
1<=X<=180
*/

#include<bits/stdc++.h>
using namespace std;

int dp[100][101][2];
int solve(string & num,int n,int x,bool tightCondition){
    if(x<0)return 0;
    if(n==1){
        if(x>=0 && x<9){
            return 1;
        }
        return 0;
    }

    if(dp[n][x][tightCondition]!=-1)return dp[n][x][tightCondition];

    int ub=tightCondition?num[(num.length()-n)]-'0':9;
    int answer=0;
    for(int dig=0;dig<=ub;dig++){
        answer+=solve(num,n-1,x-dig,tightCondition & (dig==ub));
    }

    return dp[n][x][tightCondition]=answer;
}

int main(){
    string L="",R="11235";
    memset(dp,-1,sizeof(dp));
    cout<<solve(R,R.length(),5,1);
    return 0;
}