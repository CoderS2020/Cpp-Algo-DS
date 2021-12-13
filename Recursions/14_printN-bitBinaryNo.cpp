//print N-bit binary numbers having  1's greater than or equal to 0's for any prefix
#include<bits/stdc++.h>
using namespace std;

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	void solve(int n,int one,int zero,string output,vector<string> &v){
        if(n==0){
            v.push_back(output);
            return;
        }
        
        string output2=output;
        output2.push_back('1');
        solve(n-1,one+1,zero,output2,v);
    
        if(one>zero){ //check
            string output1=output;
            output1.push_back('0');
            solve(n-1,one,zero+1,output1,v);        
        }
        
        
        return;

    }


    vector<string> NBitBinary(int n){
        vector<string> v;
        string output="";
        int one=0;
        int zero=0;
        solve(n,one,zero,output,v);
        return v;
    }
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}  // } Driver Code Ends