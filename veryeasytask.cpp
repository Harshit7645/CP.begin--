#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
ll fact(ll n)
{
    ll ans=1;
    rep(i,1,n)
    {
        ans*=i;
    }
    return ans;
}
ll nCr(ll n,ll r)
{
    return (fact(n)/((fact (r))*(fact(n-r))));
}
bool isPrime(ll n)
{
    if(n<=1)
    return false;
    if(n<=3)
    return true;

    if(n%2==0 || n%3==0 || n%5==0)
    return false;
    for(ll i=6;i<=sqrt(n);i+=5)
    {
        //for (ll i=5;i*i<=n;i+=6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;//return true;
    }
    return true;
}
ll n;
bool good(ll t,ll x,ll y)
{
    if(t<min(x,y))
    return false;
    t-=min(x,y);
    ll a=t/x;
    ll b=t/y;
    if(a+b+1>=n)
    return true;
    else
    return false;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        ll x,y;
        cin>>n>>x>>y;
        ll l=1,r=max(x,y)*n;
        while(l+1<r)
        {
            ll m=l+(r-l)/2;
            if(good(m,x,y))
            {
                r=m;
            }
            else
            l=m;
        }
        cout<<r<<endl;
}