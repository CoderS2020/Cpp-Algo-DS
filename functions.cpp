#include<iostream>
#include<math.h>
using namespace std;
/* 1. bool isPrime(int num){
        for(int i=2;i<=sqrt(num);i++){
            if(num%i==0){
                return false;
            }
        }
        return true;
    }
int main(){
      //Print prime numbers between 2 given numbers using functions.
    int a,b;
    cin>>a>>b;
    for(int i=a;i<=b;i++){
        if(isPrime(i)){
            cout<<i<<endl;
        }
    }
    return 0;
}*/
/*//2 Fibonacci Sequence
void fib(int n){
    int t1=0;
    int t2=1;
    int nextTerm;
    for(int i=1;i<=n;i++){
        cout<<t1<<endl;
        nextTerm=t1+t2;
        t1=t2;
        t2=nextTerm;
    }
    return ;
}
int main(){
    int n;
    cin>>n;
    fib(n);
    return 0;
}*/

/*//3. Factorial
int fact(int n){
    if(n==00 || n==1){
        return 1;
    }
    else{
        return n*fact(n-1);
    }
}
int main(){
    int n;
    cin>>n;
    cout<<fact(n);
    return 0;
}*/

/*//nCr=n!/(n-r)!*r!*/
/*int fact(int n){
    if(n==00 || n==1){
        return 1;
    }
    else{
        return n*fact(n-1);
    }
}
int main(){
    int n,r;
    cin>>n>>r;
    cout<<fact(n)/(fact(r)*fact(n-r));
    return 0;
}*/

/*
Pascals triangle
1
11
121
1331
14641
*/
/*int fact(int n){
    if(n==00 || n==1){
        return 1;
    }
    else{
        return n*fact(n-1);
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<=n-1;i++){
        for(int j=0;j<=i;j++){
            cout<<fact(i)/(fact(j)*fact(i-j));
        }
        cout<<endl;
    }
    return 0;
}*/