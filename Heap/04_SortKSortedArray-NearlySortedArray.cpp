/*
Given an array that is nearly sorted/ k sorted, ie. the value that should have been present on the given index
is present anywhere at a distance of k from the given index in left/right. From this given array, find
the sorted array.s
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=7,k=3;
    int arr[n]={6,5,3,2,8,10,9};
    priority_queue<int,vector<int>, greater<int>> pq;
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
        if(pq.size()==k){
            cout<<pq.top()<<" ";
            pq.pop();
        }       
    }

    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }


   return 0;
}