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
    ll n;
    cin>>n;
    ll p[n];
    map<ll,ll>m;
    rep(i,0,n)
    {
        cin>>p[i];
        m[p[i]]=i+1;
    }
    rep(i,1,n+1)
    {
        cout<<m[i]<<" ";
    }
}