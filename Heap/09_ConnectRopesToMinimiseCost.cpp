/*
Given an array representing sizes of ropes, we have to connect them, cost =sum of two ropes to be connected
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=5;
    int arr[n]={1,2,3,4,5};
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
        
    }
    int ans=0;
    while(pq.size()>=2){
        int first=pq.top();
        pq.pop();
        int second=pq.top();
        pq.pop();
        ans+=first+second;
        pq.push(first+second);
    }
    cout<<ans<<" "<<pq.top();

   return 0;
}