/*
How many nos in range 1-10^6 have minimum prime factor as 'n'
*/
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
    int N;
    cin>>N;
    cout<<sieve[N]<<endl;
    return 0;    
}