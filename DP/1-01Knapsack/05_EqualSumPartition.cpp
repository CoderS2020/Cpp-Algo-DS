/*
Given an array and you have to divide it into 2 parts(not necessary of same size) 
such that both the parts have equal sum. Tell if it is possible to do so or 

Intuition:-
If the total sum of all the elements is odd then return false,
else check if there exists any subarray such that it sum =(totalsum/2) [other subarray will automatically equal totalsum/2]
*/

#include<bits/stdc++.h>
using namespace std;

/*
bool t[n+1][sum+1];
for(int i=0;i<n+1;i++){
    for(int j=0;j<sum+1;j++){
        if(i==0) t[i][j]=false; //if i==0 ,ie no elements then sum will always be 0

        if(j==0) t[i][j]=true; //there will always be empty subset for every set that givens sum as 0
    }
}

bool subsetSum(int arr[], int sum,int n){
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){
                t[i][j]= t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }

  return t[n][sum];
};


//main function
for(int i=0;i<n;i++) sum+=arr[i];

if(sum%2!=0) return false;
else if(sum%2==0) return subsetSum(arr,sum/2,n);


*/

