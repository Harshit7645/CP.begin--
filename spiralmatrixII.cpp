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
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

vector<vector<int>>solve(int A)
{
    vector<vector<int>>ans(A,vector<int>(A,0));
    vector<vector<bool>>vis(A,vector<bool>(A,false));
    int row=0,col=0,dir=0;
    rep(i,1,A*A+1)
    {
        ans[row][col]=i;
        vis[row][col]=true;
        int x=row+dx[dir];
        int y=col+dy[dir];
        if(x>=0 && y>=0 && x<A && y<A && !vis[x][y])
        {
            row=x;
            col=y;
        }
        else
        {
            dir=(dir+1)%4;
            row+=dx[dir];
            col+=dy[dir];
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>>ans;
    ans=solve(5);
    rep(i,0,ans.size())
    {
        rep(j,0,ans[i].size())
        cout<<ans[i][j]<<" ";
        cout<<"\n";
    }
}   
