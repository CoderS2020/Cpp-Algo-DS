#include<iostream>
using namespace std;
int main()
{
    //1.
    /*int row,col;
    cin>>row>>col;
    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            cout<<"*";
        }
        cout<<endl;
    }*/

    //2
  /*  int row,col;
    cin>>row>>col;
    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            if(i==1||i==row||j==1||j==col){
                cout<<"*";
            }
           
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }*/

    //3
    /* int row;
    cin>>row;
    for(int i=row;i>=1;i--){
        for(int j=1;j<=i;j++){
            cout<<"*";
            
        }
        cout<<endl;
    }*/

    //4
   /* int row;
    cin>>row;
    for(int i=1;i<=row;i++){
        for(int j=1;j<=row;j++){
            if(j<=row-i){
                cout<<" ";
            }
            else{
                cout<<"*";
            }
            
        }
        cout<<endl;
    }*/

    //5
  /*int row;
    cin>>row;
    for(int i=1;i<=row;i++){
        for(int j=1;j<=i;j++){
                cout<<i<<' ';
        }
        cout<<endl;
    }*/

    //6
  /*  int row;
    cin>>row;
    int count=1;
    for(int i=1;i<=row;i++){
        for(int j=1;j<=i;j++){
            cout<<count++<<" ";
        }
        cout<<endl;
    }*/

    //7--Butterfly pattern (important)
 /*  int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        int space=2*n-2*i;
        for(int j=1;j<=space;j++){
            cout<<" ";
        }
         for(int j=1;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }

    for(int i=n;i>=1;i--){
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        int space=2*n-2*i;
        for(int j=1;j<=space;j++){
            cout<<" ";
        }
         for(int j=1;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }*/
    return 0;
}
