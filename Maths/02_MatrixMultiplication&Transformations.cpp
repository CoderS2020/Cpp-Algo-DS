// Matrix Multiplication and Matrix Exponentiation
// Treat matrix as a number and apply the same logic as power finding
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


/*
Transformations
first pt(x,y)-> second pt(x+y,2y-x) [second no is added to first no, 2*second no - first no]-->....
What will be the 100th transformation?

we can write above first transformation in the form of matrices:
 1 1    x  =  x+y  
-1 2    y     2y-x  
ie.
A   x = x+y
    y   2y-x

for nth transformation
A^n x = nth transformation matrix/co-ordinates
    y

So we can use matrix multiplication to find A^n and then multiply with  x to get the answer(nth transformation)
                                                                        y
Time complexity = O(logn) (base 2)
*/  