// https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-2/practice-problems/algorithm/ashu-and-prime-factors-4/

#include<bits/stdc++.h>
using namespace std;


const int n=1000000;
int sieve[n+1];

void createsieve(){
    for(int i=2;i<=n;i++){
        sieve[i]=1;
    }

    for(int i=2;i*i<=n;i++){
        if(sieve[i]==1){
            for(int j=i*i;j<=n;j+=i){
                if(sieve[j]!=0){
                    sieve[i]++;
                    sieve[j]=0;
                }
            }
        }
    }

}


int main(){
    createsieve();
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<sieve[n]<<"\n";
    }

   return 0;
}