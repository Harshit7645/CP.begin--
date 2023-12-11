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

ll power(ll a,ll b)
{
    ll result=1;
    while(b>0)
    {
        if(b%2==1)
        result*=a;
        a*=a;
        b/=2;
    }
    return result;
}

int find(vector<int>&parent,int node)
{
    if(parent[node]==-1)
    return node;
    return find(parent,parent[node]);
}

void Union(int u,int v,vector<int>&parent)
{
    int pu=find(parent,u);
    int pv=find(parent,v);
    parent[pu]=pv;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll tt=1;
    cin>>tt;
    while(tt--)
    {
        ll n,s;
        cin>>n>>s;
        vector<pair<ll,ll>>v(n);
        rep(i,0,n-1)
        {
            ll x,y,wt;
            cin>>x>>y>>wt;
            v[x-1]={wt,y-1};
            v[y-1]={wt,x-1};    
        }
        sort(v.begin(),v.end());
        rep(i,0,n)
        {
            cout<<
        }
    }
}   