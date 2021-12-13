/*
Given A, count the no of right angled triangles with integer length in which the length of a
non hypotenuse edge is A.
1<=A<=1e5

ie. A^2=C^2-B^2
A^2=(C-B)(C+B)
i.e. xy=(C-B)(C+B) [x*y=A^2]
i.e. c=(x+y)/2
i.e. b=(y-x)/2

So find factors (x,y) of A^2, and check if x<y , x,y->both even or x,y->both odd (dry run factors to understand)


*/

#include<bits/stdc++.h>
using namespace std;

int count(int n){
    int ans=0;
    for(int x=1;x*x<=n*n;x++){
        if(n%x==0){
            int y=n/x;
            if(x<y && (x%2==y%2)){
                int c=(x+y)/2;
                int b=(y-x)/2;
                ans++;
            }
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<count(n)<<endl;
    }


   return 0;
}