/*
If the last char of strings match then perform lcs on remaining parts of respective strings.
If the last char do not match then we have two options 
1.remaining part of first string and complete second string
2.remaining part of second string and complete first string

n,m are sizes of string x,y
int LCS(string x, string y,int n,int m){
    if(n==0 || m==0) return 0;

    if(x[n-1]==m[m-1]) return 1+ LCS(x,y,n-1,m-1);
    else{
        min(lCS(x,y,n-1,m), LCS(x,y,n,m-1));
    }
}

//DP: memoization
n,m are changing so they will be included in dp table
int t[n+1][m+1];

Initialize the table with -1 throughout
for(int i=0;i<n+1;i++){
    for(int j=0;j<m+1;j++){
        t[i][j]=-1;
    }
}

or memset(t,-1,sizeof(t));
int LCS(string x, string y,int n,int m){
    if(n==0 || m==0) return 0;
    if(t[n][m]!=-1) return t[n][m]; // if it is already visited(calculated) then return its's value

    if(x[n-1]==m[m-1]) return t[n][m]=1+ LCS(x,y,n-1,m-1);
    else{
        return t[n][m]=min(lCS(x,y,n-1,m), LCS(x,y,n,m-1));
    }
}

//DP: Top Down Approach
t[n+1][m+1];

Initialization (base condition in recursive function is considered)
int LCS(string x,string y, int m,int n){

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 || j==0) t[i][j]=0;
        }
    }

    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(x[i-1]==y[i-1]) t[i][j]=1+t[i-1][j-1];
            else{
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    return t[n][m];
}



*/