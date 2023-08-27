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

int helper(ll a,ll b)
{
    if(a==0)
    return 0;
    else if(b==0)
    return 1;
    if(a<b)
    return (1+helper(b,b-a))%3;
    else
    {
        if(a>2*b)
        return helper(a%(2*b),b);
        else
        return (helper(b,abs(a-b))+1)%3;
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll tt=1;
    cin>>tt;
    while(tt--)
    {
        ll n;
        cin>>n;
        ll a[n],b[n];
        rep(i,0,n)
        {
            cin>>a[i];
        }
        rep(i,0,n)
        {
            cin>>b[i];
        }
        vector<ll>cnt(n);
        rep(i,0,n)
        {
            ll x=a[i],y=b[i];
            if(x==0 && y==0)
            {
                cnt[i]=-1;
                continue;
            }
            else
            cnt[i]=helper(x,y);
        }
        // rep(i,0,n)
        // {
        //     cout<<cnt[i]<<" ";
        // }
        //cout<<"\n";
        rep(i,0,n)
        {
            if(cnt[i]==-1)
            continue;
            else
            cnt[i]=cnt[i]%3;
        }
        ll x=-1,f=0;
        rep(i,0,n)
        {
            if(cnt[i]==-1)
            continue;
            if(x==-1)
            x=cnt[i];
            else if(x!=cnt[i])
            {
                f=1;
                break;
            }
        }
        if(!f)
        PYES;
        else
        PNO;
    }
}   