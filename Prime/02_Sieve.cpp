#include<bits/stdc++.h>
using namespace std;

int n=1000000;
bool sieve[1000001];
//O(nlog(logN))
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

// Inside main function, int array can be of 10^6 size but globally it can be 10^7
// Inside main function, bool array can be of 10^7 size but globally it can be 10^8
//So choose where to declare sieve array according to constraints

int main(){
    createSieve();
    

   return 0;
}