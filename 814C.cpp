#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define PNO cout<<"No\n"
#define PYES cout<<"Yes\n"
#define vll vector<ll>;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,q,x,k;
        cin>>n>>q;
        vector<ll> v;
        map<ll,ll>m;
        rep(i,0,n)
        {
            cin>>v[i];
            m[i+1]=v[i];
        }
        cin>>x>>k;
        rep(z,0,q)
        {
            cin>>x>>k;
            ll temp;
            temp=n-m[x];
            
        }
    }
}