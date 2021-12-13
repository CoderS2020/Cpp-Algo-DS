/*
Given 2 strings find length of longest common substring

t[m+1][n+1];
int LCSubstring(string x,string y,int m,int n){
    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==0 || j==0) t[i][j]=0;
        }
    }

    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(x[i-1]==y[j-1]) t[i][j]=1+t[i-1][j-1];
            else{
                t[i][j]=t[i-1][j-1]; //since continuity is broken so uptill t[i][j] subproblem ans would be equal to prev
            }
        }
    }
    
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            ans=max(ans,t[i][j]);
        }
    }
}

*/

/*
//https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1#
class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        int t[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0) t[i][j]=0;
            }
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(S1[i-1]==S2[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }
                else{
                    t[i][j]=0;
                }
            }
        }
        int ans=0;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                ans=max(ans,t[i][j]);
            }
        }
        return ans;
        
        
    }
};

*/

/*
Print the longest Common subsequence
Travel reverse in t array from the last element to first element.
If the elements are equal then we go to diagonal top left (i--, j--)
If the elements are not equal then we go to max of top and left (i-- or j--)

At the end reverse the string and return
t[m+1][n+1];
LCS(x,y,m,n); //call the string and fill t array

int i=m,j=n;
string anss="";
while(i>0 && j>0){ //i==0 or j==0 is already initialized to 0
    if(x[i-1]==y[j-1]){
        ans.push_back(a[i-1]);  
        i--,j--;
    } 
    else{ //elements are not equal
        if(t[i-1][j]>t[i][j-1]){ //top is greater than left
            i--;
        }
        else{ //left is greater than top
            j--;
        }
    }
}


*/