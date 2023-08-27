#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int M=1e9+7;

bool good(vector<ll>arr,double x,ll k)
{
    long double loss=0,gain=0;
    rep(i,0,arr.size())
    {
        if(arr[i]<x)
        gain+=(x-arr[i]);
        else
        loss+=(arr[i]-x);
    }
    if(loss-loss*k/100>=gain)
    return 1;
    return 0;
}
int main()
{
    ll n,k;
    cin>>n>>k;
    vector<ll>arr(n);
    ll sum=0;
    rep(i,0,n)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    long double l=0,r=sum;
    auto e=pow(10,-10);
    rep(i,0,100)
    {
        double mid=l+(r-l)/2;
        if(good(arr,mid,k))
        l=mid+e;
        else
        r=mid+e;   
    }
    cout<<setprecision(10)<<l<<"\n";
}   