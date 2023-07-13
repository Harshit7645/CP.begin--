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
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};

string solve(int A,int B,int C,int D,vector<int>E,vector<int>F)
{
    string yes="YES";
    string no="NO";
    vector<vector<bool>>isBlocked(A+1,vector<bool>(B+1,false));
    rep(i,0,A+1)
    {
        rep(j,0,B+1)
        {
            rep(k,0,C)
            {
                if((i-E[k])*(i-E[k])+(j-F[k])*(j-F[k])<=D*D)
                {
                    isBlocked[i][j]=true;
                    break;
                }
            }
        }
    }
    // rep(i,0,A+1)
    // {
    //     rep(j,0,B+1)
    //     {
    //         cout<<isBlocked[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    if(isBlocked[0][0])
    return no;
    queue<pair<int,int>>q;
    q.push({0,0});
    isBlocked[0][0]=true;
    while(!q.empty())
    {
        pair<int,int>node=q.front();
        q.pop();
        if(node.first==A && node.second==B)
        return yes;
        rep(i,0,8)
        {
            int x=node.first+dx[i];
            int y=node.second+dy[i];
            if(x>=0 && y>=0 && x<=A && y<=B && isBlocked[x][y]==false)
            {
                q.push({x,y});
                isBlocked[x][y]=true;
            }
        }
    }
    return no;
}
int main()
{
    int x = 2;
    int y = 3;
    int N = 1;
    int R = 1;
    vector<int>A = {2};
    vector<int>B = {3};
    string ans=solve(x,y,N,R,A,B);
    cout<<ans;
}   