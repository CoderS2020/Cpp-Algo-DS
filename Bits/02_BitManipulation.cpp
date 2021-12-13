#include<iostream>
using namespace std;

int main(){
    // a>>1 -> divides by 2 (right shift)
    // a<<1 -> multiplies by 2 (left shift )

    //Two swaps without using third variable
    //101 111=010
   /* int a=5;
    int b=7;
    a=a^b;
    b=a^b;
    a=a^b;
    cout<<a<<" "<<b<<endl;*/

    //To find number of 1's in a binary representation
/*  int count=0;
    int n=13;
    while(n!=0){
        count++;
        n=n&(n-1);      //Time complexity - O(n)- but n=no of 1's only
    }       
    cout<<count<<endl;
*/
        //OR
    /*int n=13;
    int count=0,ans=0;
    

    while(n!=0){
    ans=n&1;
    if(ans==1){
        count++;
    }
    n=n>>1;
    }
    cout<<count<<endl;
    // int ans=(13>>1);
    // cout<<ans; */


    return 0;
}