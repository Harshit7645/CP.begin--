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
        ll a[4],mx=0,mn=10e9;
        ll maxi=0,mini=0;
        rep(i,0,4)
        {
            cin>>a[i];
            mx=max(mx,a[i]);
            mn=min(mn,a[i]);
        }
        rep(i,0,4)
        {
            if(mx==a[i])
            maxi=i;
            if(mn==a[i])
            mini=i;
        }
        if((maxi==0 && mini==3) ||(maxi==3 && mini==0) ||(maxi==1 && mini==2) ||(maxi==2 && mini==1))
        PYES;
        else 
        PNO;
        //cout<<maxi<<" "<<mini;
        // rep(i,0,4)
        // cout<<a[i]<<" ";
    }
}