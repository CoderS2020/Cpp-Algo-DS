/*
gcd(a,b) is the maximum divisor of a and b
84=2^2+3^1+7^1
63=2^0+3^2+7^1

gcd(84,63)=2^0+3^1+7^1 (compare the correspoding prime factors and take one with minimum power)
We take minimum power prime factor since it will divide both unlike maximum power prime factor

gcd(a,b)=gcd(a%b,b) [if a>b]
gcd(x,0)=x 

Also gcd(a,b) * lcm(a,b) = a*b
Calculate gcd and then correspondingly calculate lcm
*/
#include<bits/stdc++.h>
using namespace std;

//O(log b)
int gcd(int a,int b){ //a>b
    if(b==0){
        return a;
    }
    else{
        return gcd(b,a%b);
    }
}

/*
Observations:
a) gcd(a,0)=gcd(0,a)=a
gcd(a,b)=gcd(a-b,b)=gcd(a,b-a)


*/


//https://www.codechef.com/problems/GCDQ
//Precomputation
int pre[100005],suff[100005];
int arr[100001];

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        // int arr[n];
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        pre[0]=suff[n+1]=0;

        for(int i=1;i<=n;i++){
            pre[i]=gcd(pre[i-1],arr[i]);
        }

        for(int i=n;i>=1;i--){
            suff[i]=gcd(suff[i+1],arr[i]);
        }
        while(q--){
            int l,r;
            cin>>l>>r;
            cout<<gcd(pre[l-1],suff[r+1]);
        }

    }


   return 0;
}