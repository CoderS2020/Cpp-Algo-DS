#include<iostream>
using namespace std;
/*
//To check if the number is a power of 2 or not
int powerofTwo(int n){
    return (n&& !(n&(n-1)));  we do n&& because we want to handle base case if n==0
}
//[when you flip the right most bit and all bits after that of number 'n' , then u get n-1]
 //also if ans=n&(n-1), then  ans has same bits as n except the right most set bit -VVImp

Thus, if a number is divisible by 2 then n has only 1 set bit and n-1 will have all set bits after that position

int main(){
    cout<<powerofTwo(16);
    return 0 ;
}

//OR

int main(){

    int n;
    cin>>n;
    if(n==1) cout<<"n";return 0;

    int N=__builtin_popcount(n);
    if(N==1){ 
        cout<<'y'<<endl;
    }
    else{
        cout<<'N'<<endl;
    }
    return 0;
}

*/

/*
//Number of 1's in binary representation of a number
int Numberof1(int n){
    int count=0;
    while(n){ //n is true i.e. n!=0 since all non-zero numbers are by default true
        n=(n&(n-1)); // since only right most set (1) bit differs, '&' of n,n-1 will eliminate one set bit in each iteration
        count++;
    }
    return count;
}
int main(){
    cout<<Numberof1(7);
    return 0;
}*/


/*
//Program to generate all possible subsets of a set
void subset(char arr[],int n){
    for(int i=0;i<(1<<n);i++){ // 2^n can be written as 1<<n
        for(int j=0;j<n;j++){
            if(i & (1<<j)){
                cout<<arr[j]<<" ";
            }
        }
        cout<<endl;
    }
}


int main(){

    int n=3;
    char arr[n]={'a','b','c'};
    subset(arr,n);
    return 0;
}*/

//Number of subarrays ith element appears in= i*(n-i+1) [1-based indexing]