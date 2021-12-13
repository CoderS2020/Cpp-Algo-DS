/*
Q1)Given n<=10^12, tell if it has exactly 3 positive divisors
There are t (<=10^5) test cases
eg. 25=1,5,25

Note: Most numbers have even no factors because the factors come in pair 12=(2*6) (3*4) etc
The only time a no will have odd no of factors is when the no is a perfect square

Solution: A number will always have 1 and itself as factors (25 has 1 & 25 as factors), 
so now out of 3 only 1 factor is remaining .A number will have only one factor if it is a perfect square
//25,36,49, etc

Thus, If sqrt(n) is prime then it has 3 divisors

Q2)Given n<=10^12, tell if it has exactly 5 positive divisors
2 factors 1 & n already there, other three factors can come if it is n^4
ie. find sqrt(sqrt(n)) where n is prime

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

/*Method 1
ll square_root(ll n){
    for(ll i=1;i*i<=n;i++){
        if(i*i==n) return i;
    }
    return -1;
}

bool is_prime(ll n){
    if(n==1) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}

bool check_three_divisors(ll n){
    ll a=square_root(n);
    if(a==-1) return false;
    if(is_prime(a)){
        return true;
    }
    return false;

}

int main(){
    ll n;
    cin>>n;
    if(check_three_divisors(n)){
        cout<<"True";
    }
    else{
        cout<<"False";
    }

    return 0;
}*/

set<ll> myBucket;
const int maxN=1e6+5;
bool isPrime[maxN];

void prime_sieve(){
    for(int i=1;i<=maxN;i++){
        isPrime[i]=true;
    }

    for(int i=2;i*i<=maxN;i++){
        if(isPrime[i]){
            for(int j=i*i;j<=maxN;j+=i){
                isPrime[j]=false;
            }
        }
    }

    for(ll i=2;i<=maxN;i++){
        if(isPrime[i]){
            myBucket.insert(i*i);
        }
    }
};


bool checkThreeDiv(ll n){
    if(myBucket.find(n)!=myBucket.end()){
        return true;
    }
    return false;
}


int main(){
    prime_sieve();
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        if(checkThreeDiv(n)){
            cout<<"YES\n";
        }
        else cout<<"NO\n";
    }

   return 0;
}