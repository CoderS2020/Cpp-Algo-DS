/*
Given an array (ideally should have 1 to n nos) in which 1 number is missing and 1 number is duplicate(in place of missing one)

Approach 1: Use map to find missing and duplicate number.However it takes O(n) space

Approach 2: Using Maths
            Sum expected array - sum given array=> missing - duplicate
            Sum expected array square  - sum given array square=> missing^2 - duplicate^2
After getting above 2 equations then we can find answer.

Approach 3: Using Swap Sort
Ex: Given array: [5,2,3,1,1];
If we convert it to [1,2,3,1,5]; ie. expected elements at their respective position(arr[i]=i+1)
and duplicate no at missing no's position, then we can simply traverse the array then to find
duplicate no and missing number.

Using Swap Sort: Finding All missing and All duplicate numbers
Use same above approach, it works. Present numbers will be in correct positions and duplicate numbers
will be in missing numbers position
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    int i=0;
    while(i<arr.size()){ // the number of swap operations will be in worst case O(n-1) bcz no swap is unwanted
        if(arr[i]!=arr[arr[i]-1]){//thus we will get O(n+n-1) ie. O(2n-1) as TC ie O(n)
            swap(arr[i],arr[arr[i]-1]); 
        }
        else{
            i++;
        }
    }
    vector<int> missing,duplicate;
    for(int i=0;i<n;i++){
        if(arr[i]!=i+1){
            missing.push_back(i+1);
            duplicate.push_back(arr[i]);
        }
    }
    return missing,duplicate;


   return 0;
}