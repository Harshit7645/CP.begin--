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
int ans;

void dfs(vector<int>&A,int good,vector<vector<int>>&nodes,int node,int C)
{   
    if(A[node-1]==1)
    good++;
    if(good>C)
    {
        return ;
    }
    int cnt=0;
    for(auto child:nodes[node])
    {
        cnt++;
        dfs(A,good,nodes,child,C);
    }
    if(cnt==0)
    ans++;
}
int solve(vector<int>A,vector<vector<int>>B,int C)
{
    int n=A.size();
    ans=0;
    vector<vector<int>>nodes(n+1);
    rep(i,0,B.size())
    {
        nodes[B[i][0]].push_back(B[i][1]);
    }
    dfs(A,0,nodes,1,C);
    return ans;
}
int main()
{
    cout<<solve({0, 1, 0, 1, 1, 1},{ {1, 2},{1, 5},{1, 6},{2, 3},{2, 4}},1);
}   