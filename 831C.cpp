#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=b;i>=a;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
typedef vector<ll> vll;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll ans=0,arr[n];
        rep(i,0,n)
        cin>>arr[i];
        sort(arr,arr+n);
        ll ans1=0,ans2=0;
        ans1=2*arr[n-1]-arr[0]-arr[n-2];
        //ans2=max(ans1,2*arr[2]-arr[1]-arr[0]);
        rep(i,2,n)
        {
            ans=max(ans,2*arr[i]-arr[i-1]-arr[i-2]);
        }
        ll req=0,req1=0;
        rep(i,1,n)
        {
            ll temp=abs(arr[i]-arr[i-1])+(arr[i]-arr[0]);
            req=max(req,temp);
        }
        rep(i,0,n-1)
        {
            ll temp=abs(arr[i+1]-arr[i])+abs(arr[i]-arr[n-1]);
            req1=max(req1,temp);
        }
        ll t1=max(ans,ans1);
        ll t2=max(req,req1);
        cout<<max(t1,t2)<<"\n";
    }
}