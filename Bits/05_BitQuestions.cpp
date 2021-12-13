#include<bits/stdc++.h>
using namespace std;

//Given n , print xor of all nos between (1-n)
/*
n     xor uptill n
n=1       1
2         3
3         0
4         4
5         1
6         7
7         0
8         8

Thus we can find a pattern
i.e. if(n%4==0) print(n)
if(n%4==1) print(1)
if(n%4==2) print(n+1)
if(n%4==3) print(0)

Thus solution is in O(1)
*/
/*
int main(){

   int n;
   cin>>n;
   if(n%4==0) cout<<n;
   if(n%4==1) cout<<1;
   if(n%4==2) cout<<n+1;
   if(n%4==3) cout<<0;

   return 0;
}*/

//Given range (l,r), print xor of given segment


int xorArray[1000000001]={0};

void preXor(){
   for(int i=1;i<1000000001;i++){
      if(i%4==0) xorArray[i]=i;
      if(i%4==1) xorArray[i]=1;
      if(i%4==2) xorArray[i]=i+1;
      if(i%4==3) xorArray[i]=0;
   }
};


int main(){
   preXor();
   int l,r;
   cin>>l>>r;
   if(l==0) cout<<xorArray[r];
   else cout<<(xorArray[r] ^ xorArray[l-1]);

   return 0;
}

/*
To check odd or even dont use modulu(it is expensive)
if(n&1==0) print(even)
else print(odd)
*/


/*
Count no of 1's
//Method 1
cnt=0;
while(n!=0){ O(no of bits) or O(MSB)
   if(n&1==1) cnt++;
   n=n>>1;
}

cnt=0; 
while(n!=0){ //O(no of set bits)
   n=n&(n-1);
   cnt++;
}

*/

/*
Given n integers, print xor of all subsets
a={1,2,3}
Subsets will be {1},{2},{3},{1,2},{1,3},{2,3},{1,2,3}
-> the ans is always going to be 0
*/

/*
//Power set algorithm: works only if n=16,17,18

Generate all subsets: [3,2,4]
No of subsets=2^n
#include<bits/stdc++.h>
using namespace std;

int main(){
   int n;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++) cin>>a[i];
   for(int num=0;num<(1<<n);num++){
      vector<int> bt;
      for(int bit=0;bit<n;bit++){
         if(num&(1<<bit)){
            bt.push_back(a[bit]);
         }
      }
      for(auto it: bt){
         cout<<it<<" ";
      }cout<<endl;
   }

   return 0;
}
*/

// https://codeforces.com/problemset/problem/1097/B
/*
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
         flag=true; break;
      }
   }
   if(flag){
      cout<<"YES\n";
   }
   else cout<<"NO\n";


   return 0;
}*/

//Bit Masking
/*
0<=n<=60
Design a data structure(like set) that performs following operations
1) add
2) remove
3) print all elements 
long long n=0;
add(5)-> n|(1<<5) -> n=32 (2^5=32)
add(1)-> n|(1<<1)-> n=33
remove(5)-> n^(1<<5) -> n=4 




*/