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
    ll n,m;
    cin>>n>>m;
    map<ll,ll>end;
    vector<set<int>>nodes(n+1);
    rep(i,0,m)
    {
        ll x,y;
        cin>>x>>y;
        if(x==0)
        end[y]++;
        else
        {
            nodes[x].insert(y);
            nodes[y].insert(x);
        }
    }
    rep(i,1,n+1)
    {
        for(auto x:end)
        {
            nodes[i].insert(x.first);
            nodes[x.first].insert(i);
        }
    }
}   