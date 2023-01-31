#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
ll fact(ll n)
{
    ll ans=1;
    rep(i,1,n+1)
    {
        ans*=i;
    }
    return ans;
}
ll nCr(ll n,ll r)
{
    return (fact(n)/((fact(r))*(fact(n-r))));
}
ll power(ll a,ll b)
{
    ll result=1;
    while(b>0)
    {
        if(b%2==1)
        result*=a;
        a*=a;
        b/=2;
    }
    return result;
}
bool isPrime(ll n)
{
    if(n<=1)
    return false;
    if(n<=3)
    return true;

    if(n%2==0 || n%3==0 || n%5==0)
    return false;
    for(ll i=6;i<=sqrt(n);i+=5)
    {
        //for (ll i=5;i*i<=n;i+=6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;//return true;
    }
    return true;
}
int Partition(int arr[],int l,int r);
void quickSort(int arr[],int l ,int r)
{
    if(l<r){
    int pi=Partition(arr,l,r);
    quickSort(arr,l,pi-1);
    quickSort(arr,pi+1,r);
    }
}
int Partition(int arr[],int l,int r)
{
    int pivot=arr[r];
    int i=l-1;
    rep(j,l,r)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
        //swap(arr[i],arr[l]);
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin>>n;
    int arr[n];
    rep(i,0,n)
    {
        cin>>arr[i];
    }
    quickSort(arr,0,n-1);
    rep(i,0,n)
    cout<<arr[i]<<" ";
    cout<<"\n";
}