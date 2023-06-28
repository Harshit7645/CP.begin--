#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int M=1e9+7;

int solve(int A,int B,int C)
{
    vector<vector<int>>dp(A+1,vector<int>(C+1));
    dp[0][0]=1;
    rep(i,1,A+1)
    {
        rep(j,1,C+1)
        {
            dp[i][j]=dp[i-1][j-1]+dp[i][j-1];   
            if(j-B>=1)
            dp[i][j]-=dp[i-1][j-B-1];
        }
    }
    return dp[A][C];
}
int main()
{
    cout<<solve(2,4,5);
}   