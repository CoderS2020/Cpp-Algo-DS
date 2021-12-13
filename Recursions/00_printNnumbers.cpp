#include<bits/stdc++.h>
using namespace std;

//print 1 to n
void print(int n){

    if(n==1){
        cout<<"1"<<" ";
        return;
    }

    print(n-1);
    cout<<n<<" ";


}

//print n to 1
void printreverse(int n){
    if(n==1){
        cout<<n<<" ";
        return;
    }

    cout<<n<<" ";    
    printreverse(n-1);
    
}

int factorial(int n){
    if(n==0 || n==1){
        return 1;
    }

    return n*factorial(n-1);


}

int main(){
    int n;
    cin>>n;
    // print(n);
    // printreverse(n);
    cout<<factorial(n);

   return 0;
}