#include<iostream>
using namespace std;

/*
//Find a unique number in an array where all numbers except one are present twice
int main(){
    int arr[7]={2,4,6,3,4,3,2};
    int xorsum=0;
    for(int i=0;i<7;i++){
        xorsum=xorsum^arr[i];
    }
    cout<<xorsum<<endl;
    
    return 0;
}*/


//Find 2 unique nos in an array where all numbers except 2 are present twice

/*
int getBit(int n,int pos){
    return (n&(1<<pos));
}
void unique(int arr[],int n){
    int xorsum=0;
    for(int i=0;i<n;i++){
        xorsum=xorsum^arr[i];
    }
    int tempsum=xorsum;
    int setbit=0;
    int pos=0;
    while(setbit!=1){
        setbit=xorsum & 1;
        pos++;
        xorsum=xorsum>>1;
    }
    xorsum=0;
    for(int i=0;i<n;i++){
        if(getBit(arr[i],(pos-1))){
            xorsum=xorsum^arr[i];
        }
    }
    cout<<xorsum<<endl;
    cout<<(xorsum^tempsum)<<endl;

}

int main(){
    int arr[8]={2,4,6,7,4,5,6,2};
    unique(arr,8);
    return 0;
}*/

//Find unique number in an array where all numbers except one are present thrice
/*bool getBit(int no,int pos){
    return ((no & (1<<pos))!=0);
}

int setBit(int n,int pos){
    return (n|(1<<pos));
}

int unique(int arr[],int n){
    int result=0;
    for(int i=0;i<64;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            if(getBit(arr[j],i)){
                sum++;
            }
        }
        if(sum%3!=0){
            result=setBit(result,i);
        }
    }
    return result;
}

int main(){
    int arr[]={1,2,3,4,1,2,3,1,2,3};
    cout<<unique(arr,10);
    return 0;
}*/