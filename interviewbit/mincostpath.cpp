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
int solve(int A,int B,vector<string>C)
{
    vector<vector<int>>dist(A,vector<int>(B,INT_MAX));
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
    string s="DRUL";
    pq.push({0,0,0});
    dist[0][0]=0;
    while (!pq.empty())
    {
        auto a=pq.top();
        int row=a[1];
        int col=a[2];
        int dis=a[0];
        pq.pop();
        rep(i,0,4)
        {
            int x=row+dx[i];
            int y=col+dy[i];
            if(x<0 || y<0 || x>=A || y>=B)
            continue;
            int cost=0;
            if(C[row][col]!=s[i])
            cost=1;
            if(cost+dis<dist[x][y])
            {
                dist[x][y]=cost+dis;
                pq.push({dist[x][y],x,y});
            }
        }
    }
    return dist[A-1][B-1];
}
int main()
{
    int A = 3;
    int B = 3;
    vector<string>C = {"RRR","DDD","UUU"};
    cout<<solve(A,B,C);
}   