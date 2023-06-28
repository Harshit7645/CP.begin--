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
    int n,x;
    cin>>n>>x;
    vector<int>A(n);
    rep(i,0,n)
    {
        cin>>A[i];
    }
    vector<int>dp(x+1);
    dp[0]=1;
    rep(i,1,n+1)
    {
        rep(j,0,x+1)
        {
            if(A[i-1]<=j)
            dp[j]=(dp[j]+dp[j-A[i-1]])%M;
        }
    }
    cout<<dp[x]<<"\n";
}   