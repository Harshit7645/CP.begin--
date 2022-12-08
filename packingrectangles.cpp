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
    ll n,w,h;
    cin>>w>>h>>n;
    ll ans=0;
    ll l=0,r=1;
    while(1)
    {
        if((r/w)*(r/h)>=n)
        break;
        r*=2;
    }
    ans=(l+r)/2;
    while(l<r-1)
    {
        if(l==r)
        break;
        if((ans/w)*(ans/h)>=n)
        r=ans;
        else
        l=ans;
        ans=(l+r)/2;
    }
    cout<<r<<endl;
}