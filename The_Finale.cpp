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

ll fact(ll n)
{
    ll ans=1;
    rep(i,1,n+1)
    {
        ans=(ans*i)%M;
    }
    return ans%M;
}
ll nCr(ll n,ll r)
{
    if (r > n)
        return 0;
    if (r == 0 || r == n)
        return 1;
    return nCr(n - 1, r - 1) + nCr(n - 1, r);
}
ll power(ll a,ll b)
{
    ll result=1;
    while(b>0)
    {
        if(b%2==1)
        result*=a;
        a*=a;
        b/=2;
    }
    return result;
}


int main()
{
    ll n,m;
    cin>>n>>m;
    ll a[n+1],b[m+1];
    rep(i,1,n+1){
        cin>>a[i];
    }
    rep(j,1,m+1)
    {
        cin>>b[j];
    }
    a[0]=0;
    b[0]=0;
    vector<vector<ll>>dp(n+1,vector<ll>(m+1,0));
    dp[0][0]=0;
    rep(i,0,n+1)
    {
        rep(j,0,m+1)
        {
            if(i*j==0)
            continue;
            if(a[i]==b[j])
            dp[i][j]=((dp[i-1][j]+dp[i][j-1])%M+1)%M;
            else
            dp[i][j]=((dp[i-1][j]+dp[i][j-1])%M+(M-dp[i-1][j-1])%M)%M;
        }
    }
    cout<<dp[n][m]+1<<"\n";
}   