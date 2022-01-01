
#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b,int &x ,int &y){
   if(b==0){
      //(ax+by=gcd(a,b)) and gcd(p,0)=p
      x=1;
      y=0;
      return a; //gcd(p,0)=p so return gcd(a,b)=a
   }
   int x1,y1;
   int d=gcd(b,a%b,x1,y1);
   x=y1;
   y=x1-y1*(a/b);
   return d;
}

int main(){
   cout<<gcd(6,3,0,0);

   return 0;
}
