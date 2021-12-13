#include<bits/stdc++.h>
using namespace std;

int main(){

    //binary search on reverse sorted array
  /*  int arr[10]={20,17,15,14,13,12,10,19,8,4};
    int x=8;
    int start=0,end=9;
    

    while(start<=end){
        int mid=start+(end-start)/2;    
        if(arr[mid]==x){
            
            cout<<mid; break;
        }

        else if(arr[mid]>x){
            start=mid+1;
        }
        else if (arr[mid]<x){
            end=mid-1;
        }

    }*/

    //1st and last occurence of an element
    // int arr[7]={2,4,10,10,10,18,20};
    // int x=10;

/*    //first occurence
    cout<<lower_bound(arr,arr+7,10)-arr<<endl;

    //last occurence
    int index=upper_bound(arr,arr+7,10)-arr;
    index-=1;
    cout<<index<<endl;
*/

//without stl
//first occurence (lower bound)
  /*  int low=0,high=7;
    int res=0;
    while(low<=high){
        int mid=low+(high-low)/2;

        if(arr[mid]==x){
            res=mid;
            high=mid-1;
        }
        else if(arr[mid]<x){
            low=mid+1;
        }
        else if(arr[mid]>x){
            high=mid-1;
        }


    }
    cout<<res<<endl;*/

 //last occurence (upper bound)
/*int low=0,high=7;
    int res=0;
    while(low<=high){
        int mid=low+(high-low)/2;

        if(arr[mid]==x){
            res=mid;
            low=mid+1;
        }
        else if(arr[mid]<x){
            low=mid+1;
        }
        else if(arr[mid]>x){
            high=mid-1;
        }


    }
    cout<<res<<endl;
*/

//count of an element (if told to code upper and lower bound , you can use the above two pieces of code)
    /*int high=(upper_bound(arr,arr+7,10)-arr)-1;
    int low=lower_bound(arr,arr+7,10)-arr;
    cout<<high-low+1<<endl;*/



     




   return 0;
}

