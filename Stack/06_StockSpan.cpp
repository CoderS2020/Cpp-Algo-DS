/*
Given an array, find the consecutive smaller or equal numbers before it

Brute force
vector<int> v;
for(int i=0;i<n;i++){
        int ans=1;
        for(int j=i-1;i>=0;j--){
            if(arr[j]<=arr[i]){
                ans++;
            }
            else break;
        }
        v.push_back(ans);
    }
*/

#include<bits/stdc++.h>
using namespace std;

//Consecutive smaller to left == nearest greater to left
/*Find nearest greater to left of each element(index) and then when we subtract curr_ind-calc_index we get ans
Since now I want index as well so we will make a stack<pair<int,int>> to store (elem,index);
*/

int main(){
    int n=7;
    int arr[n]={100,80,60,70,60,75,85};
    vector<int> v;
    stack<pair<int,int>> s;
    for(int i=0;i<n;i++){
        if(s.size()==0){
            v.push_back(-1);
        }
        else if(s.size()>0 and s.top().first>arr[i]){
            v.push_back(s.top().second);
        }
        else if(s.size()>0 and s.top().first<=arr[i]){
            while(s.size()>0 and s.top().first<=arr[i]){
                s.pop();
            }
            if(s.size()==0){
                v.push_back(-1);
            }
            else if(s.top().first>arr[i]){
                v.push_back(s.top().second);
            }
        }
        s.push({arr[i],i});
    }

    for(int i=0;i<n;i++){
        cout<<i-v[i]<<" ";
    }
       return 0;
}