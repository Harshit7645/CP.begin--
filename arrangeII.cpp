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

int recur(int ind,string &s,int k,vector<vector<int>>&dp)
{
    int n=s.length();
    if(ind>=n && k<=0)
    return 0;
    else if(ind>=n || k<=0)
    return 1e9;
    if(dp[ind][k]!=-1)
    return dp[ind][k];
    int ans=1e9;
    rep(i,ind,n)
    {
        int black=0,white=0;
        rep(j,ind,i+1)
        {
            black+=(s[j]=='B');
            white+=(s[j]=='W');
        }
        ans=min(ans,black*white + recur(i+1,s,k-1,dp));
    }
    return dp[ind][k]=ans;
}

int solve(string A,int B)
{
    int n=A.length();
    if(B>n)
    return -1;
    else if(B==n)
    return 0;
    vector<vector<int>>dp(n+1,vector<int>(B+1,-1));
    int ans=recur(0,A,B,dp);
    return (ans==1e9)?-1:ans;
}

int main()
{
    cout<<solve("WWWB",2);
}   