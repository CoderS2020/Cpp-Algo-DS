
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void solve(vector<int> &v,int k,int index,int &ans){
        if(v.size()==1){
            ans=v[0];
            return;
        }
        index=(index+k)%v.size();
        v.erase(v.begin()+index);       
        solve(v,k,index,ans);
    }
    
    int josephus(int n, int k)
    {
       //Your code here
       vector<int> v;
        for(int i=1;i<=n;i++){
            v.push_back(i);
        }
        int ans=-1;
        solve(v,k-1,0,ans);
        return ans;
       
    }
};



int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;//taking input n and k
		
		//calling josephus() function
		Solution ob;
		cout<<ob.josephus(n,k)<<endl;
	}
	return 0;
}