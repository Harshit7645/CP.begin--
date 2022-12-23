#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int n,k;
vector<int>v;
bool cancut(double n)
{
    ll cnt=0;
    for(auto x:v)
    {
        cnt+=x/n;
    }
    if(cnt>=k)
    return true;
    else
    return false;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>k;
    v.resize(n);
    rep(i,0,n)
    {
        cin>>v[i];
    }
    double l=0,r=10e8;
    double m;
    rep(i,0,100)
    {
        m=l+(r-l)/2;
        if(cancut(m))
        {
            l=m;
        }
        else
        r=m;
    }
    cout<<setprecision(20)<<l;
}