/*
Formula --> (a*b)%p=((a%p)*(b%p))%p
            (a+b)%p= (a%p + b%p)%p
            For division the same formula does not work, we use inverse there
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=1e9+5;
//find a^b modulo mod

ll power(ll a,ll b){ //similar to binary exponentiation
    if(b==0) return 1;

    ll x=power(a,b/2);
    ll ans=1;
    if(b%2){
        ans = (x*x)%mod;
        ans=(ans*a)%mod;
    }
    else{
        ans=(x*x)%mod;
    }
    return ans;
}

int main(){

    cout<<power(2,1e5);
   return 0;
}

/*
a and b are said to be congruent to each other under modulo N, if they leave same remainder when divided by N
eg. 13%7=6 and 41%7=6 so 13,41 are congruent under modulo 7

if a and b are congruent under modulo N ,then (a-b)%n==0 ie. (a-b) is divisible by N
Also a=N*k + b (k is a factor)

If a*b=c
then a%n * b%n = c%n

Q . Find last digit of 2573*34268?
(2573*34268)%10 = (2573%10 *34268%10)%10 = (3*8)%10 =24%10=4

Q. (142+453+324+781+523)%2=?
(142%2+453%2+324%2+781%2+523%2)%2=(0+1+0+1+1)%2=3%2=1

Divisibility by 9 and 3
If the sum of numbers is divisible by 9 then it is divisible by 9
eg (142+453+324+781+533+250+714)%3
(10+0+0+1+2+1+0)%3 = 5%3=2

If a%N=b%N then a^k%N=b^k%N


Q. (29^10)%3
29%3 = 2
also 2%3 = 2
hence (29^10)%3 = (2^10)%3 = 1024%3 =7%3=1

Q. 2^123456789 %7
=(2^3)^41152263%7
= (8^41152263)%7
=1^41152263%7=1
*/

// https://codeforces.com/contest/742/problem/A

ll power_n(int a, ll n,ll p){
   if(n==0) return 1;
    ll res=1;
    ll x=power_n(a,n/2,p);
    if(n%2==0){
        res=(x*x)%p;
    }
    else{
        res=(x*x)%p;
        res=(res*a)%p;
    }
    return res;
}

int main(){
    ll n;
    cin>>n;
    cout<<power_n(1378,n,10)  ;
    //or 
    // cout<<power_n(8,n,10)  ;

   return 0;
}

//
/*
https://www.codechef.com/problems/GCDMOD

If you need to calculate gcd(x,y) where x is very large but y is very small then
we would find potential gcd candidates and apply modulo arithmetic to find gcd

gcd(a,b) is a number that is greatest divisor of a,b ; so if a is too large and b is too small
we can calculate divisors of b(smaller no) and then find the largest no among them


*/

#define lli long long int
const lli mod=1e9+7;

lli power_find(lli a, lli n,lli p){
   if(n==0) return 1;
    lli res=1;
    lli x=power_find(a,n/2,p);
    if(n%2==0){
        res=(x*x)%p;
    }
    else{
        res=(x*x)%p;
        res=(res*a)%p;
    }
    return res;
}

//We calculate the factors of a-b and return 
lli gcd_find(lli a,lli b,lli n){
    if(a==b){
        return (power_find(a,n,mod)+ power_find(b,n,mod))%mod;
    }
    lli candidate=1;
    lli num=a-b;
    // a-b is always lesser than a^n+b^n, hence we calculate its factors and then check if 
    // these factors (i,n/i) are factors of a^n+b^n also and store the max
    for(lli i=1;i*i<=num;i++){
        if(num%i==0){ //factors are i,n/i
            lli temp=(power_find(a,n,i)+power_find(b,n,i))%i;
            if(temp==0) candidate=max(candidate,i);
            
            temp=(power_find(a,n,num/i)+power_find(b,n,num/i))%(num/i);
            if(temp==0) candidate=max(candidate,num/i);
        }
    }
    
    return candidate%mod;
}

int main(){
    lli a,b,n,t;
    cin>>t;
    while(t--){
        cin>>a>>b>>n;
        cout<<gcd_find(a,b,n)<<endl;
    }

   return 0;
}

/*
Modulo Inverse

Modulo inverse n under modulo p exists if and only if gcd(n,p)=1
*/



