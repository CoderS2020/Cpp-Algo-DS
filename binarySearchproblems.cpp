#include<bits/stdc++.h>
using namespace std;





int main(){

    //Rotated array is given and we have to find the number of rotations that have been made to the original array to get the input array.
/*
    // int arr[8]={1,2,3,4,5,6,7,8};--original array

    int arr[8]={3,4,5,6,7,8,1,2};
    //here the number of rotations will be 2 i.e. size-(index of minimum element)
    //secondly the minimum element always lies in the unsorted subarray
    //thirdly the minimum element is placed such that it is smaller to the elements in left and right
    int n=8;
    int left=0,right=n-1;
    while(left<=right){
        int mid=left+(right-left)/2;

        if(arr[mid]<= arr[(mid+n-1)%n] && arr[mid]<=arr[(mid+1)%n]){
            cout<<(n-mid)<<" "; break;
        }
        
        if(arr[left]< arr[mid] && arr[mid] > arr[right]){
            left=(mid+1)%n;
        }
        else if(arr[left]>arr[mid] && arr[mid]< arr[right]){
            right=(mid+n-1)%n;
        }
        



    }
    //if you are told to find an element in an rotated sorted array:
    //first find the index of minimum element(from above code) , that is you get 2 sorted arrays (left,mid-1) and (mid,right)
    //then apply binary search to these two arrays and of course only one array of the two is going to return right index and other is going to return -1

*/

    //Given a nearly sorted array , find the element 
    //Nearly sorted array: the element which is at position i in the sorted array will be at position i-1 or i or i+1 in nearly sorted array.
/*
    int arr[5]={5,10,30,20,40};
    int x=20;

    int start=0,end=4;
    
    while(start<=end){
        int mid=start+(end-start)/2;

        
        if(arr[mid]==x){
            cout<<mid; break;
        }
        else if (arr[mid-1]==x && mid-1>=start){
         cout<<mid-1; break;

        }
        else if (arr[mid+1]==x  && mid+1<=end){
            cout<<mid+1; break;
        } 

        if(arr[mid]>x){
            end=mid-2; //in normal bst it is mid-1 but here since in base case we checked for mid,mid-1 , hence here it is mid-2
        }
        else if(arr[mid]<x){
            start=mid+2;  //in normal bst it is mid+1 but here since in base case we checked for mid,mid+1 , hence here it is mid+2
        }



    }
*/

//Find floor of an element in a sorted array : floor- greatest element smaller than given value(if that value does not exist)
/*int arr[9]={1,2,3,4,8,10,10,12,19};
int x=16;

int start=0,end=8;
int res=0;
while(start<=end){
    int mid=start+(end-start)/2;

    if(arr[mid]==x){
        res=mid; break;
    } 

    if(arr[mid]>x){
        end=mid-1;
    }
    else if(arr[mid]<x){
        res=max(res,mid);
        start=mid+1;
    }



}

cout<<res<<endl;
*/

//Find ceil of an element in a sorted array; ceil- smallest element greater than given value(if that value does not exist)
/*int arr[9]={1,2,3,4,8,10,10,12,19};
int x=5;


int start=0,end=8;
int res=1000;
while(start<=end){
    int mid=start+(end-start)/2;
    if(arr[mid]==x){
        res=mid; break;
    }

    else if(arr[mid]<x){
        start=mid+1;
    }
    else if(arr[mid]>x){
        end=mid-1;
        res=min(res,mid);
    }
}
cout<<res<<endl;
*/

//Now you can find floor and ceil without using res and in the same code - arr[start] gives floor and arr[end] gives ceil
// cout<<arr[start]<<" "<<arr[end]<<endl; 


//Next Alphabetical Element
/*
char arr[7]={'a','g','h','j','l','o','z'};
char x='g';

int start=0,end=6;
char res='z';
while(start<=end){
    int mid=start+(end-start)/2;
    if(arr[mid]==x){
        
        start=mid+1;
    }
    else if(arr[mid]>x){
        res=min(res,arr[mid]); // or res=arr[mid];
        end=mid-1;
    }
    else if(arr[mid]<x){
        start=mid+1;
    }



}
cout<<res<<endl;
*/


//Find position of an element in infinite sorted array
/*
//Place start at 0 and end at 1 position (bcz we dont know end of infinite) and try to bring the element to be searched within the start and end pointers.
int arr[10]={1,2,3,4,9,78,122,150,170,200};

int start=0,end=1;
int x=78;
while(arr[end]<x){
    start=end;
    end=end*2; //binary here also(increases by 2)
}

while(start<=end){
    int mid=start+(end-start)/2;
    if(arr[mid]==x){
        cout<<mid; break;
    }
    else if(arr[mid]<x){
        start=mid+1;
    }
    else if(arr[mid]>x){
        end=mid-1;
    }
}
*/

//Find index of first 1 in a binary sorted infinite array eg.001111...
/*
int arr[15]={0,0,0,0,0,0,1,1,1,1,1,1,1,1,1};
int res=100;

int start=0,end=1;
while(arr[end]!=1){
    start=end;
    end=end*2;
}

while(start<=end){
    int mid=start+(end-start)/2;
    if(arr[mid]==1){
        res=min(mid,res);
        end=mid-1;
    }
    else if(arr[mid]<1){
        start=mid+1;
    }
    else if(arr[mid]>1){
        end=mid-1;
    }
}
cout<<res;
*/


//Minimum Difference Element in a Sorted Array
/*
//A value is given and you have to search in the array an element whose subtraction with the value is minimum in the entire array.
//1.If the key is present in the array then key-key=0 which is surely going to be minimum.
//2.If key is not present then find ceil and floor and check which one is min and ouput

int arr[5]={1,3,8,10,15};
int key=100;

int res=0,flag=0;

int start=0,end=4;
while(start<=end){
    int mid=start+(end-start)/2;
    if(arr[mid]==key){
        res=mid; flag=1; break;
    }

    else if(arr[mid]>key){
        res=max(res,mid);
        end=mid-1;
    }
    else if(arr[mid]<key){
        res=max(res,mid);
        start=mid+1;
    }

}

if(!flag){
    if(abs(arr[res]-key)< abs(arr[res-1]-key) ){
        cout<<arr[res];
    }
    else{
        cout<<arr[res-1];
    }
}
else{
    cout<<arr[res];
}

*/

//Peak Element(Element which is greater than its adjacent neighbors(if they exist))
//Here array is not sorted but still we use Binary Search

//Some problem in this code
/*int arr[6]={1,5,7,10,3,2};


int low=0;
int high=4;

while(low<=high){
    int mid=low+(high-low)/2;


    if(mid<4 && mid>0 && arr[mid]>arr[mid-1] && arr[mid]<arr[mid+1]){
        cout<<arr[mid]; break;
    }
    else if(arr[mid-1]>arr[mid]){
        high=mid-1;
    }
    
    else if(arr[mid+1]>arr[mid]){
        low=mid+1;
    }

    
    else if(mid==0){
        if(arr[0]>arr[1]){
            cout<<arr[mid]; break;

        } 
    }
    else if(mid==4){
        if(arr[4]>arr[3]){
            cout<<arr[mid]; break;

        }
    }
    
}
*/


//Find Maximum Element in Bitonic Array
//Bitonic: Monotonically increasing then decreasing
//Only one peak-> Thus find peak element (the same as previous one)

//Search in row wise and column wise sorted matrix
int arr[4][4]={{10,20,30,40},{15,25,35,45},{27,29,37,48},{32,33,39,50}};
int x=19;

//Worst case time complexity : O(n+m)
//Start from upper right corner
int n=4;
int i=0,j=n-1;
int flag=0;
while(i>=0 && i<n && j>=0 && j<n){

    if(arr[i][j]==x){
        cout<<i<<" "<<j<<endl; flag=1; break;
    }

    else if(arr[i][j]>x){
        j--;
    }
    
    else if(arr[i][j]<x){
        i++;
    }

}
if(flag==0) cout<<"Element not present"<<endl;





   return 0;
}