/*1444A codeforces
Given p,q , find largest x where x is a factor of p; x isnt a multiple of q
p<=1e18
q<=1e9

For eg. p=8,q=24 
24= 1,2,3,4,6,8,12,24
Thus largest no which is a factor of p but not a multiple of q is 12

So store all the factors of p, then travel from right to left(descending order) bcz we want largest x
*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long

//method 1 : brute force
/*int main(){
    ll p,q;
    cin>>p>>q;
    ll ans=0;
    for(ll i=1;i*i<=p;i++){ //O(sqrt(p))
        if(p%i==0){
            //i and p/i are factors
            if(i%q!=0){ //i is not a multiple of q
                ans=max(ans,i);
            }
            if((p/i)%q!=0){ // p/i is not a multiple of q
                ans=max(ans,p/i);
            }
        }
    }
    cout<<ans;
    return 0;
}*/

//method 2 

const int MAXN=50000;
bool is_prime[MAXN];
vector<int> primes;

void prime_sieve(){
    is_prime[1]=0;
    for(int i=2;i*i<=MAXN;i++){
        if(is_prime[i]){
            for(int j=i*i;j<=MAXN;j+=i){
                is_prime[j]=true;
            }
        }        
    }
    for(int i=2;i<MAXN;i++){
        if(is_prime[i]){
            primes.push_back(i);
        }
    }
};

vector<int> getPrimefactors(ll q){
    vector<int> prime_factors;
    for(auto u:primes){
        if(q%u==0){
            prime_factors.push_back(u);
            while (q%u==0)//through this while loop we remove(divide) all the prime factors present in q
            {
                q/=u;
            }
            
        }
    }
    //for a given number there can be only one prime factor greater than equal to sqrt(n) [important]
    //eg . for 34 there is only one prime factor greater than sqrt(34) which is 17
    if(q>1){ 
    //as prime factors are removed through above while loop, however one prime factor is going to remain
    //this prime factor is nothing but the above discussed prime factor greater than sqrt(q) which was 
    // not considered in while loop becasue untill the the value of u came to this last prime factor
    // the other previously travelled primes took the value of q less than sqrt(q) , thus one prime factor
    // was left, and we are storing this 
        prime_factors.push_back(q);
    }
    return prime_factors;
}

int main(){
    prime_sieve();
    ll p,q;
    cin>>p>>q;
    if(p%q>0){
        cout<<p<<endl;
        return 0;
    }
    vector<int> prime_factors=getPrimefactors(q);

    ll ans=1;
    for(int y:prime_factors){
        //y is a prime factor of q
        ll x=p;
        while(x%q==0){ //untill we get a no which is non-multiple keep on removing prime factor
            x/=y;   // thus through this we get a no which is as high as possible and not a multiple of q
        }
        ans=max(ans,x);
    }
    cout<<ans<<endl;


   return 0;
}
