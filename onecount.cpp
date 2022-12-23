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
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    map<char,vector<ll>>m;
    rep(i,0,n)
    {
        m[s[i]].push_back(i);
    }
    ll x[n];
    char c[n];
    rep(i,0,q)
    {
        cin>>x[i];
    }
    rep(i,0,q)
    {
        cin>>c[i];
    }
    ll axis=0;
    char ch='\0';
    rep(i,0,q)
    {
        ll ans=0;
        axis=x[i];
        ch=c[i];
        rep(j,0,m[ch].size())
        {
            if(m[ch][j]<axis-1)
            ans+=j+1;
            else if(m[ch][j]>n-axis)
            ans+=(n-j);
            else
            ans+=axis;
        }
        cout<<ans<<" ";
    }
}