/*
Given a rod and an array of prizes from (1 to n) n is size of array. You have to break it into pieces such that
total prize is maximized
//https://practice.geeksforgeeks.org/problems/rod-cutting0840/1#

Here only 1 array of prizes is given , you have to find second array of lengths from 1 to n

int t[n+1][L+1];
for(int i=0;i<n+1;i++){
    for(int j=0;j<L+1;j++){
        if(i==0 || j==0) t[i][j]=0; //Base condition to initialization
    }
}

int unBoundedknapsack(int length[], int prize[],int L,int n){
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<L+1;j++){
            if(length[i-1]<=j){ //replace n with i and L with j
                t[i][j]=max(prize[i-1]+t[i][j-length[i-1]], t[i-1][j]);  //instead of t[i-1] we have t[i] because we want to reinclude it
            }
            else if(length[i-1]>j){
                t[i][j]=t[i-1][j];
            }
        }
    }

  return t[n][L];
};
*/
/*
class Solution{
  public:
    int cutRod(int prize[], int n) {
        //code here
        int length[n];
        for(int i=0;i<n;i++)length[i]=i+1;
        int t[n+1][n+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0 || j==0) t[i][j]=0; 
            }
        }
        
         for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                if(length[i-1]<=j){
                    t[i][j]=max(prize[i-1]+t[i][j-length[i-1]], t[i-1][j]); 
                }
                else if(length[i-1]>j){
                    t[i][j]=t[i-1][j];
                }
            }
        }
    
      return t[n][n];
        
    }
};
*/