//https://atcoder.jp/contests/dp/tasks/dp_e
// https://www.youtube.com/watch?v=o8N6vwEHo7M&list=PL-ZG-Gxv4hG59EGDdxeOsSf6NbVcsrd2t
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long 


ll n,w, wt[109], val[109];
ll dp[109][100009];

ll solve(int r, int idx) {
    if(idx == n)
        return r == 0 ? 0 : INT_MAX;

    if(dp[idx][r] != -1)
    	return dp[idx][r];

    ll ans = solve(r, idx + 1);
    if(val[idx] <= r)
    	ans = min(ans, wt[idx] + solve(r - val[idx], idx + 1));
     
    return dp[idx][r] = ans;
}

int s(int v_max) {

	for(int i = v_max; i >= 0; i--) {
		if(solve(i, 0) <= w)
			return i;
	}
	return 0;
}
 
int main() {
 
        cin>>n>>w;
        memset(dp, -1, sizeof(dp));

        int v_max = 0;

        for(int i = 0; i < n; i++) {
            cin>>wt[i]>>val[i];
            v_max += val[i];
        }

        cout<<s(v_max)<<endl;

}
