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
    ll s,n;
    cin>>s>>n;
    vector<pair<ll,ll>>v(n);
    rep(i,0,n)
    {
        cin>>v[i].first>>v[i].second;
    }
    sort(v.begin(),v.end());
    ll f=0;
    rep(i,0,n)
    {
        if(s-v[i].first>0)
        s+=v[i].second;
        else
        {
            f=1;
            break;
        }
    }
    if(f)
    {
        PNO;
    }
    else
    PYES;
}