#include<bits/stdc++.h>
using namespace std;

bool check(int mid,int arr[],int n,int m){
    int students=1;
    int pages=0;
    for(int i=0;i<n;i++){
        pages+=arr[i];

        if(pages>mid){
            students++;
        }

        if(students>m){
            return false;
        }
    }
    return true;
}

int main(){
    int n,m;
    cin>>n>>m;
    int arr[n]={0};
    int maximum=-1,sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
        maximum=max(maximum,arr[i]);
    }

    int start=maximum,end=sum;
    int result=INT_MAX;

    while(start<=end){
        int mid=start+(end-start)/2;
        if(check(mid,arr,n,m)){
            result=min(result,mid);
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    cout<<result<<" ";
   return 0;
}