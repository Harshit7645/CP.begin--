#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int M=1e9+7;

int dp[101][10001];
int recur(int eggs,int floors)
{
    if(floors<=1)
    return floors;
    if(eggs==0)
    return 0;
    else if(eggs==1)
    return floors;
    if(dp[eggs][floors]!=-1)
    return dp[eggs][floors];
    int mn=INT_MAX;
    rep(k,1,floors+1)
    {
        int temp=max(recur(eggs-1,k-1),recur(eggs,floors-k));
        mn=min(mn,temp);
    }
    return dp[eggs][floors]=mn+1;
}
int solve(int A,int B)
{
    memset(dp,-1,sizeof(dp));
    return recur(A,B);
}
int main()
{
    cout<<solve(100,10000);
}   