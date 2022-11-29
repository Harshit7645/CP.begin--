#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=b;i>=a;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
typedef vector<ll> vll;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        ll n,q;
        cin>>n>>q;
        ll p[n];
        rep(i,0,n)
        cin>>p[i];
        sort(p,p+n);
        ll sums[n],tsum=0;
        rep(i,0,n)
        {
            tsum+=p[i];
            sums[i]=tsum;
        }
        rep(i,0,q)
        {
            ll x,y;
            cin>>x>>y;
            if(x==n)
            {
                cout<<sums[y-1]<<endl;
                continue;
            }
            cout<<sums[n-x+y-1]-sums[n-x-1]<<endl;
        }
}