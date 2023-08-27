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

int main()
{
    ll n,p,q;
    cin>>n>>p>>q;
    ll ans=INT_MAX;
    rep(i,0,n)
    {
        ll x;
        cin>>x;
        ans=min(ans,x);
    }
    cout<<min(p,q+ans)<<"\n";
}   