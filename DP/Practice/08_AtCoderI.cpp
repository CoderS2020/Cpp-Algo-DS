//https://atcoder.jp/contests/dp/tasks/dp_i


#include<bits/stdc++.h>
using namespace std;
double dp[3000][3000];


double coins(vector<double> &arr,int i,int x){
	if(x==0) return 1;
	if(i==0) return 0;
	// bcoz of double we can't use ==
	if(dp[i][x]>-0.9) return dp[i][x];
	return dp[i][x] = arr[i]*coins(arr,i-1,x-1) + (1-arr[i])*coins(arr,i-1,x);
}

int main(){
	int n;
	cin>>n;
	vector<double> arr(n+1);
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=n;i++)
		cin>>arr[i];

	cout<<fixed<<setprecision(10)<<coins(arr,n,(n+1)/2);

	return 0;
}