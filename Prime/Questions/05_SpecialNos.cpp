//https://www.hackerearth.com/practice/math/number-theory/primality-tests/practice-problems/algorithm/bob-and-gems-f8226fbd/

#include<bits/stdc++.h>
using namespace std;

const int n=10000000;
int sieve[n+1];
void createSieve(){
    for(int i=2;i<=n;i++){
        sieve[i]=i;
    }

    for(int i=2;i*i<=n;i++){
        if(sieve[i]==i){
            for(int j=i*i;j<=n;j+=i){
                sieve[j]=i;
            }
        }
    }

};

int noOfPrimeFactors(int no){
    int count=0;
    set<int> s;
    
    while(no>1){
        if(s.count(sieve[no])==0){
            s.insert(sieve[no]);
            count++;
        }
        
        no=no/sieve[no];
    }
    return count;
}



int main(){
    createSieve();
    int p,t;
    cin>>p>>t;
    while(t--){
        int n;
        cin>>n;

        if(noOfPrimeFactors(n)>=p){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
   return 0;
}