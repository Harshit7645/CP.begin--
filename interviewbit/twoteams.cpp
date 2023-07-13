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

int solve(int A,vector<vector<int>>B)
{
    int n=B.size();
    vector<vector<int>>edges(A+1);
    vector<int>col(A+1,-1);
    col[1]=0;
    rep(i,0,n)
    {
        edges[B[i][0]].push_back(B[i][1]);
        edges[B[i][1]].push_back(B[i][0]);
    }
    queue<pair<int,int>>q;
    q.push({1,0});
    int f=0;
    while(!q.empty())
    {
        int node=q.front().first;
        int color=q.front().second;
        q.pop();
        for(auto child:edges[node])
        {
            if(col[child]==color)
            return 0;
            if(col[child]==-1)
            {
                col[child]=1-color;
                q.push({child,col[child]});
            }
        }
    }
    return 1;
}
int main()
{
    int A = 4;
    vector<vector<int>>B={{1, 4},{3,1},{4,3},{2, 1}};
    cout<<solve(A,B);
}   