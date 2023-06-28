#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int M=1e9+7;

int solve(vector<vector<int>>A)
{
    int m=A.size();
    int n=A[0].size();
    vector<vector<int>>dp(m,vector<int>(n,0));
    rep(i,0,m)
    {
        if(A[i][0]==0)
        dp[i][0]=1;
        else
        break;
    }
    rep(j,0,n)
    {
        if(A[0][j]==0)
        dp[0][j]=1;
        else
        break;
    }
    rep(i,1,m)
    {
        rep(j,1,n)
        {
            if(A[i-1][j]==0 && A[i][j-1]==0 && A[i][j]==0)
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
            else if(A[i-1][j]==0 && A[i][j]==0)
            dp[i][j]=dp[i-1][j];
            else if(A[i][j-1]==0 && A[i][j]==0)
            dp[i][j]=dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}
int main()
{
    cout<<solve({{0,0,0},{0,1,0},{0,0,0}});
}   