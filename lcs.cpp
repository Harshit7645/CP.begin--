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

int solve(string A,string B)
{
    int n=A.length(),m=B.length();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    rep(i,1,n+1)
    {
        rep(j,1,m+1)
        {
            if(A[i-1]==B[j-1])
            dp[i][j]=dp[i-1][j-1]+1;
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
}

int main()
{
    string A = "abbcdgf";
    string B = "bbadcgf";
    cout<<solve(A,B);
}   