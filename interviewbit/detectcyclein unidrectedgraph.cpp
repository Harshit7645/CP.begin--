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

int find(vector<int>&parent,int node)
{
    if(parent[node]==-1)
    return node;
    return find(parent,parent[node]);
}

void Union(int u,int v,vector<int>&parent)
{
    int pu=find(parent,u);
    int pv=find(parent,v);
    parent[pu]=pv;
}

int solve(int A,vector<vector<int>>&B)
{
    vector<int>parent(A,-1);
    int n=B.size();
    rep(i,0,n)
    {
        int pu=find(parent,B[i][0]-1);
        int pv=find(parent,B[i][1]-1);
        if(pu==pv)
        return 1;
        else
        {
            Union(pu,pv,parent);
        }
    }
    return 0;
}
int main()
{
    int A=3;
    vector<vector<int>>B={{1, 2},
        {1,3}};
    cout<<solve(A,B);
}   