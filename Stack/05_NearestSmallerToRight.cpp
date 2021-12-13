/*
int n=5
int arr[n]={4,5,2,10,8};
ans=[2,2,-1,8,-1]
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=5;
    int arr[n]={4,5,2,10,8};
    vector<int> v;
    stack<int> s;
    
    for(int i=n-1;i>=0;i--){
        if(s.size()==0){
            v.push_back(-1);
        }
        else if(s.size()>0 && s.top()<arr[i]){
            v.push_back(s.top());
        }
        else if(s.size()>0 && s.top()>=arr[i]){
            while(s.size()>0 and s.top()>=arr[i]){
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

    reverse(v.begin(),v.end());
    for(auto it:v){
        cout<<it<<" ";
    }


   return 0;
}