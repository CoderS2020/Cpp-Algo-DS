#include<bits/stdc++.h>
using namespace std;

int main(){
   int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++){
      cin>>arr[i];
   }
   bool flag=false;
   for(int num=0;num<(1<<n);num++){
      int ans=0;
      for(int j=0;j<n;j++){
         if(num&(1<<j)){
            ans+=arr[j];
         }
         else{
            ans-=arr[j];
         }
      }
      if(ans%360==0){
         cout<<ans<<"-";
         flag=true; break;
      }
   }
   if(flag){
      cout<<"YES\n";
   }
   else cout<<"NO\n";


   return 0;
}