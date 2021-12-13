// https://www.spoj.com/problems/PRIME1/

#include<bits/stdc++.h>
using namespace std;

const int n=1000000;
bool sieve[n+1];
void createSieve(){
    for(int i=2;i<=n;i++){
        sieve[i]=true;
    }

    for(int i=2;i*i<=n;i++){
        if(sieve[i]==true){
            for(int j=i*i;j<=n;j+=i){
                sieve[j]=false;
            }
        }
    }
};

vector<int> generatePrimes(int n){
    vector<int> ans;
    for(int i=2;i<=n;i++){
        if(sieve[i]==true)ans.push_back(i);
    }
    return ans;
}

int main(){
    createSieve();
    int t;
    cin>>t;
    while(t--){
        int l,r;
        cin>>l>>r;
        vector<int> primes=generatePrimes(sqrt(r));

        int dummy[r-l+1];
        for(int i=0;i<r-l+1;i++){
            dummy[i]=1;
        }

        for(auto pr:primes){
            int firstMultiple=(l/pr)*pr;
            if(firstMultiple<l) firstMultiple+=pr;

            for(int j=max(firstMultiple,pr*pr);j<=r;j+=pr){
                dummy[j-l]=0;
            }
        }

        for(int i=l;i<=r;i++){
            if(dummy[i-l]==1){
                if(i!=1)
                    cout<<i<<"\n";
            }
        }
        cout<<"\n";

        
    }


   return 0;
}