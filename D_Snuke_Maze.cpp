#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"No\n"
#define PYES cout<<"Yes\n"
#define vll vector<ll>;
ll M=1e9+7;
string snuke="snuke";
ll dp[505][505];
ll dx[4]={1,0,-1,0};
ll dy[4]={0,1,0,-1};
void recur(ll row,ll col,vector<string>&A,ll ind,vector<vector<bool>>&vis)
{
    if(vis[row][col]==true)
    return ;
    vis[row][col]=true;
    rep(i,0,4)
    {
        int x=row+dx[i];
        int y=col+dy[i];
        if(x>=0 && x<A.size() && y>=0 && y<A[0].size() && vis[x][y]==false && snuke[(ind+1)%5]==A[x][y])
        {
            recur(x,y,A,ind+1,vis);
        }
    }
}
int main()
{
    ll n,m;
    cin>>n>>m;
    vector<string>A(n);
    rep(i,0,n)
    {
        cin>>A[i];
    }
    vector<vector<bool>>vis(n,vector<bool>(m,false));
    if(A[0][0]!='s')
    {   
        PNO;
        return 0;
    }
    recur(0,0,A,0,vis);
    if(vis[n-1][m-1])
    PYES;
    else
    PNO;
}   