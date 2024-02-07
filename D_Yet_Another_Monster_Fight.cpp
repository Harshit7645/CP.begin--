#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
#define all(x) x.begin(),x.end()
int M=1e9+7;

bool good(ll x,vector<ll>&req)
{
    ll f=0;
    rep(i,0,req.size())
    {
        if(x<req[i])
        {
            //cout<<x<<" "<<req[i]<<" "<<i<<"\n";
            f=1;
            break;
        }
        x--;
    }
    if(f)
    return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll tt=1;
    //cin>>tt;
    while(tt--)
    {
        ll n;
        cin>>n;
        ll arr[n];
        rep(i,0,n)
        {
            cin>>arr[i];
        }
        ll pref[n]={0},suff[n]={0};
        rep(i,0,n)
        {
            pref[i]=arr[i]+(n-i-1);
            suff[i]=arr[i]+i;
        }
        rep(i,1,n)
        {
            pref[i]=max(pref[i-1],pref[i]);
        }
        repr(i,n-2,0)
        {
            suff[i]=max(suff[i+1],suff[i]);
        }
        ll ans=1e11    ;
        rep(i,0,n)
        {
            ll curr=arr[i];
            if(i!=0)
            curr=max(curr,pref[i-1]);
            if(i!=n-1)
            curr=max(curr,suff[i+1]);
            ans=min(ans,curr);
        }
        cout<<ans<<"\n";
    }
}   