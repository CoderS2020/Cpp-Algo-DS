//https://spoj.com/problems/DQUERY/
//Check Code
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
struct Q{
    int l,r,idx;
};
int rootN;


bool compare(Q q1,Q q2){
    if(q1.l/rootN==q2.l/rootN)return q1.r> q2.r;
    return q1.l<q2.l;
};

int main(){
    Q q[N];
    int n;cin>>n;
    vector<int> a(n,0);
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

    sort(q,q+n,compare);

    vector<int> ans(queries,0);

    int curr_l=0,curr_r=-1,l,r;
    int curr_ans=0;
    vector<int> freq(1e6+5,0);

    for(int i=0;i<queries;i++){
        l=q[i].l;
        r=q[i].r;
        l--;r--;

        while(curr_r<r){
            curr_r++;
            freq[a[curr_r]]++;
            if(freq[a[curr_r]]==1)curr_ans++;
        }
        while(curr_l>l){
            curr_l--;
            freq[a[curr_l]]++;
            if(freq[a[curr_l]]==1)curr_ans++;
        }
        while(curr_l<l){
            freq[a[curr_l]]--;
            if(freq[a[curr_l]]==0)curr_ans--;
            curr_l--; //curr l reduced after updating
        }
        while(curr_r>r){
            freq[a[curr_r]]--;
            if(freq[a[curr_r]]==0)curr_ans--;
            curr_r--; //curr l reduced after updating
        }
        ans[q[i].idx]=curr_ans;
    }

    for(int i=0;i<queries;i++){
        cout<<ans[i]<<endl;
    }

   return 0;
}