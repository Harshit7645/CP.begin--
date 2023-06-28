#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
#define COUNT 10
int M=1e9+7;
vector<vector<ll>> nodes;
vector<ll> vis;
void dfs(ll u,ll p, vector<ll>& vis){
    for(ll v : nodes[u])
    {
        if(v!= p){
            dfs(v, u, vis);
            vis[u] += vis[v];
        }
    }
    if (vis[u]==0)
    vis[u]=1;
}
int main()
{
    ll tt=1;
    cin>>tt;
    while(tt--)
    {
        ll n;
        cin>>n;
        vector<pair<ll,ll>>v;
        map<ll,ll>flag;
        nodes.clear();
        vis.clear();
        nodes.resize(n);
        vis.resize(n);
        rep(i,0,n-1)
        {
            ll u, v;
            cin>>u>>v;
            nodes[u-1].push_back(v-1);
            nodes[v-1].push_back(u-1);
        }
        dfs(0,-1,vis);
        ll q;
        cin>>q;
        while(q--)
        {
            ll u, v;
            cin>>u>>v;
            u--;
            v--;
            ll ans=vis[u]*vis[v];
            cout<<ans<<endl;
        }
    }
}   