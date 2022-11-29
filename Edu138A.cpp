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
        vector<ll>r,c;
        rep(i,0,m)
        {
            ll x,y;
            cin>>x>>y;
            r.push_back(x);
            c.push_back(y);
        }
        if(m<n)
        {
            PYES;
            continue;
        }
        else
        {
            if(m==n){
            PNO;
            continue;
            }
        }
    } 
}