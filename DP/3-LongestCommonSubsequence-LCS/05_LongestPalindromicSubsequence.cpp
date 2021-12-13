/*
Given a string find the longest palindromic subsequence.

a=given string
b= reverse of a
Find LCS(a,b)

*/
/*
// https://leetcode.com/problems/longest-palindromic-subsequence/
class Solution {
public:
    int LCS(string X,string Y){
	int n=X.size(), m=Y.size();
	int t[n+1][m+1];
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++){
			if(i==0||j==0)
				t[i][j]=0;
		}
		
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(X[i-1]==Y[j-1])
				t[i][j]= 1+t[i-1][j-1];
			else
				t[i][j]= max(t[i-1][j],t[i][j-1]);
		}
		
	return t[n][m];
}
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(s.begin(),s.end());
        return LCS(t,s);
    }
};
*/

/*
Minimum no of deletion in a string to make it a palindrome
Length of palindromic string = 1/no of deletion

Find longest palindromic subsequence, which will eventually ensure least no of deletion
thus, no of deletion = length(string) - length(longest palindromic subsequence)
*/


/*
Minimum no of insertion in a string to make it a palindrome
Length of palindromic string = 1/no of insertion

Find longest palindromic subsequence, which will eventually ensure least no of insertion
thus, no of insertion = length(string) - length(longest palindromic subsequence)
*/