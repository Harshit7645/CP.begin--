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

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
void dfs(vector<vector<char>>&A,int row,int col,vector<vector<bool>>&vis)
{
    if(vis[row][col]==true)
    return ;
    vis[row][col]=true;
    rep(i,0,4)
    {
        int x=row+dx[i];
        int y=col+dy[i];
        if(x>=0 && x<A.size() && y>=0 && y<A[0].size() && A[x][y]=='O')
        dfs(A,x,y,vis);
    }
}
void solve(vector<vector<char>>&A)
{
    int n=A.size();
    int m=A[0].size();
    vector<vector<bool>>vis(n,vector<bool>(m,false));
    rep(i,0,n)
    {
        if(A[i][0]=='O' && vis[i][0]==false)
        dfs(A,i,0,vis);
        if(A[i][m-1]=='O' && vis[i][m-1]==false)
        dfs(A,i,m-1,vis);
    }
    rep(j,0,m)
    {
        if(A[0][j]=='O' && vis[0][j]==false)
        dfs(A,0,j,vis);
        if(A[n-1][j]=='O' && vis[n-1][j]==false)
        dfs(A,n-1,j,vis);
    }
    rep(i,0,n)
    {
        rep(j,0,m)
        {
            if(vis[i][j]==false)
            A[i][j]='X';
        }
    }
    return ;
}
int main()
{
    vector<vector<char>>x={ {'X', 'X', 'X', 'X'}
                           ,{'X', 'O', 'O', 'X'}
                           ,{'X', 'X', 'O', 'X'}
                           ,{'X', 'O', 'X', 'X'}};
    solve(x);
    rep(i,0,x.size())
    {
        rep(j,0,x[i].size())
        cout<<x[i][j]<<" ";
        cout<<endl;
    }
}   