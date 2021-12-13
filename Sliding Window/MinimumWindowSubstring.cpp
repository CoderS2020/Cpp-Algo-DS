#include<bits/stdc++.h>
using namespace std;

int main(){
    string s="tasjhcosdfjhtsocjscssto";
    string w="toc";
    map<char,int> m;
    for(int i=0;i<w.length();i++){
        m[w[i]]++;
    }

    int i=0,j=0,count=m.size(),ans=INT_MAX;
    while(j<s.length()){
        
        if(m.find(s[j])!=m.end()){
            m[s[j]]--;
            if(m[s[j]]==0){
                count--;
            }
        }


        if(count<m.size()){
            j++;
        }
        else if(count==m.size()){
            ans=min(ans,j-i+1);
            j++;
        }
        else if(count>m.size()){
            while(count>m.size()){
                if(m.find(s[i])!=m.end()){
                    m[s[i]]++;
                    if(m[s[i]]==1){
                        count++;
                    }

                }
                i++;
            }
            j++;
        }
    }
    cout<<ans<<endl;

    return 0;
}