/*
Given an array, find the top k most frequent elements
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=8;
    int arr[n]={1,1,1,3,2,2,4,3};
    int k=3;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(auto it:mp){
        pq.push({it.second,it.first});
        if(pq.size()>k) pq.pop();
    }

    while(!pq.empty()){
        cout<<pq.top().second<<" ";
        pq.pop();
    }

   return 0;
}