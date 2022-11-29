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
    ll t,x;
    cin>>t;
    for(x=1;x<=t;x++)
    {
        cout<<"Case #"<<x<<": ";
        ll m,n,p,i;
        cin>>n>>m>>p;
        ll s[n][m];
        vector<ll>mx(m,0);
        rep(i,0,n)
        {
            rep(j,0,m)
            {
                cin>>s[i][j];
            }
        }
        rep(j,0,m)
        {
            ll maxi=0;
            rep(i,0,n)
            {
                maxi=max(maxi,s[i][j]);
            }
            mx[j]=maxi;
        }
        // for(auto x:mx)
        // cout<<x<<" ";
        ll ans=0;
        for(i=0;i<m;i++)
        {
            if(s[p-1][i]<mx[i])
            ans+=abs(mx[i]-s[p-1][i]);
            //cout<<ans<<endl;
        }
        cout<<ans<<endl;
    } 
}