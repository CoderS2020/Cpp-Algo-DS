#include<iostream>
using namespace std;

//Sieve of Eratosthenes Approach - To find prime numbers uptill given number
/*void sieve(int n){
    int arr[n]={0};
    for(int i=2;i<n;i++){
        if(arr[i]==0){
            for(int j=i*i;j<=n;j+=i){
                arr[j]=1;            
            }
        }
    }

    for(int i=2;i<=n;i++){
        if(arr[i]==0){
            cout<<i<<" ";
        }
    }
}
int main(){
    
    sieve(50);

    return 0;
}*/



//To find prime factors of a given number

void sieveprime(int n){
    int arr[n];
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

    while(n!=1){
        cout<<arr[n]<<" ";
        n=n/arr[n];
    }


}


int main(){

    sieveprime(10);
    return 0;
}