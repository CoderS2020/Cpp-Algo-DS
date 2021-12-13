/*
Given an array and k , find kth largest element
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=6;
    int arr[n]={7,10,4,3,20,15};
    int k=3;

    priority_queue<int,vector<int>,greater<int>>  maxh;
    for(int i=0;i<n;i++){
        maxh.push(arr[i]);
        if(maxh.size()>k){
            maxh.pop();
        }
    }
    cout<<maxh.top();


   return 0;
}