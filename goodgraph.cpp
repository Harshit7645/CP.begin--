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
void dfs(vector<vector<int>>&nodes,int node,vector<bool>&vis)
{
    if(vis[node]==true)
    return ;
    vis[node]=true;
    for(auto child:nodes[node])
    {
        dfs(nodes,child,vis);
    }
}
int solve(vector<int>A)
{
    int n=A.size();
    vector<vector<int>>nodes(n+1);
    rep(i,1,n+1)
    {
        nodes[i].push_back(A[i-1]);
    }
    vector<bool>vis(n+1,false);
    vis[0]=true;
    int ans=0;
    rep(i,1,n+1)
    {
        if(vis[i]==false)
        {
            ans++;
            dfs(nodes,i,vis);
        }
    }
    return ans-1;
}
int main()
{
    cout<<solve({3,1,3,1});
}   