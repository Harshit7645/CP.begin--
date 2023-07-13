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

int dfs(vector<vector<int>>&nodes,int node,int &ht)
{
    int maxm=0;
    for(auto child:nodes[node])
    {
        int next = dfs(nodes,child,ht);
        ht=max(ht,maxm+next);
        maxm=max(maxm,next);
    }
    return 1+maxm;
}
int solve(vector<int>A)
{
    int n=A.size();
    if(n==1)
    return 0;
    vector<vector<int>>nodes(n);
    int src=-1;
    rep(i,0,n)
    {
        if(A[i]==-1)
        src=i;
        else
        {
            nodes[A[i]].push_back(i);
        }
    }
    int ht=0;
    dfs(nodes,src,ht);
    return ht;
}
int main()
{
    cout<<solve({-1, 0, 1, 1, 2, 0, 5, 0, 3, 0, 0, 2, 3, 1, 12, 14, 0, 5, 9, 6, 16, 0, 13, 4, 17, 2, 1, 22, 14, 20, 10, 17, 0, 32, 15, 34, 10, 19, 3, 22, 29, 2, 36, 16, 15, 37, 38, 27, 31, 12, 24, 29, 17, 29, 32, 45, 40, 15, 35, 13, 25, 57, 20, 4, 44, 41, 52, 9, 53, 57, 18, 5, 44, 29, 30, 9, 29, 30, 8, 57, 8, 59, 59, 64, 37, 6, 54, 32, 40, 26, 15, 87, 49, 90, 6, 81, 73, 10, 8, 16});
}   