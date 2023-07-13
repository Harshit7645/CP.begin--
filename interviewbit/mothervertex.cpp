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
    }
    int ver=0;
    rep(i,0,A)
    {
        if(vis[i]==false)
        {
            dfs(i,nodes,vis);
            ver=i;
            cout<<ver<<" ";
        }
    }
    cout<<"\n";
    fill(vis.begin(),vis.end(),false);
    dfs(ver,nodes,vis);
    rep(i,0,A)
    {
        if(vis[i]==false)
        return 0;
    }
    return 1;
}
int main()
{
    int A=3;
    vector<vector<int>>B={{1,3},{2,3},{3,2}};
    cout<<solve(A,B);
}   