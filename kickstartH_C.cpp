#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;

void dfs(ll i,ll p,vector<vector<ll>>&adjacent,vector<ll>&v,set<ll>&s){
    if(s.find(i)!=s.end())
    return;
    if(v[i]>=p)
    return;
    s.insert(i);
    for(auto x:adjacent[i]){
        if(v[x]<p)
            dfs(x,v[i],adjacent,v,s);
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t,x;
    cin>>t;
    for(x=1;x<=t;x++)
    {
        cout<<"Case #"<<x<<": ";
        ll n;
        cin>>n;
        vector<ll>v(n+1);
        rep(i,1,n+1)
            cin>>v[i];
        vector<vector<ll>>adjacent(n+1);
        ll x,y;
        rep(i,0,n-1){
            cin>>x>>y;
            adjacent[y].push_back(x);
            adjacent[x].push_back(y);
        }
        set<ll>visits;
        ll req;
        req=0;
        rep(i,1,n+1)
        {
            ll dsj;
            dfs(i,INT_MAX,adjacent,v,visits);
            dsj=i;
            ll temp=visits.size();
            req=max(req,temp);
            visits.clear();
        }
        cout<<req<<endl;
    }
}