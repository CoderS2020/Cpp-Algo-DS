
#include<iostream>
using namespace std;
/*int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int maxElem=INT_MIN;
  
    for(int i=0;i<n;i++){
        // if(arr[i]>maxElem){
        //     maxElem=arr[i];
        // } OR
        maxElem=max(maxElem,arr[i]);
    cout<<"Maximum till "<<i<<" is "<<maxElem<<endl;
    }
    return 0 ;
}*/

//Printing all sub arrays
/*int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum=0,k=0;
    for(int i=0;i<n;i++){
        sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            cout<<sum<<" ";
        }
 
      
    }
    cout<<endl;
    return 0;
}*/

//Number of subarrays ith element appears in= i*(n-i+1)
