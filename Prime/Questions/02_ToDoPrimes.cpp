// https://www.spoj.com/problems/TDPRIMES/

#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int	 

const ll n=100000000;
bool sieve[n+1];

void createSieve(){
    for(ll i=2;i<=n;i++){
        sieve[i]=true;
    }

    for(ll i=2;i*i<=n;i++){
        if(sieve[i]==true){
            for(ll j=i*i;j<=n;j+=i){
                sieve[j]=false;
            }
        }
    }
}

vector<ll> getPrimes(){
    vector<ll> ans;
    for(ll i=2;i<=n;i++){
        if(sieve[i]==true) ans.push_back(i);
    }
    return ans;
}

int main(){
    createSieve();
    vector<ll> ans=getPrimes();
    for(ll i=0;i<ans.size();i+=100){
        cout<<ans[i]<<" ";
    }

   return 0;
}