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
        ll n,m,t1=0,t2=0;
        cin>>n>>m;
        vector<ll>right(n+1,n);
        rep(i,0,m)
        {
            ll x,y;
            cin>>x>>y;
            ll temp=x;
            x=min(x,y);
            y=max(temp,y);
            right[x]=min(y-1,right[x]);
        }
        right[0]=0;
        ll ans=0;
        repr(i,n-1,1)
        {
            right[i]=min(right[i],right[i+1]);
        }
        rep(i,1,n+1)
        {
            //R=min(R,right[i]);
            ans+=right[i]-i+1;
        }
        cout<<ans<<endl;
    }    
}