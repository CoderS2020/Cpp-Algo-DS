#include<bits/stdc++.h>
using namespace std;
//Check code

/*
General Structure of problem:
You are given an array of size n and q queries. Each query is a range query.
In each query, we have to perform some operation and output answer of each query.
Brute force -O(q*n)

Mo's Algorithm
Input all the queries simultaneously, sort the queries in a particular fashion
TC- 
Sorting all queries: qlog(q)
call for all blocks: (n/sqrt(n))*n
no of times change in value of curr_i->sqrt(n)*q
total TC: O((n+q)sqrt(n))
*/
int N=1e5+2;
int rootN;

struct Q{
    int idx,l,r;
};



bool compare(Q q1,Q q2){
    if((q1.l/rootN) == (q2.l/rootN))return q1.r>q2.r;
    return (q1.l/rootN )< (q2.l/rootN);
};

int main(){
    Q q[N];
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];

    rootN=sqrtl(n);
    int queries;
    cin>>queries;
    
    for(int i=0;i<queries;i++){
        int l,r;
        cin>>l>>r;
        q[i].l=l;
        q[i].r=r;
        q[i].idx=i;
    }

    sort(q,q+queries,compare);

    vector<int> ans(queries);
    int curr_l=0,curr_r=-1,l,r;
    int curr_ans=0;
    for(int i=0;i<queries;i++){
        l=q[i].l; r=q[i].r;
        l--;r--;

        while(curr_r<r){
            curr_r++;
            curr_ans+=a[curr_r];
        }
        while(curr_l>l){
            curr_l--;
            curr_ans+=a[curr_l];
        }
        while(curr_l<l){
            curr_l++;
            curr_ans-=a[curr_l];
        }
        while(curr_r>r){
            curr_r--;
            curr_ans-=a[curr_r];
        }
        ans[q[i].idx]=curr_ans;

    }
    for(int i=0;i<queries;i++){
        cout<<ans[i]<<endl;
    }

    return 0;
}