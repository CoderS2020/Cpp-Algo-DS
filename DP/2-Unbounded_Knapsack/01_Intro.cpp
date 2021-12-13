/*

Unbounded Knapsack: 
Any element can have 2 options to take it or to not take it.
If we choose to take it we can take it more than 1 no of times.
If we choose not to take it we dont take it any time.

a) Rod cutting
b) Coin Change I
c) Coin Change II
d) Maximum Ribbon Cutting
*/

/*
int t[n+1][W+1];
for(int i=0;i<n+1;i++){
    for(int j=0;j<W+1;j++){
        if(i==0 || j==0) t[i][j]=0; //Base condition to initialization
    }
}

int unBoundedknapsack(int wt[], int val[],int W,int n){
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<W+1;j++){
            if(wt[i-1]<=j){ //replace n with i and W with j
                t[i][j]=max(val[i-1]+t[i][j-wt[i-1]], t[i-1][j]);  //instead of t[i-1] we have t[i] because we want to reinclude it
            }
            else if(wt[i-1]>j){
                t[i][j]=t[i-1][j];
            }
        }
    }

  return t[n][W];
};
*/