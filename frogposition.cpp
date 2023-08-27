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

double solve(int n,vector<vector<int>>edges,int t,int target)
{
    vector<vector<int>>adj(n+1);
    rep(i,0,edges.size())
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    if(target==1 && n==1)
    return 1.0;
    else if(target==1)
    {
        if(t>=1)
        return 0.0;
        else 
        return 1.0;
    }
    queue<pair<pair<int,int>,double>>q;
    vector<bool>vis(n+1);
    q.push({{1,0},1.0});
    vis[1]=true;
    while(!q.empty())
    {
        auto node=q.front();
        q.pop();
        vis[node.first.first]=true;
        if(node.first.first==target)
        {
            //if(ta)
            if(t>node.first.second && adj[node.first.first].size()<=1)
            return node.second;
            else if(t==node.first.second)
            return node.second;
            else
            return 0;
        }
        for(auto child:adj[node.first.first])
        {
            if(vis[child]==true)
            continue;
            if(node.first.first==1)
            {
                double prob=node.second;
                q.push({{child,node.first.second+1},prob/adj[node.first.first].size()});
            }
            else
            {
                double prob=node.second;
                q.push({{child,node.first.second+1},(double)prob/(1.0*(adj[node.first.first].size()-1))});
            }
        }
    }
    return 0.0;
}

int main()
{
    int n = 9; vector<vector<int>>edges = {{2,1},{3,2},{4,3},{5,3},{6,5},{7,3},{8,4},{9,5}}; int t = 9, target = 1;
    cout<<solve(n,edges,t,target);
}   