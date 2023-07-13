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
int dfs(int row,int col,vector<vector<int>>&A,vector<vector<bool>>&vis)
{
    if(A[row][col]==3)
    return 1;
    vis[row][col]==true;
    int ans=0;
    rep(i,0,4)
    {
        int x=row+dx[i];
        int y=col+dy[i];
        if(x>=0 && y>=0 && x<A.size() && y<A.size() && vis[x][y]==false && A[x][y]!=0)
        ans=ans|dfs(x,y,A,vis);
    }
    return ans;
}
int solve(vector<vector<int>>A)
{
    int n=A.size();
    vector<vector<bool>>vis(n,vector<bool>(n,false));
    int srcx=0,srcy=0;
    rep(i,0,n)
    {
        rep(j,0,n)
        {
            if(A[i][j]==1)
            {
                srcx=i;
                srcy=j;
            }
        }
    }
    return dfs(srcx,srcy,A,vis);
}   
int main()
{
    vector<vector<int>>A={{1, 3}, {3, 2}};
    cout<<solve(A);
}   