/*
//Something wrong ->accepted in gfg but not in leetcode
Given 2 strings , find shortest string such that it has both the strings as subsequences.

We get the length of shortest common supersequence by writing the common letters once and rest as they are.
Find Longest Common Subsequence and the rest letters are written as it is.

m,n are lengths of the two strings
length of shortest common supersequence= m + n - LCS(string1,string2)

-->Printing shortest common supersequence

Unlike printing LCS where we include only the common characters, here in SCS we write the common characters
only once and others as they are

t[m+1][n+1];
SCS(x,y,m,n); //call the string and fill t array

int i=m,j=n;
string ans="";
while(i>0 && j>0){
    if(x[i-1]==y[j-1]){
        ans.push_back(x[i-1]);  
        i--,j--;
    } 
    else{ //elements are not equal
        if(t[i-1][j]>t[i][j-1]){ //top is greater than left
            ans.push_back(y[j-1]);
            i--;
        }
        else{ //left is greater than top
            ans.push_back(x[i-1]);
            j--
        }
    }
}

//For printing LCS it doesnt matter if the loop ends at (0,0)
But for printing LCS it does matter bcz SCS of 'abc' and '' is 'abc'.

while(i>0){
    ans.push_back(x[i-1]);i--;
}
while(j>0){
    ans.push_back(y[i-1]);j--;
}
return ans;

*/

/*
// https://practice.geeksforgeeks.org/problems/shortest-common-supersequence0322/1#
 class Solution
{
    public:
    
     void lcs(string s1, string s2,vector<vector<int>> &t)
    {
        int n=s1.size(),m=s2.size();
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0) t[i][j]=0;
            }
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }
                else{
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        
    }
    
    int shortestCommonSupersequence(string x, string y, int n, int m)
    {
        //code here
         vector<vector<int>> t;
         for(int i=0;i<=n;i++){
             vector<int> n1(m+1);
             t.push_back(n1);
         }
         lcs(x,y,t);
         
        int i=n,j=m;
        string ans="";
        while(i>0 && j>0){
            if(x[i-1]==y[j-1]){
                ans.push_back(x[i-1]);  
                i--,j--;
            } 
            else{ 
                if(t[i-1][j]>t[i][j-1]){ 
                    ans.push_back(x[i-1]);
                    i--;
                }
                else{ 
                    ans.push_back(y[j-1]);
                    j--;
                }
            }
        }
        
        while(i>0){
            ans.push_back(x[i-1]);i--;
        }
        while(j>0){
            ans.push_back(y[j-1]);j--;
        }
        return ans.size();

    }
};
 
 
*/