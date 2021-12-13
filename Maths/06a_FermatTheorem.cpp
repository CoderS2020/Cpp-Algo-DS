/*


Fermat Theorem : a^(p-1)%p=1 [where p is prime, a is not multiple of p]

for 1<=a<=p-1

-----------

1/a=a^(p-2)
a^-1=a^(p-2)%p (power of a is -1)[important]

Q)Calcualate (a/b)%p
Ans] a/b=a*(b^-1)
(a/b)%p=(a * b^(p-2))%p  [b^-1= b^(p-2)%p]

Q) ((37)^1234)%7

1234%6=4
hence (37^1234) % 7 = (37^6x * 37^4) %7
 = (1 * 37^4)%7
 = (37^4)%7
 = ((35+2)^4)%7
 =  (2^4)%7 [ 35%7=0]
 =  16%7 = 2
*/


//Q Calculate nCr=n!/(n-r)!*r!
#include<bits/stdc++.h>
using namespace std;
#define ll long long 

const ll mod=1e9+7; //prime

ll power(ll a,ll b){
    if(b==0) return 1;
    ll ans=power(a,b/2);

    if(b%2==1){
        ans=(ans*ans)%mod;
        ans=(ans*a)%mod;
    }
    else{
        ans=(ans*ans)%mod;
    }
    return ans;
};

ll inv(ll A){
    return power(A,mod-2);
}

ll fac(ll n){
    ll ans=1;
    for(int i=1;i<=n;i++){
        ans=(ans*i)%mod;
    }
    return ans;
};

const int MAXN=1e5+5;
ll factorial[MAXN];
ll invfactorial[MAXN];
void precompute_fact(){
    factorial[0]=1;
    for(int i=1;i<MAXN;i++){
        factorial[i]=(factorial[i-1]*i)%mod;
    }
    for(int i=0;i<MAXN;i++){
        invfactorial[i]=inv(factorial[i]);
    }
}

void precompute_fact1(){
    factorial[0]=1;
    for(int i=1;i<MAXN;i++){
        factorial[i]=(factorial[i-1]*i)%mod;
    }
    invfactorial[MAXN-1]=inv(factorial[MAXN-1]);
    for(int i=MAXN-1;i>=1;i--){
        invfactorial[i-1]=(invfactorial[i]*i)%mod;
    }
}

/* Method 1: Higher TC
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,r;
        cin>>n>>r;
        ll nfact=fac(n);
        ll rfact=fac(r);
        ll nrfact=fac(n-r);
        ll numerator=nfact;
        ll denominator=(nrfact*rfact)%mod;
        ll ans=numerator*inv(denominator)%mod;
        cout<<ans;

    }

   return 0;
}*/

//Method 2 : Precomputation 
/*int main(){
    precompute_fact();
    int t;
    cin>>t;
    while(t--){
        int n,r;
        cin>>n>>r;
        ll nfact=factorial[n];
        ll rfact=invfactorial[r];
        ll nrfact=invfactorial[n-r];               
        ll ans=(nfact*rfact)%mod; //we could have done (nfact*rfact*nrfact) but this no will be too large ,so break in 2 parts
        ans=(ans*nrfact)%mod;
        cout<<ans;

    }

   return 0;
}*/

//Method 3: Calculate invfact array in lesser TC
int main(){
    precompute_fact1();
    int t;
    cin>>t;
    while(t--){
        int n,r;
        cin>>n>>r;
        ll nfact=factorial[n];
        ll rfact=invfactorial[r];
        ll nrfact=invfactorial[n-r];               
        ll ans=(nfact*rfact)%mod; 
        ans=(ans*nrfact)%mod;
        cout<<ans;

    }

   return 0;
}


//Trailing zeroes problem
//In a number the zeros will come only if it has 10 as one of its multiple
//eg. 250 = 5*5*5*2 (5*5*10)
// so what we do is take 5^a , 2^b and take min(a,b) and that is the answer
//eg. 720 = 3*3*2*2*2*5*2 (3^2*2^4*5^1) so consider 5^1 & 2^4 so min(1,4) =1 (the no of trailing zeros)


//For factorial we are always going to have 2's power larger than 5's power.
//So minimum is always going to be 5's power, so no need to calculate 2's power

//We can calculate power of a number using [n/i] + [n/i*i]+ [n/i*i*i] ...
//eg. 37!= 37/5+37/25 =7+1 = 8 zeroes (take floor division)


// int power_p(int n,int p){
//     int g=p;
//     int ans=0;
//     while(g<=n){
//         ans+=n/g;
//         g*=p;
//     }
//     return ans;
// };

// int trailing_zero(int n){
//     return power_p(n,5);
// }

// int main(){

//     int n;
//     cin>>n;
//     cout<<trailing_zero(n);
//    return 0;
// }

//Given n,r find trailing zeroes in nCr (here not necessary that power of 5 will be small than power of 2)

// int trailing_zero_nr(int n,int r){
//     int power2=power_p(n,2)-power_p(n-r,2)-power(r,2);
//     int power5=power_p(n,5)-power_p(n-r,5)-power(r,5);
//     return min(power2,power5);
// }
// int main(){

//     int n,r;
//     cin>>n>>r;
//     cout<<trailing_zero_nr(n,r);
//    return 0;
// }