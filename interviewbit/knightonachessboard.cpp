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

int solve(int A,int B,int C,int D,int E,int F)
{
    queue<pair<pair<int,int>,int>>q;
    vector<vector<bool>>vis(A+1,vector<bool>(B+1,false));
    q.push({{C,D},0});
    vis[C][D]=true;
    while(!q.empty())
    {
        auto tp=q.front();
        q.pop();
        int row=tp.first.first;
        int col=tp.first.second;
        int dist=tp.second;
        if(row==E && col==F)
        return dist;
        rep(i,0,8)
        {
            int x=row+dx[i];
            int y=col+dy[i];
            if(x<=0 || y<=0 || x>A || y>B || vis[x][y]==true)
            continue;
            q.push({{x,y},dist+1});
            vis[x][y]=true;
        }
    }    
    return -1;
}
int main()
{
    cout<<solve(3,3,1,1,8,8);
}   