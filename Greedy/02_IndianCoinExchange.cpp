#include<bits/stdc++.h>
using namespace std;

//You are given an array of Denominations and a value x. You need to find the minimum number of coins
//required to make value X.We have infinite supply of each coin.

/*
Approach: Start from the largest value , till we can include it, else move to the next smaller value
*/

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int x;
    cin>>x;

    sort(arr.begin(),arr.end(), greater<int>());
    int count=0;
    for(int i=0;i<n;i++){
        count+=x/arr[i];
        x=x - (x/arr[i]) * arr[i]; // to find remainder: no - (no/divisor)*divisor [we do this bcz in c++ division returns int value]
    }

    cout<<count<<endl;

   return 0;
}