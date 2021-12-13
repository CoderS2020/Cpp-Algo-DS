// https://codeforces.com/contest/546/problem/D
#include<bits/stdc++.h>
using namespace std;
int a[5000005];
int main()
{
	int i,j,t,r,l,k;
	for(i=2;i<=5000000;i++)
	{
		if(!a[i])
		{
			for(j=1;j*i<=5000000;j++)
			{
				for(k=j*i;k%i==0;k/=i)
				a[i*j]++;
			}
		}
		a[i]+=a[i-1];
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&r,&l);
		printf("%d\n",a[r]-a[l]);
	}
}