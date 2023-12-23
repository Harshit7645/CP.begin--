#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int M=998244353;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll tt=1;
    //cin>>tt;
    while(tt--)
    {
        ll n;
        cin>>n;
        ll arr[n];
        rep(i,0,n)
        {
            cin>>arr[i];
            arr[i]=arr[i]%2;
        }
        ll dp[n+1][3][3][3];
        memset(dp,0,sizeof(dp));
        dp[0][2][2][2]=1;
        rep(i,0,n)
        {
            rep(x,0,3)
            {
                rep(y,0,3)
                {
                    rep(z,0,3)
                    {
                        dp[i+1][x][y][z]=dp[i][x][y][z];
                    }
                }
            }
            rep(x,0,3)
            {
                rep(y,0,3)
                {
                    rep(z,0,3)
                    {
                        if(y==2 || z==2 || (y+z+arr[i])%2==0)
                        dp[i+1][y][z][arr[i]]=(dp[i+1][y][z][arr[i]]+dp[i][x][y][z])%M;
                    }
                }
            }
        }
        ll ans=0;
        rep(i,0,2)
        {
            rep(j,0,2)
            {
                rep(k,0,2)
                {
                    ans=(ans+dp[n][i][j][k])%M;
                }
            }
        }
        //ans=(ans%M+M)%M;
        cout<<ans<<"\n";
    }
}   