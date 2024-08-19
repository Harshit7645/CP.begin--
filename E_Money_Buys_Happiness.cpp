#include<iostream>
#include<vector>
#include<map>
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
        ll m,p;
        cin>>m>>p;
        ll h[m],c[m];
        rep(i,0,m)
        {
            cin>>c[i]>>h[i];
        }
        vector<ll>dp(1);
        dp[0]=0;//happiness ->cost
        ll sum=0;
        rep(i,0,m)
        {
            sum+=h[i];
            dp.resize(sum+1,-1);
            repr(j,sum,h[i])
            {
                if(dp[j-h[i]]>=c[i])
                dp[j]=max(dp[j],dp[j-h[i]]-c[i]);
            }   
            rep(j,0,sum+1)
            {
                if(dp[j]>=0)
                dp[j]+=p;
            }
        }
        ll ans=0;
        rep(i,0,dp.size())
        {
            if(dp[i]>=0)
            ans= max(ans, i);
        }
        cout<<ans<<endl;
    }   
}   