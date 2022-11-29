#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
ll fact(ll n)
{
    ll f=1;
    rep(i,1,n+1)
    {
        f*=i;
    }
    return f;
}
ll nCr(ll n,ll i)
{
    ll ans;
    ans=fact(n)/(fact(i)*fact(n-i));
    return ans;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll M=1000000007;
    ll n,k;
    cin>>n>>k;
    ll x=pow(2,n);
    if(k>=n)
    cout<<x%M<<endl;
    else
    {
        ll ans=1;
        rep(i,0,min(n,k))
        {
            ans+=nCr(n,k)%M;
        }
        cout<<ans%M<<"\n";
    }
}