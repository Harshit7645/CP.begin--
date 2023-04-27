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
    rep(i,1,n+1)
    {
        ans*=i;
    }
    return ans;
}
ll nCr(ll n,ll r)
{
    return (fact(n)/((fact(r))*(fact(n-r))));
}
ll power(ll a,ll b)
{
    ll result=1;
    while(b>0)
    {
        if(b%2==1)
        result*=a;
        a*=a;
        b/=2;
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll tt;
    cin>>tt;
    while(tt--)
    {
        ll n,m;
        cin>>n>>m;
        ll x1,y1,x2,y2,c=0;
        cin>>x1>>y1>>x2>>y2;
        if((x1==1 && y1==1)||(x1==1 && y1==m)||(x1==n && y1==1)||(x1==n && y1==m))
        cout<<"2\n";
        else if((x2==1 && y2==1)||(x2==1 && y2==m)||(x2==n && y2==1)||(x2==n && y2==m))
        cout<<"2\n";
        else if(x1==1 || y1==1 || x2==1 || y2==1 || x2==n || y2==m || x1==n || y1==m)
        cout<<"3\n";
        else
        cout<<"4\n";
    }
}   