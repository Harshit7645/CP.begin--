#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int M=1e9+7;
bool comp(pair<ll,ll>p1,pair<ll,ll>p2)
{
    if(p1.first*p2.second==p1.second*p2.first)
    return p1.first<p2.first;
    else
    return p1.first*p2.second<p1.second*p2.first;
}
int main()
{
    ll n;
    cin>>n;
    vector<ll>a(n),b(n);
    vector<ll>perm;
    rep(i,0,n)
    {
        cin>>a[i]>>b[i];
        perm.push_back(i);
    }
    auto comp=[&](ll i,ll j)
    {
        ll x=a[i]*(a[j]+b[j]);
        ll y=a[j]*(a[i]+b[i]);
        if(x!=y)
        return x>y;
        return i<j;
    };
    sort(perm.begin(),perm.end(),comp);
    rep(i,0,n)
    cout<<perm[i]+1<<" ";
}   