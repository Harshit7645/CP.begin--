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

bool solve(string s,string p)
{
    int n=s.length();
    int m=p.length();
    vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
    dp[0][0]=true;
    rep(j,1,m+1)
    {
        if(p[j-1]=='*')
        dp[0][j]=dp[0][j-1];
    }
    rep(i,1,n+1)
    {
        rep(j,1,m+1)
        {
            if(s[i-1]==p[j-1] || p[j-1]=='?')
            dp[i][j]=dp[i-1][j-1];
            else if(p[j-1]=='*')
            dp[i][j]=dp[i][j-1]|dp[i-1][j];
        }
    }
    // rep(i,0,n+1)
    // {
    //     rep(j,0,m+1)
    //     cout<<dp[i][j]<<" ";
    //     cout<<"\n";
    // }
    return dp[n][m];
}
int main()
{
    cout<<solve("aaaaaaaaaaaa","*");
}   