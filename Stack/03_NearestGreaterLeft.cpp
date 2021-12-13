/*
Brute force-O(n^2)

*/

#include<bits/stdc++.h>
using namespace std;



int main(){
    int n=4;
    int arr[4]={1,3,2,4};
    vector<int> v;
    stack<int> s;

for(int i=0;i<n;i++){ //travelling reverse
    if(s.size()==0){
        v.push_back(-1);
    }
    else if(s.size()>0 && s.top()>arr[i]){
        v.push_back(s.top());
    }
    else if(s.size()>0 && s.top()<=arr[i]){
        while(s.size()>0 && s.top()<=arr[i]){
            s.pop();
        }
        if(s.size()==0){
            v.push_back(-1);
        }
        else{
            v.push_back(s.top());
        }
    }
    s.push(arr[i]);
}
// reverse(v.begin(),v.end()); no reverse required
for(auto it:v){
    cout<<it<<" ";
}
   return 0;
}