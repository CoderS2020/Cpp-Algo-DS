#include<bits/stdc++.h>
using namespace std;


int solve(int n,int k){
    if(n==1 && k==1){
        return 0;
    }

    int mid=(pow(2,n-1))/2; //mid of previous row (No of elements in a row=2^n->take few testcases)
    if(k<=mid){
        return solve(n-1,k);
    }
    else{
        return (!solve(n-1,k-mid));
    }

}

int main(){

    int n,k;
    cin>>n>>k;
    cout<<solve(n,k);
   return 0;
}