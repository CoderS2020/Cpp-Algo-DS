/*
Given an array that represents heights of buildings, find total area where water will trap

Approach: Find max elem to left and max elem to right, take min of both ht=min(left great,right great);
find heightWater[i]=ht-arr[i];, find sum of heightWater.

*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=6;
    int arr[n]={3,0,0,2,0,4};
    int mxLeft[n],mxRight[n];
    mxLeft[0]=arr[0]; //first elem's left is first elem itself

    for(int i=1;i<n;i++){
        if(mxLeft[i-1]<arr[i]){
            mxLeft[i]=arr[i];
        }
        else mxLeft[i]=mxLeft[i-1];
    }

    mxRight[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--){
        if(mxRight[i+1]<arr[i]){
            mxRight[i]=arr[i];
        }
        else mxRight[i]=mxRight[i+1];
    }

    int heightWater[n];
    int sum=0;
    for(int i=0;i<n;i++){
        heightWater[i]=min(mxLeft[i],mxRight[i])-arr[i];
        sum+=heightWater[i];
    }
    cout<<sum<<endl;

   return 0;
}