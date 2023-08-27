#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
const int M=1e9+7;
ll dp[1000005];

int main()
{
    ll n,x;
    cin>>n>>x;
    vector<int>arr(n);
    rep(i,0,n)
    {
        cin>>arr[i];
    }
    dp[0]=1;
    rep(wt,0,x+1)
    {
        rep(i,1,n+1)
        {
            if(wt>=arr[i-1])
            dp[wt]=(dp[wt]+dp[wt-arr[i-1]])%M;
        }
    }
    cout<<dp[x];
}   