#include<bits/stdc++.h>
using namespace std;

//Variable size sliding window
int main(){

    string s;
    cin>>s;
    int k;
    cin>>k;
    int i=0,j=0;
    map<char,int> m;
    int ans=0;
    while(j<s.length()){

        //calculation
        m[s[j]]++;
        


        if(m.size()<k){
            j++;
        }
        else if(m.size()==k){
            //ans
            ans=max(ans,j-i+1);
            j++;
        }
        else if(m.size()>k){
            while(m.size()>k){
                //remove calculation
                
                m[s[i]]--;
                if(m[s[i]]==0){
                    m.erase(s[i]);
                }
                i++;
            }
            j++;
        }


    }
    cout<<ans<<endl;
   return 0;
}