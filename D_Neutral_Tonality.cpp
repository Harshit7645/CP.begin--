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

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll tt=1;
    cin>>tt;
    while(tt--)
    {
        ll n,m;
        cin>>n>>m;
        vector<ll>a(n),b(m);
        rep(i,0,n)
        {
            cin>>a[i];
        }
        rep(i,0,m)
        {
            cin>>b[i];
        }
        sort(all(b));
        reverse(all(b));
        ll j=0;
        rep(i,0,n)
        {
            while(j<m && b[j]>=a[i])
                cout<<b[j++]<<" ";
            cout<<a[i]<<" ";
        }
        while(j<m)
        {
            cout<<b[j++]<<" ";
        }
        cout<<"\n";
    }
}   