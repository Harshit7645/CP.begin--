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
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,q;
        cin>>n>>q;
        vector<ll>h,w;
        ll hs=0,ws=0,hb=0,wb=0;
        vector<ll>areas;
        ll sum=0,i,j;
        rep(i,0,n)
        {
            ll x;
            cin>>x;
            h.push_back(x);
            cin>>x;
            w.push_back(x);
            sum+=h[i]*w[i];
            areas.push_back(h[i]*w[i]);
        }
        // for(auto x:h)
        // cout<<x<<" ";
        rep(i,0,q)
        {
            cin>>hs>>ws>>hb>>wb;
            ll ans=0;
            auto it1=lower_bound(h.begin(),h.end(),hs);
            auto it2=lower_bound(w.begin(),w.end(),ws);
            auto it3=upper_bound(h.begin(),h.end(),hb);
            auto it4=upper_bound(w.begin(),w.end(),wb);
            for(j=*it1;j<=max(hb,wb);j++)
            {
                if(h[j]>hb || h[j]>wb)
                break;
                else
                ans+=h[j]*w[j];
            }
            cout<<ans<<"\n";
        }
        //cout<<endl;
    }
}