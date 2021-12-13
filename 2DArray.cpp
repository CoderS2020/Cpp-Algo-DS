//Self made
#include<iostream>
using namespace std;

/*int main(){
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int row_start=0,col_start=0,row_end=n-1,col_end=m-1;

    while(row_start<=row_end && col_start<=col_end){
    for(int i=col_start,j=row_start;i<=col_end;i++){
        cout<<arr[j][i]<<" ";
    }
    
    for(int i=row_start+1, j=col_end;i<=row_end;i++){
         cout<<arr[i][j]<<" ";
    }
    
    for(int i=col_end-1, j=row_end;i>=col_start;i--){
            cout<<arr[j][i]<<" ";
    }

    for(int i=row_end-1, j=col_start;i>row_start;i--){
            cout<<arr[i][j]<<" ";
    }

    row_start++,col_start++,row_end--,col_end--;
    }
    return 0;
}*/

//Transpose without creating a new matrix
/*int main(){
    int n;
    cin>>n;
    int arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
        cin>>arr[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int temp=arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=temp;
        }
    }

    
    for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
            }cout<<endl;
        }

    return 0;
}*/

//Matrix multiplication
/*int main(){
    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    int mat1[n1][n2];
    int mat2[n2][n3];
    int res[n1][n3];
    cout<<"First Matrix"<<endl;
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
        cin>>mat1[i][j];
        }
    }
    cout<<endl<<"Second matrix"<<endl;
    for(int i=0;i<n2;i++){
            for(int j=0;j<n3;j++){
            cin>>mat2[i][j];
        }
    }

    for(int i=0;i<n1;i++){
            for(int j=0;j<n3;j++){
            res[i][j]=0;
        }
    }
    for(int i=0;i<n1;i++){
        for(int j=0;j<n3;j++){
            for(int k=0;k<n2;k++){
                res[i][j]+=mat1[i][k]*mat2[k][j];
            }
        }
    }
    cout<<endl<<"Resultant matrix"<<endl;
    for(int i=0;i<n1;i++){
            for(int j=0;j<n3;j++){
            cout<<res[i][j]<<" ";
        }cout<<endl;
    }

    return 0;
}*/

//To check if a given value exists in a matrix or not(naive approach if it is not in ascending order)
/*int main(){
    int n;
    cin>>n;
    int target;
    cin>>target;
    int arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }cout<<endl;
    int check=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==target){
                check=1;
            }
        }
    }
    if(check=1){
        cout<<"The element is present"<<endl;
    }
    else{
        cout<<"The element is not present"<<endl;
    }

    return 0;
}*/

//To check if a given value exists in a matrix or not (if it is ascending order)
