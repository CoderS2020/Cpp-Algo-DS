/*
Recurrence Relation: An equation that defines a sequence based on a rule that gives
the next term as a function to the previous terms

Fibonacci Nos using matrix transformations
Fibonacci series: [1,1,2,3,5,....]
we know fn=fn-1 + fn-2   ( 0,1 are base cases, rest all follow the formula)

1 1     fn-1      =     fn  
1 0     fn-2            fn-1

A =1 1  
   1 0

A^k fn      =   fn+k               [we calculate A^k using matrix multiplication in log(k) (base 2) ]
    fn-1        fn+k-1

thus
A^100    f1 =   f101    //so we got 101th ,100th fibonacci nos so quickly
         f0     f100
*/

#include<bits/stdc++.h>
using namespace std;


struct matrix{
    int mat[2][2];
};
matrix mul(matrix A, matrix B){ //both matrices should be of same size
    matrix C;
    for(int row=0;row<2;row++){
        for(int col=0;col<2;col++){
            int here=0;
            for(int i=0;i<2;i++){
                here+=A.mat[row][i]*B.mat[i][col];
            }
            C.mat[row][col]=here;
        }
    }
    return C;
};

//Making an identity matrix
matrix identity(){
    matrix A;
    A.mat[0][0]=1 , A.mat[1][1]=1;
    A.mat[0][1]=0 , A.mat[1][0]=0;
    return A;
}

//Same as recursive approach from 01_Basics.txt
matrix power(matrix a,int n){
    if(n==0){
        return identity();
    }
    matrix X=power(a,n/2);
    if(n%2==0){
        return mul(X,X);
    }
    else{
        return mul(mul(X,X),a);
    }
}


int get_nth_fibonacci(int n){
    matrix fib;
    fib.mat[0][0]=1, fib.mat[0][1]=1;
    fib.mat[1][0]=1, fib.mat[1][1]=0;
    return power(fib,n).mat[0][0];
}

int main(){
    cout<<get_nth_fibonacci(1);
    

   return 0;
}