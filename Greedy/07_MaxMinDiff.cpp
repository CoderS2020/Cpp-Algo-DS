#include<bits/stdc++.h>
using namespace std;
/*
You are given an array A of n elements, You have to remove exactly n/2 elements from array A and add it to
another array B. Find the maximum and minimum values of differences between these two arrays. We define
the difference between these two arrays as : Sum(abs(A[i]-B[i]))
*/


int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i:a) cin>>i;
    sort(a.begin(),a.end());
    long long mn=0,mx=0;
    //Remember the following technique
    for(int i=0;i<n/2;i++){
        mx+=a[n-1-i]-a[i]; //diff of max and min elements after sorting OR mx+=a[i+n/2]-a[i] also is permissible bcz it is add-subtract so eventually it will give the same result
        mn+=a[2*i+1]-a[2*i]; //diff of odd and even indexed numbers
    }
    cout<<mn<<" "<<mx<<endl;

   return 0;
}