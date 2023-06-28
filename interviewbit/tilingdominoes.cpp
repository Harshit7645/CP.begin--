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
        result=(result*a)%M;
        a=(a*a)%M;
        b/=2;
    }
    return result;
}

int solve(int A)
{
    if(A==0)
    return 1;
    vector<int>B(A+1),dp(A+1);
    dp[0]=1;
    dp[1]=0;
    B[0]=0;
    B[1]=1;
    rep(i,2,A+1)
    {
        dp[i]=(dp[i-2]+(2*B[i-1])%M)%M;
        B[i]=(B[i-2]+dp[i-1])%M;
    }
    return dp[A]%M;
}
int main()
{
    cout<<solve(6);
}   