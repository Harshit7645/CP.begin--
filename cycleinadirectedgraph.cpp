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
bool ok;

void dfs(vector<vector<int>>nodes,int node,vector<bool>&vis)
{   
    if(vis[node]==2)
    {
        ok=1;
        return ;
    }
    vis[node]=1;
    for(auto child:nodes[node])
    {
        if(vis[child])
        dfs(nodes,child,vis);
    }
}

int solve(int A,vector<vector<int>>B)
{
    ok = false;
    vector<vector<int>>nodes(A+1);
    int n=B.size();
    vector<bool>vis(A+1,false);
    rep(i,0,n)
    {
        nodes[B[i][0]].push_back(B[i][1]);
    }
    rep(i,1,A+1)
    {
        if(vis[A]==false)
        dfs(nodes,A,vis);
    }
    return ok;
}

int main()
{
    cout<<solve(5,{{1, 2},{2, 3}, {3, 4},{4,5}});
}   