#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int M=1e9+7;
int getmaxArea(vector<int>&heights)
{
    int n=heights.size();
    stack<int>s;
    int maxarea=0;
    rep(i,0,n)
    {
        if(s.empty() || heights[s.top()]<=heights[i])
        s.push(i);
        else
        {
            int tp=s.top();
            s.pop();
            maxarea=max(maxarea,heights[tp]*(s.empty()?i:i-s.top()-1));
        }
        while(!s.empty())
        {
            int tp=s.top();
            s.pop();
            maxarea=max(maxarea,heights[tp]*(s.empty()?i:i-s.top()-1));
        }
    }
    return maxarea;
}
int solve(vector<vector<int>>A)
{   
    int n=A.size();
    int m=A[0].size();
    int maxarea=0;
    vector<int>curr(m);
    curr=A[0];
    maxarea=getmaxArea(curr);
    rep(i,1,n)
    {
        rep(j,0,m)
        {
            if(A[i][j]==0)
            curr[j]=0;
            else
            curr[j]+=1;
        }
        maxarea=max(maxarea,getmaxArea(curr));
    }
    return maxarea;
}
int main()
{
    cout<<solve({{1,1,1},{0,1,1},{1,0,0}});
}   