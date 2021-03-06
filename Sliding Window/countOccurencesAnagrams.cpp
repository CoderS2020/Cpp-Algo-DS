#include<bits/stdc++.h>
using namespace std;



int main(){
    string s="abdc";
    string w="abcd";
    map<char,int> m;
    for(int i=0;i<w.length();i++){
        m[w[i]]++;
    }

    int i=0,j=0,count=m.size(),ans=0;

    while(j<s.size()){

        if(m.find(s[j])!=m.end()){
            m[s[j]]--;

            if(m[s[j]]==0){
                count--;
            }
        }

        if(j-i+1<w.size()){
            j++;
        }
        else if(j-i+1==w.size()){
            if(count==0){
                ans++;
            }
            if(m.find(s[i])!=m.end()){
                m[s[i]]++;
                if(m[s[i]]==1){
                    count++;
                }
            }
            i++;j++;
        }
    }
    cout<<ans<<endl;

   return 0;
}

//Note: When we are performing Xor operation in sliding window , so in order to move to next window by removing
//the first element and adding next element for xor we do xor of first element in order to remove it since
//a^a=0 (so when we xor it again it is removed)