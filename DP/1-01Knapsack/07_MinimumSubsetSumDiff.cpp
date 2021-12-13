/*
Array is given, divide into 2 subsets such that the abs diff between those 2 subsets is minimum

If one is s1 then other automatically becomes (range - s1)
s1-s2= range-2*s1

Now we know that value of s1/s2 is restricted to only few specific values and not all.
To find those values we use subsetSum function and from this dp table in the last row we get whether
that value is permissible or not. We store that into a vector

sum-> addition of all elements
bool t[n+1][sum+1];
for(int i=0;i<n+1;i++){
    for(int j=0;j<sum+1;j++){
        if(i==0) t[i][j]=false; //if i==0 ,ie no elements then sum will always be 0

        if(j==0) t[i][j]=true; //there will always be empty subset for every set that givens sum as 0
    }
}

vector<int> subsetSum(int arr[], int sum,int n){
    vector<int> s1;
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){
                t[i][j]= t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }

  for(int j=0;j<=sum/2;j++){ //sum/2 because if you take if s1=sum/2 then s2=sum/2 and then s1-s2=0 (minimum possible-that is what we want,look question)
      if(t[n][j]==true){
          s1.push_back(j);
      }
  }
  return s1;
};

int minAns=INT_MAX;
for(int i=0;i<s1.size();i++){
    minAns=min(minAns,sum-2*s1[i]);
}
return minAns;


*/

