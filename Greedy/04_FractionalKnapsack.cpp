#include<bits/stdc++.h>
using namespace std;

/*
We are given n itmes with {value,weight} of each item and the capacity of knapsack (Sack) 'W'.
We need to put these items in a knapsack such that final value of items in knapsack is maximum.
*/

bool compare(pair<int,int> p1,pair<int,int> p2){
   double v1=(double) p1.first/p1.second;
   double v2=(double) p2.first/p2.second;

   return v1>v2;

}

int main(){
   int n;
   cin>>n;
   vector<pair<int,int>> a;
   for(int i=0;i<n;i++){
      cin>>a[i].first>>a[i].second;
   }
   int w;
   cin>>w;
   sort(a.begin(),a.end(),compare);

   int ans=0;
   for(int i=0;i<n;i++){
      if(w>a[i].second){
         ans+=a[i].first;
         w-=a[i].second;
         continue;
      }
      double vw=(double) a[i].first/a[i].second; //taking fraction if we cant include everything
      ans+=vw*w; //remaining weight
      w=0;
      break;
   }
   cout<<ans<<endl;

   return 0;
}