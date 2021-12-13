#include<bits/stdc++.h>
using namespace std;

int main(){

    string s;
    cin>>s;
    map<char,int> m;
    int i=0,j=0,ans=0,count=0;
    while(j<s.length()){
        //condition
        m[s[j]]++;
        count++;
        if(m.size()<2){
            j++;
        }
        else if(m.size()==2){
            // ans
            ans=max(ans,count);
            j++;
        }
        else if(m.size()>2){
            while(m.size()>2){
                if(m.find(s[i])!=m.end()){
                    m[s[i]]--;
                    count--;
                    if(m[s[i]]==0){
                        m.erase(s[i]);
                    }
                }
                i++;
            }
            j++;
        }
    }
    cout<<ans;
   return 0;
}