/*
Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).
*/
#include<bits/stdc++.h>
using namespace std;

//Recursive Approach-Memoized
/*
      wt[last element]<=Weight          or             wt[last element]> Weight
            |                                                   |
    ----------------------                              dont include it                     
    |                    |
include last      dont include last

*/

int knapsack(int wt[], int val[],int W,int n){
    if(n==0 || W==0) return 0;

    if(wt[n-1]<=W){
        return max(val[n-1]+knapsack(wt,val,W-wt[n-1],n-1), knapsack(wt,val,W,n-1)); //either include last or dont include it
    }
    else if(wt[n-1]>W){
        return knapsack(wt,val,W,n-1);
    }
};

//Memoization
/*
int t[n+1][w+1]; //make matrix with elements that change here (n and W - look at recursive functions)
memset(t,-1,sizeof(t)); //mark entire matrix with -1

int knapsack(int wt[], int val[],int W,int n){
    if(n==0 || W==0) return 0;

    if(t[n][W]!=-1) return t[n][W];

    if(wt[n-1]<=W){
        return t[n][W]=max(val[n-1]+knapsack(wt,val,W-wt[n-1],n-1), knapsack(wt,val,W,n-1)); //either include last or dont include it
    }
    else if(wt[n-1]>W){
        return t[n][W]=knapsack(wt,val,W,n-1);
    }
};*/

//TopDown Approach
//Sometimes we get stack overflow while using recursive approach becuase so many functions are called, so this approach comes in handy

/*
int t[n+1][W+1];
for(int i=0;i<n+1;i++){
    for(int j=0;j<W+1;j++){
        //When i is in consideration think of corresponding value in j and vice-versa
        if(i==0 || j==0) t[i][j]=0; //Base condition to initialization
    }
}

int knapsack(int wt[], int val[],int W,int n){
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<W+1;j++){
            if(wt[i-1]<=j){ //replace n with i and W with j
                t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]], t[i-1][j]); 
            }
            else if(wt[i-1]>j){
                t[i][j]=t[i-1][j];
            }
        }
    }

  return t[n][W];
};


*/


int main(){


   return 0;
}