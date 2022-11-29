#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int visited[7] = {0,0,0,0,0,0,0};
int a [7][7] ={
{0,1,1,1,0,0,0},
{1,0,1,0,0,0,0},
{1,1,0,1,1,0,0},
{1,0,1,0,1,0,0},
{0,0,1,1,0,1,1},
{0,0,0,0,1,0,0},
{0,0,0,0,1,0,0}};
void dfs(int i)
{
    cout<<i<<" ";
    visited[i]=1;
    rep(j,0,7)
    {
        if(visited[j]==0 && a[i][j]==1)
        {
            dfs(j);
        }
    }
}
int main()
{
    dfs(2);
}