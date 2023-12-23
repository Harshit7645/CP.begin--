#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int M=1e9+7;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll tt=1;
    cin>>tt;
    while(tt--)
    {
        ll n;
        cin>>n;
        vector<ll>l(n),c(n);
        vector<ll>req;
        multiset<ll>r;
        rep(i,0,n)
        {
            cin>>l[i];
        }
        rep(i,0,n)
        {
            ll temp;
            cin>>temp;
            r.insert(temp);
        }
        rep(i,0,n)
        {
            cin>>c[i];
        }
        sort(l.begin(),l.end());
        sort(c.begin(),c.end());
        vector<ll>len;
        repr(i,n-1,0)
        {
            auto it=r.upper_bound(l[i]);
            len.push_back(*it-l[i]);
            r.erase(it);
        }
        ll ans=0;
        sort(len.begin(),len.end());
        rep(i,0,n)
        {
            ans+=len[i]*c[n-i-1];
        }
        cout<<ans<<"\n";
    }
}   