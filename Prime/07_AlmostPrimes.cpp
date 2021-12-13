/*
Find no of natural nos <=n that are almost primes
A no is almost prime if it is of the form p1*p2, where p1!=p2 and p1,p2 are primes
n<=3000 

Dont forget to check that p1!=p2!=1
*/
#include<bits/stdc++.h>
using namespace std;
/*

bool is_prime(int x){
    if(x==1) return false;
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            return false;
        }
    }
    return true;
}

bool is_almost_prime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            if(is_prime(i) && is_prime(n/i) && n!=i){
                return true;
            }
            else{
                return false;
            }

        }
    }
    return false;
}

int main(){

    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++){
        if(is_almost_prime(i)){
            ans+=1;
        }
    }
    cout<<ans<<endl;

   return 0;
}*/

//if n<=1e5

const int MAXN=1e5+5;
bool prime[MAXN];

void prime_sieve(){
    for(int i=1;i<MAXN;i++){
        prime[i]=true;
    }
    prime[1]=false;
    for(int i=2;i*i<MAXN;i++){
        if(prime[i]=true){
            for(int j=i*i;j<MAXN;j+=i){
                prime[j]=false;
            }
        }
    }
};

bool almost_prime[MAXN];
int computeAnswer(int n){
    for(int i=2;i<=n;i++){
        if(prime[i]){
            for(int j=i;j<=n;j+=i){
                if(prime[j/i] && j/i!=i){
                    almost_prime[j]=true;
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(almost_prime[i]){
            ans++;
        }
    }
    return ans;
}

int main(){
    prime_sieve();
    int n;
    cin>>n;
    cout<<computeAnswer(n);
    return 0;
}

//Another method
/*
Find all the prime multiples of a no (using sieve-> sieve[i]/i ->loop untill we get 1)

*/