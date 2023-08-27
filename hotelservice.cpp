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

int bfs(int row,int col,vector<vector<int>>&A)
{
    queue<pair<pair<int,int>,int>>q;
    q.push({{row,col},0});
    int n=A.size(),m=A[0].size();
    vector<vector<bool>>vis(n,vector<bool>(m,false));
    vis[row][col]=true;
    while(!q.empty())
    {
        auto tp=q.front();
        q.pop();
        int dist=tp.second;
        int r=tp.first.first;
        int c=tp.first.second;
        if(A[r][c]==1)
        return dist;
        for(int i=0;i<4;i++)
        {
            int x=r+dx[i];
            int y=c+dy[i];
            if(x<0 || y<0 || x>=n||y>=m || vis[x][y]==true)
            continue;
            q.push({{x,y},dist+1});
            vis[x][y]=true;
        }
    }
    return -1;
}
vector<int>nearestHotel(vector<vector<int>> &A, vector<vector<int>> &B) {
    int n=A.size();
    int m=A[0].size();
    //vector<vector<int>>dist(n,vector<int>(m,0));
    vector<int>ans;
    for(int i=0;i<B.size();i++)
    {
        int val=bfs(B[i][0]-1,B[i][1]-1,A);
        ans.push_back(val);
    }
    return ans;
} 
int main()
{
    vector<vector<int>>A={{0, 0},
                          {1, 0}};
    vector<vector<int>>B={{1, 1},
                          {2, 1},
                          {1, 2}};
    vector<int>ans=nearestHotel(A,B);
    //cout<<"hi";
    rep(i,0,ans.size())
    {
        cout<<ans[i]<<" ";
    }
}