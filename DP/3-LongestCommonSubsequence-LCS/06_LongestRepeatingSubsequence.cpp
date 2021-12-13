/*
Given a string , find the subsequence that is repeating in the string.

Find LCS(s,s) just take care of i==j

//LCS
t[n+1][m+1];

Initialization (base condition in recursive function is considered)
x=y;
class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    int n=str.size();
		    int t[n+1][n+1];
		     for(int i=0;i<=n;i++){
                for(int j=0;j<=n;j++){
                    if(i==0 || j==0) t[i][j]=0;
                }
            }
        
            for(int i=1;i<n+1;i++){
                for(int j=1;j<n+1;j++){
                    if(str[i-1]==str[j-1] && i!=j){ 
                        t[i][j]=1+t[i-1][j-1];
                    } 
                    else{
                        t[i][j]=max(t[i-1][j],t[i][j-1]);
                    }
                }
            }
            return t[n][n];
		}

};


*/