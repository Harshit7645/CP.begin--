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

vector<int> solve(vector<int>A,vector<int>B,int cost)
{
    int n=A.size();
    vector<int>ans;
    vector<vector<int>>dp(2,vector<int>(n+1,0));
    dp[0][0]=0;
    dp[1][0]=cost;
    rep(i,1,n+1)
    {
        dp[0][i]=min(dp[0][i-1],dp[1][i-1])+A[i-1];
        dp[1][i]=min(dp[0][i-1]+cost,dp[1][i-1])+B[i-1];
        //dp[0][i]=min(dp[0][i],dp[1][i]);
    }
    // rep(i,0,2)
    // {
    //     rep(j,0,n+1)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    rep(i,0,n+1)
    {
        ans.push_back(min(dp[0][i],dp[1][i]));
    }
    return ans;
}
int main()
{
    vector<int>ans=solve({40,20},{30,25},5);
    rep(i,0,ans.size())
    cout<<ans[i]<<" ";
}   