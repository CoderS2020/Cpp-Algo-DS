#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
       cin>>v[i];
    }
    map<int,int> m;
    
    int prefsum[n]={0};
    prefsum[0]=v[0];
    m[prefsum[0]]++;
    for(int i=1;i<n;i++){
       prefsum[i]=prefsum[i-1]+v[i];
       m[prefsum[i]]++;
    }

    map<int,int> :: iterator it;
    int ans=0;
    for(it=m.begin();it!=m.end();it++){
       ans+=it->second*(it->second-1)/2; //ans=m*(m-1)/2;
       if(it->first==0){
          ans+=it->second;
       }
    }
   cout<<ans;





   return 0;
}