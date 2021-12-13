#include<iostream>
using namespace std;
int main(){
    //1
    /*int row;
    cin>>row;
    for(int i=1;i<=row;i++){
        for(int j=1;j<=(row+1-i);j++){
            cout<<j;
        }
        cout<<endl;
    }*/

    //2
   /* int row;
    cin>>row;
    for(int i=1;i<=row;i++){
        for(int j=1;j<=i;j++){
            if((i+j)%2==0){
            cout<<'1';
            }
            else{
                cout<<'0';
            }
        }
        cout<<endl;
    }*/

    //3
  /*  int row;
    cin>>row;
    for(int i=1;i<=row;i++){
        for(int j=1;j<=(row-i);j++){
            cout<<' ';
        }
        for(int j=1;j<=row;j++){
            cout<<'*';
        }
        cout<<endl;
    }*/

    //4
   /* int row;
    cin>>row;
    for(int i=1;i<=row;i++){
        for (int j=1;j<=(row-i);j++){
            cout<<' ';
        }
        for(int j=1;j<=i;j++){
            cout<<j<<' ';
        }
        cout<<endl;
    }*/

    //5
   /* int row,count;
    cin>>row;
    for(int i=1;i<=row;i++){
            int count=i;
        for(int j=1;j<=row-i;j++){
            cout<<' ';
        }
        for(int j=1,count=i;j<=i;j++){
            cout<<count--;
        }
        for(int j=1,count=2;j<=(i-1);j++){
            cout<<count++;
        }
        cout<<endl;
    }*/

    //6
    /*int row;
    cin>>row;
    for(int i=1;i<=row;i++){
        for(int j=1;j<=row-i;j++){
            cout<<' ';
        }
        for(int j=1;j<=2*i-1;j++){
            cout<<'*';
        }
        cout<<endl;
    }
      for(int i=row;i>=1;i--){
        for(int j=1;j<=row-i;j++){
            cout<<' ';
        }
        for(int j=1;j<=2*i-1;j++){
            cout<<'*';
        }
        cout<<endl;
    }*/

    //7
    //Important
   /* int n;
    cin>>n;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=n;j++){
            if(((i+j)%4)==0 || (i==2 && j%4==0)){
                cout<<'*';
            }
            else{
                cout<<' ';
            }
        }
        cout<<endl;
            
    }*/

    return 0;
}