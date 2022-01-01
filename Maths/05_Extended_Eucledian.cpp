//GCD has property that ax+by=gcd(a,b)

//a,b,x,y,c are integers
//Given a,b,c ; solve for x,y where ax+by=c

/*
Bezout's Lemma: Given 2 integers a & b, their gcd d, then there exists x & y
such that ax+by=d 

Applications:
1) Calculate GCD of 2 integers
2) Find modulo inverse
3) Solution of Linear Diophantine Equation

*/


#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b,int &x ,int &y){
   if(b==0){
      //(ax+by=gcd(a,b)) and gcd(p,0)=p
      x=1;
      y=0;
      return a; //gcd(p,0)=p so return gcd(a,b)=a
   }
   int x1,y1;
   int d=gcd(b,a%b,x1,y1);
   x=y1;
   y=x1-y1*(a/b);
   return d;
}


/*
Linear Diophantine Equation (ax+by=c or x^2-y^2=z^2 ie. of same power)
Degenerate Case: When a=b=0 (degenerate case). There are 2 sub cases
a) when c=0, solutions are infinite
b) when c!=0, solutions : 0

Let x0 and y0 are solution of equation ax+by=g, then solution (multiply by c/g throughout)
of equation ax+by=c will be x=x0*(c/g) and y=y0*(c/g) [ However c should be divisible by g ,else
c/g will be fraction which might be wrong. So c should be divisible by g]

----
Once you have one solution you can find all other solutions using formula
x=x0+k*(b/g)  where (x0,y0) is one of the solutions
y=y0-k*(a/g)  g= gcd(a,b)

----
Q) Given LDE, find solution (x,y) such that x+y is minimum among all possible solutions.
x+y= x0+y0+ k(b-a)/g
here x0,y0,a,b,g are constants but k isn't

Case 1: if a<b ,then choose smallest k possible
Case 2: if a>b, then choose biggest k possible
Case 3: if a=b, solution is always 0 irrespective of k's value

bool find_any_solution(int a,int b, int c, int & x, int & y){
   int x0,y0;
   int g= gcd(abs(a),abs(b),x0,y0); //find positive nos

   if(c%g){
      return false;
   }
   x=x0*x/g;
   y=y0*c/g;
   if(a<0) x=-x;
   if(b<0) y=-y;
   return true;
}

int main(){
   int t,a,b,c,x,y;
   cin>>t;
   while(t--){
      cin>>a>>b>>c;
      if(find_any_solution(a,b,c,x,y)==false){
         cout<<"No solution exists...";
      }
      else{
         cout<<"x= "<<x<<" ,y= "<<y<<endl;
      }
   }

}


*/
//https://www.spoj.com/problems/CEQU/#
#include<bits/stdc++.h>
using namespace std;

int main(){

   int q,a,b,c;
   cin>>q;
   for(int i=1;i<=q;i++){
      cin>>a>>b>>c;
      int g= __gcd(a,b);
      if(c%g) cout<<"Case "<<i<<": No"<<'\n';
      else cout<<"Case "<<i<<": Yes"<<'\n';
   }
   return 0;
}

// Get AC in one go

/*

int main(){
   int t;
    scanf("%d", &t);
    LL a, b, ans;
    while (t--)
    {
        scanf("%lld %lld", &a, &b);
         //chicken mcnugget theorem: the max value that cannot be written in form am+bn for integers a,b
         // is m*n-m-n (m,n should be coprime)
        if (__gcd(a, b) == 1)
            ans = a*b - a - b + 1;
        else
            ans = -1;
        printf("%lld\n", ans);
    }

  
   return 0;
}
*/