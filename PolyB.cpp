#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m,k;
        cin>>n>>m>>k;
        ll a[m],mx=0;
        rep(i,0,m)
        {
            cin>>a[i];
            mx=max(mx,a[i]);
        }
        if(m<k)
        {
            PNO;
            continue;
        }
        sort(a,a+m);
        rep(i,0,n%k)
        {
            a[m-i-1]--;
        }
        mx=0;
        rep(i,0,m)
        {
            mx=max(mx,a[i]);
        }
        if(mx>(n/k))
        PNO;
        else
        PYES;
    }
}