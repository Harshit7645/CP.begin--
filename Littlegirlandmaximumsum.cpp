#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
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
    ll n,q;
    cin>>n>>q;
    map<ll,ll>m;
    ll arr[n],art[n];
    rep(i,0,n)
    {
        cin>>arr[i];
        art[i]=arr[i];
    }
    vector<pair<ll,ll>>v,greatest;
    rep(i,0,q)
    {
        ll x,y;
        cin>>x>>y;
        v.push_back({x,y});
        m[x]++;
        m[y]++;
    }
    rep(i,1,n)
    {
        if(m[i])
        continue;
        else
        m[i]=0;
    }
    for(auto x:m)
    {
        greatest.push_back({x.first,x.second});
    }
    sort(greatest.begin(),greatest.end(),sortbysec);
    reverse(greatest.begin(),greatest.end());
    // for(auto x:greatest)
    // {
    //     cout<<x.first<<" "<<x.second<<"\n";
    // }
    sort(art,art+n);
    ll c=0;
    rep(i,0,n)
    {
        arr[greatest[i].first-1]=art[n-i-1];
    }
    ll suffsum[n],s=0;
    rep(i,0,n)
    {
        s+=arr[i];
        suffsum[i]=s;
    }
    ll ans=0;
    rep(i,0,q)
    {
        ans+=abs(suffsum[v[i].first-1]-suffsum[v[i].second-1])+arr[v[i].first-1];
        //cout<<ans<<" ";
    }
    // rep(i,0,n)
    // {
    //     cout<<suffsum[i]<<" ";
    // }
    cout<<ans<<"\n";
}