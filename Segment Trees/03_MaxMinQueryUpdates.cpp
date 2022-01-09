//Find max and min in the given query
#include<bits/stdc++.h>
using namespace std;

const int N=1e5+2;
int a[N],tree[4*N];

void buildMaxSeg(int node,int start,int end){
    if(start==end){
        tree[node]=a[end];
        return ;
    }

    int mid=(start+end)/2;
    buildMaxSeg(2*node,start,mid);
    buildMaxSeg(2*node+1,mid+1,end);
    tree[node]=max(tree[2*node],tree[2*node+1]);
}

int query(int node,int st,int end,int l, int r){
    if(st>r or end<l)return INT_MIN;

    if(l<=r and end<=r)return tree[node];

    int mid=(st+end)/2;
    int q1=query(2*node,st,mid,l,r);
    int q2=query(2*node+1,mid+1,end,l,r);

    return max(q1,q2);
}

void update(int node,int st,int end,int idx,int val){
    if(st==end){
        a[st]=val;
        tree[node]=val;
        return;
    }

    int mid=(st+end)/2;
    if(idx<=mid){
        update(2*node,st,mid,idx,val);
    }
    else{
        update(2*node+1,mid+1,end,idx,val);
    }

    //Backtracking
    tree[node]=max(tree[2*node],tree[2*node+1]);
}


int main(){

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    buildMaxSeg(1,0,n-1);
    while(1){
        int type;
        cin>>type;
        if(type==-1)break;

        if(type==1){
            int l,r;
            cin>>l>>r;
            int ans=query(1,0,n-1,l,r);
            cout<<ans<<endl;
        }
        else if(type==2){
            int idx,val;
            cin>>idx>>val;
            update(1,0,n-1,idx,val);
            cout<<query(1,0,n-1,0,n)<<endl;
        }
    }


    return 0;
}