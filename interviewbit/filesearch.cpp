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

void dfs(int node,vector<vector<int>>&nodes,vector<bool>&vis)
{
    if(vis[node]==true)
    return ;
    vis[node]=true;
    for(auto child:nodes[node])
    {
        dfs(child,nodes,vis);
    }
}

int solve(int A,vector<vector<int>>B)
{
    int n=B.size();
    vector<vector<int>>nodes(A);
    vector<bool>vis(A,false);
    rep(i,0,n)
    {
        nodes[B[i][0]-1].push_back(B[i][1]-1);
        nodes[B[i][1]-1].push_back(B[i][0]-1);
    }
    int ans=0;
    rep(i,0,A)
    {
        if(vis[i]==false)
        {
            ans++;
            dfs(i,nodes,vis);
        }
    }
    return ans;
}
int main()
{
    cout<<solve(4,{{1,2},{3,4}});
}   