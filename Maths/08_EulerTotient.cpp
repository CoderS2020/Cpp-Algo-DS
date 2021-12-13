/*
Euler Totient Function (ETF) counts the number of positive integer upto n which are co-prime to n
coprime- gcd is 1
Phi(5)=4 bcz gcd(1,5)=gcd(2,5)=gcd(3,5)=gcd(4,5)=1
phi(10)=4 bcz gcd(1,10)=gcd(3,10)=gcd(7,10)=gcd(9,10)=1

brute force
int Phi(int n){ //O(nlogn)
    int count=0;
    for(int i=1;i<=n;i++){
        if(gcd(i,n)==1){
            count++;
        }
    }
    return count;
}

*** Phi(p)=p-1 where p should be prime

Phi(p^x) = p^x - no of integers not coprime with p 
         = p^x - no of multiple of p
         = p^x - (p^x/p)   [ eg no of multiples of 3 uptill 100 =100/3]
         = p^(x-1) (p-1)

Phi(p^x) = p^x - (p^x/p)


An arithmetic function f(x) is called multiplicative if f(n*m)= f(n)*f(m) where gcd(n,m)=1[coprime]

Phi(n)= n* ((p1-1)/p1) * ((p2-1)/p2) * ((p3-1)/p3) * ... * ((pk-1)/pk) [ p is prime upto n ie 2,3,5,...]

eg. phi(6)=6*(2-1)*(3-1)/(2*3)

#include<bits/stdc++.h>
using namespace std;

int phi(int n){ O(sqrt(n))
    int res= n;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            res=res/i;
            res=res*(i-1);

            //Because of this while loop we ensure that only prime factors are considered ( dry run)
            while(n%i==0){ //number may have same prime factor repeated (12=2*2*3)
                n/=i;
            }
        }
    }

    if(n>1){ // if n itself is a prime (because the loop runs till sqrt(n) and not till n)
        res=res/n;
        res=res*(n-1);
    }
    return res;
}

int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        cout<<"ETF("<<n<<")="<<phi(n)<<"\n";
    }
}

//Efficient way to find phi(n) O(nlog(logn))

Using sieve array
1. Initialize an array with i ie [1,2,3,...]
2. For multiples of primes do division with prime and multiply by (prime-1)

#include<bits/stdc++.h>
using namespace std;
int phi[1000001];

void init(int maxN){
    for(int i=1;i<=maxN;i++){
        phi[i]=i; //step 1 : initialization
    }
    for(int i=2;i<=maxN;i++){
        if(phi[i]==i){
            for(int j=i;j<=maxN;j+=i){
                phi[j]=phi[j]/i; //or phi[j]=phi[j]/phi[i]; phi[i]= i (both are same , look at line 80)
                phi[j]=phi[j]*(i-1);
            }
        }
    }
}

int main(){
    init(1000000);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<phi[n]<<"\n";
    }
}
*/

/*
ans=sum(i=1 to n) gcd(i,n)

//brute force: Time complexity for q queries O(q*nlogn)
int res=;
for(int i=1;i<=n;i++){
    res+=gcd(i,n);
}
return res;

//efficient: TC = O(nlogn + q* sqrt(n))

int getCount(int d,int n){

    return phi[n/d]; //find phi array using precomputation
}


int main(){
    int q,n;
    cin>>q;
    while(q--){
        cin>>n;
        int res=0;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                int d1=i; //d1,d2 are divisors
                int d2=n/i; 

                res+=d1*getCount(d1,n); //getCount() tells us how many nos are there from i=1 to n such that gcd(i,n)=d1
                if(d1!=d2) //for a perfect square like 25, d1==d2 , to avoid double counting we put if clause
                    res+=d2*getCount(d2,n);
            }
        }
        cout<<res<<"\n";
    }
}


*/