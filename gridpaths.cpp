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

int main()
{
    ll n;
    cin>>n;
    vector<string>v(n);
    rep(i,0,n)
    {
        cin>>v[i];
    }
    if(v[0][0]=='*' || v[n-1][n-1]=='*')
    {
        cout<<"0\n";
        return 0;
    }
    vector<vector<ll>>dp(n,vector<ll>(n,0));
    dp[n-1][n-1]=1;
    repr(i,n-2,0)
    {
        if(v[n-1][i]=='*')
        dp[n-1][i]=0;
        else
        dp[n-1][i]=dp[n-1][i+1];
    }
    repr(i,n-2,0)
    {
        if(v[i][n-1]=='*')
        dp[i][n-1]=0;
        else
        dp[i][n-1]=dp[i+1][n-1];
    }
    repr(i,n-2,0)
    {
        repr(j,n-2,0)
        {
            if(v[i][j]=='*')
            dp[i][j]=0;
            else
            dp[i][j]=(dp[i+1][j]+dp[i][j+1])%M;
        }
    }
    cout<<dp[0][0]<<"\n";
}   