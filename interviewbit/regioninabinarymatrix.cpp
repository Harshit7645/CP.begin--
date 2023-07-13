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
int ans;
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};

int dfs(vector<vector<int>>&A,int row,int col)
{
    if(row<0 || col<0 || row>=A.size() || col>=A[0].size() || A[row][col]==0)
    return 0;
    A[row][col]=0;
    int ans=1;
    rep(i,0,8)
    {
        int x=row+dx[i];
        int y=col+dy[i];
        ans+=dfs(A,x,y);
    }
    return ans;
}

int solve(vector<vector<int>>A)
{
    ans=0;
    int n=A.size();
    int m=A[0].size();
    rep(i,0,n)
    {
        rep(j,0,m)
        {
            if(A[i][j]==1)
            ans=max(ans,dfs(A,i,j));
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>>A={{1, 0, 0, 1, 0, 0, 1},
                          {0, 0, 1, 1, 0, 1, 0},
                          {1, 0, 1, 1, 1, 0, 1},
                          {1, 0, 1, 1, 0, 1, 1},
                          {1, 0, 1, 0, 0, 1, 1},
                          {1, 1, 1, 1, 0, 0, 1},
                          {0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 1, 0, 1, 0, 0}};
    cout<<solve(A);
}   