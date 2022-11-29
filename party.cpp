#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(i=a;i<b;i++)
int main()
{
    ll t,x;
    cin>>t;
    rep(x,0,t)
    {
        ll n,m,i,j;
        cin>>n>>m;
        ll arr[n];
        rep(i,0,n)
        {
            cin>>arr[i];
        }
        vector<pair<ll,ll>>v;
        rep(i,0,m)
        {
            ll x,y;
            cin>>x>>y;
            v.push_back({x,y});
        }
    }
}