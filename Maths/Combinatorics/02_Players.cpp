/*
2N players are participating in a tournament, find the no of pairings Pn for
first round. Order of the rounds does'nt matter.

//Method 1
For eg. n=2; 1,2,3,4
4 has 3 options to pair with , then 3 has 2 options to pair with
P(n)=(2n-1)*P(n-1)

eg. n=3; 1,2,3,4,5,6
6 has 5 options to pair with, then 5 has 4 options to pair with
P(3)=(5)*P(4) [2nth person has 2n-1 options and 2n-1th person has 2n-2 matches and so on]
P(n)=(2n-1)*P(n-1)

p1=1
p2=3*p1=3
p3=5*p2=5*3*1
and so on..
so we can claim that p(n)= product of odd nos in range [1,2n] i.e. product of first n odd numbers

//Method 2
for eg n=3
6C2*4C2*2C2 [ first round- from 6 choose 2 , second round- from 4 choose 2, round three- from 2 choose 2]
But we have to divide it by n! ( because in the question the order is same ie (2,3) is same as (3,2) , so dont calculate twice and hence remove the additional pair)
ans=(6C2*4C2*2C2)/3!

ie (2nC2 * 2n-2C2 * .... * 2C2 )/ n!
after expanding and solving further the above equation, we get :
= (2n)!/((2!)^n) *n! [ we divide by n! because we dont want the same pair to be counted twice]
after further solving we get
=  product of odd nos in range [1,2n] i.e. product of first n odd numbers [ same as previous method]

//Method 3
n=2 1,2,3,4
1,2   3,4
1,2 can be placed as 1,2 or 2,1 i.e. 2! (intra changing)
3,4 can be placed as 3,4 or 4,3 ie. 2! ways (intra changing)
also between 1,2 and 3,4 we can write 1,2 first or 3,4 first so again 2! (changing order of pairing- inter changing)

i.e. (2!)^n * n!

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN=1e6;
const ll mod =1e9+7;

ll ans[MAXN];
int main(){

    ans[1]=1;
    //precomputation
    for(int i=2;i<MAXN;i++){
        ans[i]=(ans[i-1]* (2*i-1))%mod;
    }
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        cout<<ans[n]<<endl;
    }
    cin>>t;

   return 0;
}