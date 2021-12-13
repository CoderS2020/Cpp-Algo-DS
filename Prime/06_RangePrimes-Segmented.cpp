/*
Print all primes in range (L,R)
L,R are the range. L,R<=10^12 ; R-L<=10^6
*/
//Since it is 10^12 and although if we declare sieve array globally it can be 10^8 max
//Hence we use segmented sieve

//Segmented Sieve
//1. Generate prime till sqrt of r
//2. Create a dummy array of size (r-l+1) and it begins with l,l+1,l+2,l+3,....r-1,r. Mark them 1
//3. Mark all multiples of primes in (l,r) in dummy as false

#include<bits/stdc++.h>
using namespace std;

const int N=1000000; //worst case 10^12 , sqrt(10^12)=10^6
bool sieve[N+1];
void createSieve(){
    for(int i=2;i<=N;i++){
        sieve[i]=true;
    }

    for(int i=2;i*i<=N;i++){
        if(sieve[i]==true){
            for(int j=i*i;j<=N;j+=i){
                sieve[j]=false;
            }
        }
    }
}

vector<int> generatePrimes(int n){
    vector<int> ds;
    for(int i=2;i<=n;i++){
        if(sieve[i]==true){
            ds.push_back(i);
        }
    }
    return ds;
};

int main(){
    createSieve(); //O(10^6)
    int l,r;
    cin>>l>>r;
    
    //step 1 : generate all primes til sqrt(r)
    vector<int> primes=generatePrimes(sqrt(r)); //O(10^6)
    
    //step 2 : create a dummy array of size r-l+1 and make everyone as 1
    int dummy[r-l+1]; //O(10^6)
    for(int i=0;i<r-l+1;i++){
        dummy[i]=1;
    }

    //step3: Mark all multiples of primes in (l,r) in dummy as false
    for(auto pr:primes){
        int firstMultiple=(l/pr)*pr; //it has to be int,no float or double
        if(firstMultiple<l) firstMultiple+=pr;

        for(int j=max(firstMultiple,pr*pr);j<=r;j+=pr){
            dummy[j-l]=0;
        }
    }

    //step 4 : get all the primes
    for(int i=l;i<=r;i++){
        if(dummy[i-l]==1){
            cout<<i<<" ";
        }
    }

   return 0;
}