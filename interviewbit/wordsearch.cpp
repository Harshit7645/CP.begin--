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
bool ok;
void dfs(int row,int col,vector<string>&A,string B,int ind)
{
    if(ok)
    return ;
    if(ind>=B.size())
    {
        ok=true;
        return ;
    }
    rep(i,0,4)
    {
        int x=row+dx[i];
        int y=col+dy[i];
        if(x>=0 && y>=0 && x<A.size() && y<A[0].size() && A[x][y]==B[ind])
        dfs(x,y,A,B,ind+1);
    }
}

int solve(vector<string>A,string B)
{
    ok =false;
    int n=A.size();
    int m=A[0].size();
    int ans=0;
    rep(i,0,n)
    {
        rep(j,0,m)
        {
            if(A[i][j]==B[0])
            dfs(i,j,A,B,1);
        }
    }
    return ok;
}
int main()
{
    cout<<solve({{"ABCE"},{"SFCS"},{"ADEE"}},"CED");
}   