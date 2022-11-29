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
        ll n,m;
        cin>>n>>m;
        ll arr[n];
        ll sum=0;
        rep(i,0,n)
        {
            //sum+=arr[i];
            cin>>arr[i];
            sum+=arr[i];
        }
        if(sum-m>=0)
        cout<<sum-m<<"\n";
        else
        cout<<"0\n";
    } 
}