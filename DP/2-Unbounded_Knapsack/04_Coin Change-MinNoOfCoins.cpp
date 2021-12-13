/*
Typical Problem:
Given an array of coins and sum(given), there might be many ways of choosing coins such that their sum equals 
sum(given).From all these ways , you have to tell minimum no of coins required to get the given sum

t[n+1][sum+1];

In the first row of t , every element will be INT_MAX-1 (infinity).
for eg. t[0][2] -> we want sum as 2 and elements are 0 , so we will require infinte coins (mathematically 2/0)

Also for 2nd row ie. when i=1 (we can include only first element of array), we might get a condition 
wherein it is not possible to get answer. For eg. t[1][3] -> we want sum to be 3 and only first element
of array is allowed and if that element of array is 2 . So since it is 2 , it can never give an anwer
However for t[1][2] , since element is 2 and the sum required is 2, we will get the answer.
Hence what we do is if for i=1 no of coins are acheivable we write the answer or else initialise it to INT_MAX-1

for(int i=0;i<n+1;i++){
    for(int j=0;j<sum+1;j++){
        if(j==0) t[i][j]=0;
        if(i==0) t[i][j]=INT_MAX-1;
    }
    if(i==1){
        for(int j=1;j<sum+1;j++){
            if(j%arr[0]==0){
                t[i][j]=j/arr[0];
            }
            else t[i][j]=INT_MAX-1;
        }
    }
}

int unBoundedknapsack(int coin[], int sum,int n){
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(coin[i-1]<=j){
                t[i][j]=min(1+t[i][j-coin[i-1]] , t[i-1][j]);  //we add 1 because in that condition we are taking the coin
            } // so thats why we initialized INT_MAX-1 , bcz addition of 1 above results in negative no/overflow
            else if(coin[i-1]>j){
                t[i][j]=t[i-1][j];
            }
        }
    }

  return t[n][sum];
};
*/

/*
class Solution {
public:
    int coinChange(vector<int>& arr, int sum) {
        int n=arr.size();
        int t[n+1][sum+1];
   
        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(j==0) t[i][j]=0;
                if(i==0) t[i][j]=INT_MAX-1;
            }
            if(i==1){
                for(int j=1;j<sum+1;j++){
                    if(j%arr[0]==0){
                        t[i][j]=j/arr[0];
                    }
                    else t[i][j]=INT_MAX-1;
                }
            }
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(arr[i-1]<=j){
                    t[i][j]=min(1+t[i][j-arr[i-1]] , t[i-1][j]);  
                } 
                else if(arr[i-1]>j){
                    t[i][j]=t[i-1][j];
                }
            }
        }
        if(t[n][sum]==INT_MAX-1) return -1;
      return t[n][sum];
        
         
    }
        

};
*/