//find max sum of subarray from given array

#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    vector<int> v(n);

    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    int curr=0,maxTillNow=0;

    for(int i=0;i<n;i++){
        curr+=v[i];
        maxTillNow=max(curr,maxTillNow);

        if(curr<0)curr=0;
    }

    cout<<maxTillNow<<endl;

   return 0;
}