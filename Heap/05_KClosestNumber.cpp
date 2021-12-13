/*
Given an array,k and x, you have to find k elements from the given array that are closest to value x.
*/

#include<bits/stdc++.h>
using namespace std;

int main(){

    int n=5;
    int arr[n]={5,6,7,8,9};
    int k=3,x=7;
    priority_queue<pair<int,int>> pq;
    for(int i=0;i<n;i++){
        pq.push({abs(x-arr[i]),arr[i]});
        if(pq.size()>k){
            pq.pop();
        }
    }
    while(!pq.empty()){
        cout<<pq.top().second<<" ";
        pq.pop();
    }
   return 0;
}