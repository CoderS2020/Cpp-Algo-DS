#include<bits/stdc++.h>
using namespace std;
//https://www.spoj.com/problems/RMQSQ/

int main(){
    int n;
    cin>>n;
    vector<int> a(n,0);
    for(int i=0;i<n;i++)cin>>a[i];

    int len=(int)sqrtl(a.size())+1; //sqrtl is efficient
    vector<int> b(len,1e9);
    for(int i=0;i<n;i++){
        b[i/len]=min(b[i/len],a[i]);
    }

    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        int ans=1e9;

        for(int i=l;i<=r;){
            if(i%len==0 and i+len-1<=r){
                ans=min(ans,b[i/len]);
                i+=len;
            }
            else{
                ans=min(ans,a[i]);
                i++;
            }
        }
        cout<<ans<<endl;
    }

   return 0;
}