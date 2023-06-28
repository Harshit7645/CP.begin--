#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int M=1e9+7;

int jump(vector<int>&A)
{
    ll n=A.size();
    if(n==1)
    return 0;
    vector<int>dp(n,INT_MAX);
    dp[0]=0;
    rep(i,1,n)
    {
        rep(j,0,i)
        {
            if(i<=j+A[j])
            dp[i]=min(dp[i],dp[j]+1);
        }
    }
    return dp[n-1];
}
int main()
{
    vector<int>A;
    A.push_back(0);
    cout<<jump(A);
}   