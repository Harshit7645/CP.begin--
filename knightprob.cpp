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

int dx[8]={2,2,1,1,-1,-1,-2,-2};
int dy[8]={1,-1,2,-2,2,-2,1,-1};
int outside=0;

map<pair<pair<int,int>,int>,double>dp;
double bfs(int row,int col,int k,int n)
{
    if(row<0 || col<0 || row>=n || col>=n)
    return 0;
    if(k==0)
    return 1;
    if(dp.find({{row,col},k})!=dp.end())
    return dp[{{row,col},k}];
    double ans=0;
    rep(i,0,8)
    {
        int x=row+dx[i];
        int y=col+dy[i];
        ans+=(bfs(x,y,k-1,n))/8.0;
    }
    return dp[{{row,col},k}]=ans;
}
double solve(int n,int k,int row,int column)
{
    return bfs(row,column,k,n);
}

int main()
{
    cout<<solve(3,1,0,0);
}   