#include<bits/stdc++.h>
using namespace std;
/*
int main(){

    int n,k;
    cin>>n>>k;
    int arr[n]={0};
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int i=0,j=0,sum=0,ans=0;
    while(j<n){
        sum=sum+arr[j];

        if(sum<k){
            j++;
        }
        else if(sum==k){
            ans=max(ans,j-i+1);
            // sum=sum-arr[i]; // we dont do these two steps because the next element might be 0 , which will add to the length keeping the sum same.
            // i++;
            j++;
        }
        else if(sum>k){
            while(sum>k){
                sum=sum-arr[i];
                i++;
            }
            //At this position i.e. at the end of while loop the sum is either ==k or <k , in both cases we had done j++ previously, same is repeated here.
            j++;
        }
    }
    cout<<ans<<endl;
   return 0;
}*/


//The above approach would work only for positive numbers in the array , but if we have negative numbers also in the array then it wont work because negative numbers decrease the sum and there are chances that we might find the sum k again as we traverse forward in the array with same i but increasing j. However with the above approach when we find sum greater than k , we move i ahead and thus forgetting that because we have negative numbers ahead we might get the same sum with same i.

int main(){

    int n,k;
    cin>>n>>k;
    int arr[n]={0};
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int maxlength=0,sum=0;
    map<int,int> m;

    for(int i=0;i<n;i++){

        sum=sum+arr[i];

        if(sum==k){
            maxlength=i+1; //with i starting from 0 this will be considered as answer since it largest.
        }

        if(m.find(sum)==m.end()){
            m[sum]=i; //so here we first check if map has that particular sum's index or not. If it is not there previously then we write it, however if it is already there then we dont update it because we have already gotten the sum's address and as we are moving from i=0 to i=n which means the lowest address for that particular sum is already there and the lowest address will be helpful for us to find largest distance, highest address wont be of any use.
        }

        if(m.find(sum-k)!=m.end()){ 
            if(maxlength<(i-m[sum-k])){ //i-m[sum-k]= length of new subarray with sum k. i->sum , sum-k ->extra sum thus extra sum - sum= k
                maxlength=i-m[sum-k];  //here we remove the extra sum to make sum as k , and if the corresponding length is greater then update the maxlength
            }
        }
    }
    cout<<maxlength<<endl;
    return 0;
}