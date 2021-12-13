#include<iostream>
using namespace std;

//Check if the array is sorted or not
/*bool sorted(int arr[],int n){

    if(n==1){
        return true;
    }

    bool restArray = sorted(arr+1,n-1);
    return (arr[0]<arr[1] && restArray);
  
}

int main(){
    int arr[]={1,12,3,4};
    cout<<sorted(arr,4);
    return 0;
}*/

//Print numbers till n in increasing and decreasing order
/*
void dec(int n){
    if(n==0){
        return;
    }
    cout<<n;
    dec(n-1);
}

void inc(int n){
    if(n==0){
        return;
    }
    inc(n-1);
    cout<<n;
}

int main(){
    int n;
    cin>>n;
    dec(n);
    cout<<endl;
    inc(n);

    return n;
}*/

//First and last occurence of a number in an array

int firstocc(int arr[],int n,int i,int key){
    if(i==n){
        return -1;
    }

    if(arr[i]==key){
        return i;
    }
    return firstocc(arr,n,i+1,key);
}

int lastocc(int arr[],int n,int i,int key){
    if(i==n){
        return -1;
    }
    int restArr=lastocc(arr,n,i+1,key);
    if(restArr!=-1){
        return restArr;
    }
    if(arr[i]==key){
        return i;
    }
    return -1;
    

    
}
int main(){
    int arr[]={2,5,3,9,5,3,9};
    cout<<firstocc(arr,7,0,3)<<endl;
    cout<<lastocc(arr,7,0,3)<<endl;
    return 0;
}