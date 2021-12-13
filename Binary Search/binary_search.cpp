#include<bits/stdc++.h>
using namespace std;

int main(){
   int a[5]={1,2,6,8,7};
   cout<<binary_search(a,a+5,3)<<endl; //checks if 3 exists in the range or not
   cout<<binary_search(a,a+5,7)<<endl;


   //lower bound- returns a pointer pointing to the element and if that element does not exist then it points to the immediate next greater value of given element.
   cout<<lower_bound(a,a+5,4)-a<<endl; //lower_bound(start,end,value): returns an iterator ; to get the value we subtract a (which points to the start)

   //Using vector
   // cout<<lower_bound(a.begin(),a.end(),value) - a.begin();

   //upper bound: It points to the next greater element in the array irrespective whether the element exists or not.
   cout<<upper_bound(a,a+5,6)-a<<endl;
   cout<<upper_bound(a,a+5,2)-a<<endl;

   //Both upper_bound and lower_bound work in logn time.

   

    
   return 0;
}