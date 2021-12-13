#include<bits/stdc++.h>
using namespace std;

//Important
int main(){
   string s;
   cin>>s;
   
   int i=0,j=0,ans=0;
   map<char,int> m;
   while(j<s.size()){
      //calculation
      m[s[j]]++;
      
      //if the size of map(i.e. no of unique characters) is equal to current size of window then it is contendor of ans.
    if(m.size()==j-i+1){
         //ans
         ans=max(ans,j-i+1);
         j++;
      }
      else if(m.size()<j-i+1){ // it is '<' and  not '>'
         while(m.size()<j-i+1){
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