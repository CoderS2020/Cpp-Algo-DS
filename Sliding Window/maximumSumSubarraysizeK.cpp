#include<bits/stdc++.h>
using namespace std;

/*
int main(){

    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    //Brute Force Approach (O(n^2))
    // int maxSum=0;
    // for(int i=0;i<n-k+1;i++){
    //     int sum=0;
    //     for(int j=0;j<k;j++){
    //         sum+=v[i+j];
    //     }
    //     maxSum=max(sum,maxSum);
    // }
    // cout<<maxSum<<endl;

    //Using Sliding Window (O(n))
    // int initialsum=0;
    // for(int i=0;i<k;i++){
    //     initialsum+=v[i];
    // }
    // int maxSum=initialsum;
    // for(int i=k;i<n;i++){
    //     initialsum=initialsum+v[i]-v[i-k];
    //     maxSum=max(maxSum,initialsum);
    // }
    // cout<<maxSum<<endl;

    //Complex version of sliding window
    // int i=0,j=0,sum=0,maxSum=0;
    // while(j<n){

    //     sum+=v[j];

    //     if(j-i+1<k){
    //         j++;
    //     }
    //     else if(j-i+1==k){
    //         maxSum=max(maxSum,sum);
    //         sum-=v[i];
    //         j++;i++;
    //     }


    // }
    // cout<<maxSum<<endl;



   return 0;
}*/

