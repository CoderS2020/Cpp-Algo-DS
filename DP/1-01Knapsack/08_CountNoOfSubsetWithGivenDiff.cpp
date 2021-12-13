/*
Array given , find no of ways in which 2 subsets with sum s1,s2 will have s1-s2=diff (diff is given )

s1+s2= sum of all elements=s
s1+s2=s
s1-s2=diff 
2*s1=s+diff
s1=(s+diff)/2

Since s,diff is given , thus problem narrows down to finding no of subsets with given sum

int t[n+1][sum+1];
for(int i=0;i<n+1;i++){
    for(int j=0;j<sum+1;j++){
        if(i==0) t[i][j]=0;
        if(j==0) t[i][j]=1;
    }
}
sum=(s+diff)/2;
int subsetSum(int arr[], int sum,int n){
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){
                t[i][j]= t[i-1][j-arr[i-1]] + t[i-1][j];
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }

  return t[n][sum];
};




*/