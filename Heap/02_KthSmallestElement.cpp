/*
Given an array and k , find kth smallest element
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=5;
    int arr[n]={7 ,10 ,4 ,20 ,15};
    int k=4;

    priority_queue<int>  maxh;
    for(int i=0;i<n;i++){
        maxh.push(arr[i]);
        if(maxh.size()>k){
            maxh.pop();
        }
    }
    cout<<maxh.top();


   return 0;
}