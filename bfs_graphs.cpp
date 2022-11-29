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
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    queue<int>q;
    int i=0;
    cout<<i<<" ";
    visited[i]=1;
    q.push(i);
    while(q.size()!=0)
    {
        int node=q.front();
        q.pop();
        rep(j,0,7)
        {
            if(a[node][j]==1 && visited[j]==0)
            {
                cout<<j<<" ";
                visited[j]=1;
                q.push(j);
            }
        }
    }
}