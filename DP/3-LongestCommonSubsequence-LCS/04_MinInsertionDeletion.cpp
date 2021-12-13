/*
Given two strings a,b. Convert a to b, you can either insert or delete any character in string a.
Find minimum no of insertions/deletions to convert a to b

Find LCS(a,b),then delete the extra characters from b (comparing with LCS),then insert the characters present in A
Thus,1) find LCA(a,b) [common elements]
2) Find deleteOperations=b-LCA(a,b) [extra char to be deleted from b]
3) Find insertOperations=a-LCA(a,b) [extra char present in a but not in b, to be added to b]

Thus ans=deleteOperations+insertOperations


*/

/*
class Solution{
		

	public:
	int LCS(string a,string b){
	    int n=a.size(),m=b.size();
	    int t[n+1][m+1];
	    //Initialization
	    for(int i=0;i<=n;i++){
	        for(int j=0;j<=m;j++){
	            if(i==0 || j==0)t[i][j]=0;
	        }
	    }
	    
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=m;j++){
	            if(a[i-1]==b[j-1]){
	                t[i][j]=1+t[i-1][j-1];
	            }
	            else{
	                t[i][j]=max(t[i-1][j],t[i][j-1]);
	            }
	        }
	    }
	    
	    return t[n][m];
	}
	int minOperations(string str1, string str2) 
	{ 
	    
	    int lcs=LCS(str1,str2);
	    int deletion=str2.size()-lcs;
	    int insertion=str1.size()-lcs;
	    return insertion+deletion;
	    
	    
	} 
};

*/

