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

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

void dfs(int row,int col,vector<string>&A,vector<vector<bool>>&vis)
{
    if(vis[row][col]==true)
    return;
    vis[row][col]=true;
    rep(i,0,4)
    {
        int x=row+dx[i];
        int y=col+dy[i];
        if(x<0 || y<0 || x>=A.size() || y>=A[0].length() || vis[x][y]==true || A[x][y]=='O')
        continue;
        dfs(x,y,A,vis);
    }
}
int solve(vector<string>A)
{
    int n=A.size();
    int m=A[0].length();
    vector<vector<bool>>vis(n,vector<bool>(m,false));
    int ans=0;
    rep(i,0,n)
    {
        rep(j,0,m)
        {
            if(A[i][j]=='X' && vis[i][j]==false)
            {
                ans++;
                dfs(i,j,A,vis);
            }
        }
    }
    return ans;
}

int main()
{
    vector<string>A={"OOOXOOO"
                    ,"OOXXOXO"
                    ,"OXOOOXO" };
                    cout<<solve(A);
}   