/*
Identification: Given a string/array.We have to consider 2 indices i,j (i mostly towards left and j towards right)
The elements between i,j are broken into subparts, Say there are 4 numbers between i,j, so we group these 
4 elements into parts:-(1,3),(2,2),(3,1). Then these parts return an ans and then all these temp ans from 
each subpart eventually gives us the final ans.

int solve(int arr[],int i,int j){
    if(i>j) return 0; //this may be different from quest to quest

    for(int k=i;k<j;k++){ //this may be different from quest to quest
        //calculate temp ans
        tempans=solve(arr,i,k) +/* solve(arr,k+1,j)
        ans=max/min/sub/add,etc of tempans;
    }
    return ans;
}

Steps:
1) Find values of i,j (near left and right ends respectively )
2) Find Base condition by considering the smallest valid input or first invalid input
3) Move k from i to j
4) Calculate tempAns and from it find final ans
*/