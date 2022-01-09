#include<bits/stdc++.h>
using namespace std;

//In an array if we want to find and update an array and we want to complete it in lesser time we use segment trees ie. O(logn) both for query and update

//We use divide and conquer approach to use segment trees.
//Segment trees -> at every mid of given array we divide it into two parts. BT like structure
//No of levels/height= 1+log(n)[base 2]
//No of nodes=(2n-1)
//For safety we make segment tree of 4*n size

const int N=1e5+2;
int a[N],tree[4*N];

void build(int node,int start,int end){
    if(start==end){
        tree[node]=a[end];
        return ;
    }

    int mid=(start+end)/2;
    build(2*node,start,mid);
    build(2*node+1,mid+1,end);
    tree[node]=tree[2*node]+tree[2*node+1];
}

int main(){

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    build(1,0,n-1);
    for(int i=1;i<=15;i++){
        cout<<tree[i]<<endl;
    }
   return 0;
}