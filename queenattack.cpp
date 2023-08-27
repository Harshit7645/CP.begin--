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

vector<vector<int>>ans={};
int dx[8]={1,1,-1,-1,0,-1,1,0};
int dy[8]={1,-1,1,-1,1,0,0,-1};


int recur(int row,int col,int dir,vector<string>&A)
{
    int x=row+dx[dir];
    int y=col+dy[dir];
    int count=0;
    if(x>=0 && y>=0 && x<A.size() && y<A[0].size())
    {
        if(A[x][y]=='1')
        count++;
        else
        count+=recur(x,y,dir,A);
    }
    return count;
}
vector<vector<int>>solve(vector<string>&A)
{
    ans.clear();
    int n=A.size();
    int m=A[0].size();
    ans.resize(n);
    rep(i,0,n)
    {
        ans[i].resize(m);
    }
    rep(k,0,8)
    {
        rep(i,0,n)
        {
            rep(j,0,m)
            {
                ans[i][j]+=recur(i,j,k,A);
            }
        }
    }
    rep(i,0,ans.size())
    {
        rep(j,0,ans[i].size())
        cout<<ans[i][j]<<" ";
        cout<<"\n";
    }
    return ans;
}
int main()
{
    vector<string>A={"111", "111", "111"};
    vector<vector<int>>x=solve(A);
    // rep(i,0,x.size())
    // {
    //     rep(j,0,x[i].size())
    //     cout<<x[i][j]<<" ";
    // }
}   