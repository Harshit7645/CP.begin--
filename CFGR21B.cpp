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
        ll arr[n];
        rep(i,0,n)
        cin>>arr[i];
        ll ans=0;
        // if(arr[0]==0)
        // ans=-1;
        ll req=0;
        rep(i,0,n)
        {
            if(arr[i]==0)
            req++;
        }
        if(req==0)
        {
            cout<<"1\n";
            continue;
        }
        if(req==n)
        {
            cout<<"0\n";
            continue;
        }
        ll l=0,r=n-1;
        while(arr[l]==0 && l<n)
        {
            l++;
        }
        while(arr[r]==0 && r>=0)
        {
            r--;
        }
        ll f=0;
        rep(i,l,r+1)
        {
            if(arr[i]==0)
            {
                f=1;
                break;
            }
        }
        if(f==1)
        {
            cout<<"2\n";
        }
        else
        cout<<"1\n";
    } 
}