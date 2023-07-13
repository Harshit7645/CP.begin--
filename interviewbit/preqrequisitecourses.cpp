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
bool dfs(int node,vector<vector<int>>&nodes,vector<bool>&vis,vector<bool>&inStack)
{
    if(inStack[node]==true)
    return true;
    if(vis[node]==true)
    return false;
    vis[node]=true;
    inStack[node]=true;
    for(auto child:nodes[node])
    {
        if(dfs(child,nodes,vis,inStack))
        return true;
    }
    inStack[node]=false;
    return false;
}
int solve(int A,vector<int>B,vector<int>C)
{
    int n=B.size();
    vector<vector<int>>nodes(A);
    vector<bool>vis(A,false),inStack(A,false);
    rep(i,0,n)
    {
        nodes[B[i]-1].push_back(C[i]-1);
    }
    rep(i,0,A)
    {
        if(dfs(i,nodes,vis,inStack))
        return 0;
    }
    return 1;
}
int main()
{
    int A=3;
    vector<int>B={1,2};
    vector<int>C={2,3};
    cout<<solve(A,B,C);
}   