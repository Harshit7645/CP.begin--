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
    return parent[node]=find(parent,parent[node]);
}

void Union(int u,int v,vector<int>&parent)
{
    int pu=find(parent,u);
    int pv=find(parent,v);
    parent[pu]=pv;
}

int solve(vector<int>A,vector<int>B,vector<vector<int>>C)
{
    int n=A.size();
    vector<int>parent(n,-1);
    rep(i,0,C.size())
    {
        int parx=find(parent,A[C[i][0]-1]);
        int pary=find(parent,A[C[i][1]-1]);
        Union(parx,pary,parent);
    }
    rep(i,0,n)
    {
        if(A[i]!=B[i])
        {
            if(find(parent,A[i])!=find(parent,B[i]))
            return 0;
        }
    }
    return 1;
}

int main()
{
    cout<<solve({7, 29, 51, 54, 24, 27, 70, 46, 49, 21, 1, 65, 10, 11, 4, 63, 69, 30, 43, 32, 71, 33, 3, 40, 14, 12, 31, 39, 26, 48, 13, 67, 64, 34, 17, 36, 16, 58, 6, 5, 15, 35, 9, 56, 55, 25, 61, 50, 22, 45, 72, 57, 47, 53, 44, 37, 62, 20, 38, 8, 18, 28, 23, 42, 66, 59, 41, 2, 60, 52, 68, 19},{36, 29, 2, 54, 21, 48, 72, 26, 41, 24, 39, 65, 10, 51, 4, 63, 47, 45, 31, 32, 18, 15, 3, 61, 14, 37, 53, 1, 25, 27, 5, 67, 49, 60, 11, 7, 46, 43, 68, 9, 33, 16, 44, 56, 13, 50, 40, 35, 20, 30, 6, 59, 69, 58, 55, 12, 62, 22, 70, 8, 64, 34, 23, 42, 66, 71, 57, 38, 28, 52, 17, 19},
    {{3,4}});
}   