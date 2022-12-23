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
        ll n,x;
        cin>>n>>x;
        ll a[n],b[n];
        rep(i,0,n)
        {
            cin>>a[i];
        }
        rep(i,0,n)
        {
            cin>>b[i];
        }
        ll ans=0;
        rep(i,0,n)
        {
            if(a[i]>=x)
            ans+=b[i];
        }
        cout<<ans<<endl;
    }
}