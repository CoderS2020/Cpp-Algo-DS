#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,k;
    cin>>n>>k;
    int arr[n]={0};
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int i=0,j=0;
    queue<int> q;
    vector<int> ans;
    while(j<n){
        q.push(arr[j]);

        if(j-i+1<k){
            j++;
        }
        else if(j-i+1==k){
            while(q.front()<arr[j]){
                q.pop();
            }
            ans.push_back(q.front());

            if(q.front()==arr[i]){
                q.pop();
            }
            i++;j++;
        }
    }

    for(auto it=ans.begin();it!=ans.end();it++){
        cout<<*it<<" ";
    }
   return 0;
}