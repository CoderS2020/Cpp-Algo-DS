/*
Given array- sort it based on frequency
int n=7;
int arr[n]={1,1,1,3,2,2,4};
return ans[n]={1,1,1,2,2,3,4}
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=7;
    int arr[n]={1,1,1,3,2,2,4};
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    priority_queue<pair<int,int>> pq;
    for(auto it:mp){
        pq.push({it.second,it.first});
    }

    while(!pq.empty()){
        int freq=pq.top().first;
        int ele=pq.top().second;
        for(int i=1;i<=freq;i++){
            cout<<ele<<" ";
        }
        pq.pop();
    }


   return 0;
}