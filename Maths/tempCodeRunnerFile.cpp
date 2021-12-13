
#include<bits/stdc++.h>
using namespace std;

int main(){

   int q,a,b,c;
   cin>>q;
   for(int i=1;i<=q;i++){
      cin>>a>>b>>c;
      int g= __gcd(a,b);
      if(c%g) cout<<"Case "<<i<<": No"<<endl;
      else cout<<"Case "<<i<<": Yes"<<endl;
   }
   return 0;
}