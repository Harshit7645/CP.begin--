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

void dfs(ll node,vector<set<ll>>&nodes,ll parent)
{
    cout<<node<<" ";
    for(auto child:nodes[node])
    {
        if(child!=parent){
            dfs(child,nodes,node);
            cout<<node<<" ";
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll tt=1;
    //cin>>tt;
    while(tt--)
    {
        ll n;
        cin>>n;
        vector<set<ll>>nodes(n+1);
        rep(i,0,n-1)
        {
            ll x,y;
            cin>>x>>y;
            nodes[x].insert(y);
            nodes[y].insert(x);
        }
        dfs(1,nodes,0);
        return 0;
    }
}   