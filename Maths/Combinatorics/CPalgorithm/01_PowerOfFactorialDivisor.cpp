//You are given two numbers n and k (k=prime). Find the largest power of k x such that n! is divisible by k^x.
/*
Let's first consider the case of prime k. The explicit expression for factorial

n!=1⋅2⋅3…(n−1)⋅n
Note that every k-th element of the product is divisible by k, i.e. adds +1 to the answer; the number of such elements is ⌊nk⌋.

Next, every k2-th element is divisible by k2, i.e. adds another +1 to the answer (the first power of k has already been counted in the previous paragraph). The number of such elements is ⌊nk2⌋.

And so on, for every i each ki-th element adds another +1 to the answer, and there are ⌊nki⌋ such elements.

The final answer is

⌊nk⌋+⌊nk2⌋+…+⌊nki⌋+…
The sum is of course finite, since only approximately the first logkn elements are not zeros. Thus, the runtime of this algorithm is O(logkn).
*/
#include<bits/stdc++.h>
using namespace std;

int fact_pow(int n,int k){
    int res=0;
    while(n){
        n=n/k;
        res+=n;
    }
    return res;
}