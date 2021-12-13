//Allocation of Minimum Pages
/*#include<bits/stdc++.h>
using namespace std;

bool checkAllocation(int arr[],int mid,int m,int n){
    int students=1;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];

        if(sum>mid){
            students++;
            sum=arr[i];
        }

        if(students>m){
            return false;
        }
    }
    return true;



}

int main(){

    //Allocate minimum number of pages (Here array may or may not be sorted, dont sort it since then continuity will be lost)
    int m,n;
    cin>>m>>n;
    if(n<m){
        cout<<"-1"; return 0;
    }
    int c[n]={0};
    int sum=0,maxelem=-1;

    for(int i=0;i<n;i++){
        cin>>c[i];
        sum+=c[i];
        maxelem=max(maxelem,c[i]);

    }

    int start=maxelem,end=sum;
    int res=INT_MAX;
    while(start<=end){
        int mid=start+(end-start)/2;

        if(checkAllocation(c,mid,m,n)){
            res=min(res,mid);
            end=mid-1;

        }
        else{
            start=mid+1;
        }



    }
    
    cout<<res<<endl;


    
    

   return 0;
}*/

//Aggressive Cows
/*
#include<bits/stdc++.h>
using namespace std;


bool checkPosition(int mid,int arr[],int n,int c){
    
    int cows=1; int prev=arr[0];

    for(int i=1;i<n;i++){
        if(arr[i]-prev>=mid){
            cows++;
            prev=arr[i];
        }
        if(cows==c) return true;
    }
    return false;


}

int main(){

    int t;
    cin>>t;
    while(t--){
        int n,c;
        cin>>n>>c;
        int arr[n]={0};
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);

        int low=0,high=1e9;
        int res=0;
        while(low<=high){
            int mid=low+(high-low)/2;

            if(checkPosition(mid,arr,n,c)){
                low=mid+1;
                res=mid;
            }
            else{
                high=mid-1;
            }
        }
        cout<<res;
    }


   return 0;
}*/

//Painter's problem
/*
bool check(int arr[],int mid,int a,int n){
    int painters=1;int sum=arr[0];
    for(int i=1;i<n;i++){
        sum+=arr[i];
        if(sum>mid){
            painters++;
            sum=arr[i];
        }
        if(painters>a) return false;
    }
    return true;
}

#include<bits/stdc++.h>
using namespace std;

int main(){

    int a,b,n;
    cin>>a>>b>>n;
    int arr[n]={0};
    int sum=0,maxelem=0;
    for(int i=0;i<n;i++){
         cin>>arr[i];
         sum+=arr[i];
         maxelem=max(maxelem,arr[i]);
    }

    int start=maxelem,end=sum;
    int res=0;
    while(start<=end){
        int mid=start+(end-start)/2;

        if(check(arr,mid,a,n)){
            end=mid-1;
            res=mid;
        }
        else{
            start=mid+1;
        }
    }

    // cout<<res<<endl;
    
    //Here multiply by b to get total time
    cout<<(res*b)<<endl;




   return 0;
}
*/

//Codeforces Valhalla Siege
/*
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    int n,q;
    cin>>n>>q;
    vector<int> power;
    vector<int> arrows;

    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        power.push_back(temp);
    }

    
    for(int i=0;i<q;i++){
        int temp;
        cin>>temp;
        arrows.push_back(temp);
    }

    vector<int> sumPower(power.size());

   partial_sum(power.begin(),power.end(),sumPower.begin()); //Prefix array

   ll d=0;

   for(auto arrow:arrows){

       d+=arrow;
       if(d>=sumPower.back()) d=0;

       auto it=upper_bound(sumPower.begin(),sumPower.end(),d);

       cout<<distance(it,sumPower.end())<<endl;
   }

   return 0;
}*/

//Destroy Asteroids Codechef
/*
#include<bits/stdc++.h>
using namespace std;
#define ll long long 

bool checkMin(ll mid,ll arr[],ll n,ll k){
    ll sum=0;

    for(ll i=0;i<n;i++){
        if(arr[i]>=mid){
            sum+=mid;
        }
        else{
            sum+=arr[i];
        }
    }

    if((sum/mid)>=k){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    ll n,k;
    cin>>n>>k;
    ll arr[n]={0};
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }

    ll start=0, end=1e18;
    ll mid,ans;
    
    while(start<=end){
        mid=start+(end-start)/2;
        if(checkMin(mid,arr,n,k)){
            start=mid+1;
            ans=mid;
        }
        else{
            end=mid-1;
        }
    }

    cout<<ans<<endl;

    return 0;
}

*/
//812-C Codeforces (Sagheer and Nubian Market)
/*
#include<bits/stdc++.h>
int a[100005],b[100005],n,s,i,k;
auto check(int k){
	for(i=0;i<n;++i)
    {
        b[i]=a[i]+i*k+k;
    }
	std::sort(b,b+n);

	long long r=0;
    
	for(i=0;i<k;++i)
    {
        r+=b[i];
    }
	return r;
}
int main(){
	scanf("%d%d",&n,&s);
	for(i=0;i<n;++i)scanf("%d",a+i);
	for(k=1;k<=n;++k)if(check(k)>s)break;
	printf("%d %lld ",k-1,check(k-1));
}*/

//Prata and Roti -SPOJ
/*#include <bits/stdc++.h>
using namespace std;

bool check(int mid, int arr[], int l, int p)
{
    int paratha = 0;
    for (int i = 0; i < l; i++)
    {
        int sumP = arr[i];
        int k = 2;
        while (sumP <= mid)
        {
            paratha++;
            sumP = sumP + arr[i] * (k);
            k++;
        }

        if (paratha >= p)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {

        int p, l,res=0;
        cin >> p >> l;
        int arr[l]={0};
        for (int i = 0; i < l; i++)
        {
            cin >> arr[i];
        }
        int start = 0, end = 1e8;
    
        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (check(mid, arr, l, p))
            {
                res=mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        cout<<res<<endl;
    }

    return 0;
}*/


//EKO -SPOJ
/*
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool check(ll mid,ll arr[],ll n,ll m){
    ll cutWood=0;
    for(ll i=0;i<n;i++){
        if(arr[i]-mid>0){
            cutWood+=arr[i]-mid;
        }
        if(cutWood>=m) return true;
    }
    
    return false;
}

int main(){
    ll n,m;
    cin>>n>>m;
    ll arr[n]={0};
    for(ll i=0;i<n;i++)cin>>arr[i];

    ll start=0,end=1e18,res;

    while(start<=end){
        ll mid=start+(end-start)/2;

        if(check(mid,arr,n,m)){
            res=mid;
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    cout<<res<<endl;
   return 0;
}*/


