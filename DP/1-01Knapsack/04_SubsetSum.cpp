/*
An array is given and you have to find if there exists a subarray that has given sum.

//Identification: You are given a sum (max capacity of knapsack) , also choice to either take the element or not

When only 1 array is given consider it as weight array and ignore the value array

*/
#include<bits/stdc++.h>
using namespace std;
/*
bool t[n+1][sum+1];
for(int i=0;i<n+1;i++){
    for(int j=0;j<sum+1;j++){
        if(i==0) t[i][j]=false; //if i==0 ,ie no elements then sum will always be 0

        if(j==0) t[i][j]=true; //there will always be empty subset for every set that gives sum as 0
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

*/