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
        ll n,k;
        cin>>n>>k;
        ll h[n],p[n],mx=0;
        rep(i,0,n)
        {
            cin>>h[i];
            mx=max(mx,h[i]);
        }
        rep(i,0,n)
        {
            cin>>p[i];
        }
        vector<pair<ll,ll>>v;
        rep(i,0,n)
        {
            v.push_back({p[i],h[i]});
        }
        sort(v.begin(),v.end());
        ll totdam=k,f=0,i=0;
        while(i<n && k>=0)
        {
            if(totdam>=v[i].second)
            {
                i++;
                continue;
            }
            else
            {
                while(totdam<v[i].second)
                {
                    totdam+=(k-v[i].first);
                    k-=v[i].first;
                    if(k<=0)
                    {
                        f=-1;
                        break;
                    }
                }
            }
            if(k==0)
            {
                f=-1;
                break;
            }
        }
        if(f!=-1 && i==n)
        PYES;
        else
        PNO;
    }
}