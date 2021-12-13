/*
array=[4,5,2,10,8]
ans=[-1,4,-1,2,2]

Brute force
for(int i=0;i<n;i++){
    bool flag=false;
    for(int j=i-1;j>=0;j--){ //j is dependent on i
        if(arr[j]<arr[i]) ans[i]=arr[j],flag=true;
    }
    if(!flag) ans[i]=-1;
}
*/

#include<bits/stdc++.h>
using namespace std;



int main(){
    int n=5;
    int arr[n]={4,5,2,10,8};
    vector<int> v;
    stack<int> s;
    for(int i=0;i<n;i++){
        if(s.size()==0){
            v.push_back(-1);
        }
        else if(s.size()>0 && s.top()<arr[i]){
            v.push_back(s.top());
        }
        else if(s.size()>0 && s.top()>=arr[i]){
            while(s.size()>0 && s.top()>=arr[i]){
                s.pop();
            }
            if(s.size()==0){
                v.push_back(-1);
            }
            else if(s.top()<arr[i]){
                v.push_back(s.top());
            }
        }
        s.push(arr[i]);
    }
    for(auto it:v){
        cout<<it<<" ";
    }
    return 0;
}