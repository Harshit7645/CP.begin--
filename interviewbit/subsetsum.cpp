#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int M=1e9+7;

int solve(vector<int>A,int B)
{
    int n=A.size();
    int sum=0;
    rep(i,0,n)
    sum+=A[i];
    if(B>sum)
    return 0;
    vector<vector<int>>dp(n,vector<int>(sum+1,0));
    rep(i,0,n)
    dp[i][0]=1;
    if(A[0]<=B)
    dp[0][A[0]]=1;
    rep(i,1,n)
    {
        rep(j,1,sum+1)
        {
            if(j>=A[i])
            dp[i][j]=dp[i-1][j-A[i]]|dp[i-1][j];
            else
            dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n-1][B];
}
int main()
{
    cout<<solve({1, 6, 11, 5},11);
}   