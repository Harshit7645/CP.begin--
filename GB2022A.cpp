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
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        ll a[n],b[m];
        rep(i,0,n)
        {
            cin>>a[i];
        }
        rep(i,0,m)
        {
            cin>>b[i];
        }
        priority_queue<ll> req;
        priority_queue<ll,vector<ll>,greater<ll>> rigid;
        ll ans=0;
        rep(i,0,n)
        {
            rigid.push(a[i]);
        }
        rep(i,0,m)
        {
            rigid.pop();
            rigid.push(b[i]);
        }
        while(!rigid.empty())
        {
            ans+=rigid.top();
            rigid.pop();
        }
        cout<<ans<<endl;
        // rep(i,0,n)
       // cout<<a[i]<<" ";
    }
}