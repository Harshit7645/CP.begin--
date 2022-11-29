#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
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
        ll n,q;
        cin>>n>>q;
        ll a[n],k[q],height[n],sum=0;
        ll maxht[n];
        rep(i,0,n)
        {
            cin>>a[i];
            sum+=a[i];
            height[i]=sum;
        }   
        ll mx=0;
        rep(i,0,n)
        {
            mx=max(mx,a[i]);
            maxht[i]=mx;
        }
        // for(auto x:maxht)
        // cout<<x.first<<" "<<x.second<<"\n";
        rep(i,0,q)
        {
            cin>>k[i];
            ll f=0;
            if(upper_bound(maxht,maxht+n,k[i])-maxht-1>=0)
            cout<<height[upper_bound(maxht,maxht+n,k[i])-maxht-1]<<" ";
            else
            cout<<"0 ";
        }
        cout<<"\n";
    } 
}