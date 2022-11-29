#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=b;i>=a;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
typedef vector<ll> vll;
bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n],b[n];
        ll ma=0,mb=0;
        vector<pair<ll,ll>>v;
        rep(i,0,n)
        {
            cin>>a[i]>>b[i];
            if(a[i]>b[i])
            v.push_back({b[i],a[i]});
            else
            v.push_back({a[i],b[i]});
        }
        ll ans=0;
        sort(v.begin(),v.end(),sortbysec);
        rep(i,0,n)
        {
            ans+=(2*v[i].first);
        }
        rep(i,0,n-1)
        {
            ans+=abs(v[i].second-v[i+1].second);
        }
        if(n>=2){
            //cout<<ans<<endl;
        ans+=abs(v[0].second);
        ans+=abs(v[n-1].second);       
        cout<<ans<<endl;
        }
        else
        cout<<ans+2*v[0].second<<endl;

    }
}