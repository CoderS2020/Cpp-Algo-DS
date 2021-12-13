#include<bits/stdc++.h>
using namespace std;

//No of prime factors at max will be log(n) to base 2
const int n=1000000;
int arr[n+1];
void createsieve(){
    //O(n*log(log(n)))
    for(int i=2;i<=n;i++){
        arr[i]=i;
    }

    for(int i=2;i<=n;i++){
        if(arr[i]==i){
            for(int j=i*i;j<=n;j+=i){
                if(arr[j]==j){
                    arr[j]=i;
                }
            }
        }        
    }   
};

void printPrime(int k){
     while(k!=1){ //O(log(n))
        cout<<arr[k]<<" ";
        k=k/arr[k];
    }
}


int main(){
    // cout<<"in";
    createsieve();
    int k;
    cin>>k;
    printPrime(k);


   return 0;
}

/*
//1.It wont be O(n^2) because the inner while loop reduces n as n=n/i
//In worst case if it is a prime no then it will be O(n)
for(i=2;i<=n;i++){
    while(n%i==0){
        print(i);
        n=n/i;
    }
}

//2. Worst Case : O(sqrt(n))
for(i=2;i*i<=n;i++){
    while(n%i==0){
        print(i);
        n=n/i;
    }
}
if(n>1) print(n); //since we are using i*i<=n so the no greater than sqrt(n) will
                    not be considered since it will break, but for prime nos then
                    it will create problem (try to do dry run), thats why at the end
                    we check if n is still greater than 1 then print n itself

*/