#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll arr[n],diff[n-1];
        rep(i,0,n)
        cin>>arr[i];
        sort(arr,arr+n);
        ll sum=0,minm=1e18;
        rep(i,1,n-1)
        {
            sum=0;
            sum+=abs(arr[i]-arr[i-1]);
            sum+=abs(arr[i+1]-arr[i]);
            minm=min(minm,sum);
        }
        cout<<minm<<"\n";
    }
}