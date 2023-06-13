#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
#define MAXN 105 
int dp[MAXN];
int nck[MAXN][MAXN];
int height[MAXN];
int M=1e9+7;
ll fact(ll n)
{
    ll ans=1;
    rep(i,1,n+1)
    {
        ans*=i;
    }
    return ans;
}
ll nCr(ll n,ll k)
{
    if (k > n)
        return 0;
    if (n <= 1)
        return 1;
    if (k == 0)
        return 1;
 
    if (nck[n][k] != -1)
        return nck[n][k];
 
    int answer = (nCr(n - 1, k - 1)%M + nCr(n - 1, k)%M)%M;
    nck[n][k] = answer;
    return answer;
}

int getleftsubtree(int n)
{
    if(n==1)
    return 0;
    int ht=height[n];
    int numele=pow(2,ht);
    int last=n-numele+1;
    if(last>=numele/2)
    return numele-1;
    else
    return numele-1-(numele/2-last);
}
int diffheaps(int n)
{
    if(n<=1)
    return 1;
    if(dp[n]!=-1)
    return dp[n];
    int left=getleftsubtree(n);
    dp[n]=(((nCr(n-1,left)%M)*diffheaps(left))%M*diffheaps(n-1-left))%M;
    return dp[n];
}
int solve(int A)
{
    rep(i,0,A+1)
    {
        dp[i]=-1;
    }
    rep(i,0,A+1)
    {
        rep(j,0,A+1)
        nck[i][j]=-1;
    }
    int currheight=-1,currpow2=1;
    rep(i,1,A+1)
    {
        if(currpow2==i)
        {
            currpow2*=2;
            currheight++;
        }
        height[i]=currheight;
    }
    return diffheaps(A)%M;
}
int main()
{
    cout<<solve(39);
}   