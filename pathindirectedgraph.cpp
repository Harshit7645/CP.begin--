#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;

void dfs(int u,vector<vector<int>>&nodes,vector<bool>&vis)
{
    if(vis[u]==1)
    return ;
    vis[u]=true;
    rep(i,0,nodes[u].size())
    {
        dfs(nodes[u][i],nodes,vis);
    }
}
int solve(int A,vector<vector<int>>B)
{
    vector<vector<int>>nodes(A+1);
    int n=B.size();
    rep(i,0,n)
    {
        nodes[B[i][0]].push_back(B[i][1]);
    }
    vector<bool>vis(A+1);
    dfs(1,nodes,vis);
    rep(i,0,A+1)
    {
        cout<<vis[i]<<" ";
    }
    if(vis[A+1]==true)
    return 1;
    return 0;
}
int main()
{
    cout<<solve(5,{{1, 2} ,{4, 1} ,{2, 4} ,{3, 4} ,{5, 2} ,{1, 3}});
}   