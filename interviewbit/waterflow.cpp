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

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
void dfs(int x,int y,vector<vector<int>>&mat, vector<vector<int>>&vis)
{
    int n=mat.size();
    int m=mat[0].size();
    vis[x][y]=1;
    for(int i=0;i<4;i++)
    {
        int nr=x+dx[i];
        int nc=y+dy[i];
        if(nr>=0 && nr<n && nc>=0 && nc<m && mat[nr][nc]>=mat[x][y] && vis[nr][nc]==0)
        {
            dfs(nr,nc,mat,vis);
        }
    }
}
int solve(vector<vector<int>>A)
{
    int n=A.size();
    int m=A[0].size();
    vector<vector<int>>blue(n,vector<int>(m,0)),red(n,vector<int>(m,0));  
    rep(i,0,n)
    {
        if(blue[i][0]!=1)
        dfs(i,0,A,blue);
    }
    rep(j,0,m)
    {
        if(blue[0][j]!=1)
        dfs(0,j,A,blue);
    }
    rep(i,0,n)
    {
        if(red[i][m-1]!=1)
        dfs(i,m-1,A,red);
    }
    rep(j,0,m)
    {
        if(red[n-1][j]!=1)
        dfs(n-1,j,A,red);
    }
    int ans=0;
    rep(i,0,n)
    {
        rep(j,0,m)
        {
            if(blue[i][j]==1 && red[i][j]==1)
            ans++;
        }
    }
    return ans;
}
int main()
{
    cout<<solve({{1, 2, 2, 3, 5},{3, 2, 3, 4, 4},{2, 4, 5, 3, 1},{6, 7, 1, 4, 5},{5, 1, 1, 2, 4}});
}   