#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
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
        ll arr[n],s=0;
        rep(i,0,n)
        {
            cin>>arr[i];
            s+=arr[i];
        }
        sort(arr,arr+n);
        ll sum1=0,sum2=0;
        rep(i,0,n/2+1)
        {
            sum1+=arr[i];
        }
        cout<<abs(s)<<"\n";

    }
}