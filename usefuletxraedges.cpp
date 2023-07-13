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

int helper(vector<vector<pair<int,int>>>nodes,int src,int dest,int A)
{
    vector<int>dist(A,INT_MAX);
    queue<int>q;
    dist[src]=0;
    q.push(src);
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto child:nodes[node])
        {
            if(dist[node]+child.second<dist[child.first])
            {
                dist[child.first]=min(dist[child.first],dist[node]+child.second);
                q.push({child.first});
            }
        }
    }
    return dist[dest];
}
int solve(int A,vector<vector<int>>B,int C,int D,vector<vector<int>>E)
{
    vector<vector<pair<int,int>>>nodes(A);
    int n=B.size();
    rep(i,0,n)
    {
        nodes[B[i][0]-1].push_back({B[i][1]-1,B[i][2]});
    }
    // rep(i,1,A+1)
    // cout<<dist[i]<<" ";
    int ans=helper(nodes,C-1,D-1,A);
    //cout<<ans<<" ";
    rep(i,0,E.size())
    {
        nodes[E[i][0]-1].push_back({E[i][1]-1,E[i][2]});
        nodes[E[i][1]-1].push_back({E[i][0]-1,E[i][2]});
        ans=min(ans,helper(nodes,C-1,D-1,A));
        nodes[E[i][0]-1].pop_back();
        nodes[E[i][0]-1].pop_back();
    }
    if(ans!=INT_MAX)
    return ans;
    return -1;
}
int main()
{
    cout<<solve(3,{{1,2,1},{2,3,2}},1,3,{{1,3,2}});
}   