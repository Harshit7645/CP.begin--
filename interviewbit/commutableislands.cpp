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
bool comp(vector<int>&a,vector<int>&b)
{
    return a[2]<b[2];
}
void Union(int u,int v,vector<int>&parent)
{
    int pu=find(parent,u);
    int pv=find(parent,v);
    parent[pu]=pv;
}
int solve(int A,vector<vector<int>>&B)
{
    int n=B.size();
    vector<int>parent(A,-1);
    int ans=0;
    sort(B.begin(),B.end(),comp);
    rep(i,0,n)
    {
        int u=find(parent,B[i][0]-1);
        int v=find(parent,B[i][1]-1);
        if(u!=v)
        {
            Union(u,v,parent);
            ans+=B[i][2];
        }
    }
    return ans;
}

int main()
{
    int A=4;
    vector<vector<int>>B={  {1, 2, 1},
                            {2, 3, 4},
                            {1, 4, 3},
                            {4, 3, 2},
                            {1, 3, 10} };
    cout<<solve(A,B);
}   