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
        ll ans=1;
        ll f=0;
        rep(i,0,n)
        {
            if(arr[i]==1)
            {
                f=1;
                break;
            }
        }
        if(f)
        {
            cout<<"0\n";
            continue;
        }
        repr(i,n-1,0)
        {
            if(gcd(arr[i],i+1)==1)
            {
                ans=i+1;
                break;
            }
        }
        cout<<n-ans+1<<"\n";
    } 
}