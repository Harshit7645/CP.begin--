#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int M=1003;

int dp[155][155][2];
int recur(int st,int end,int isTrue,string A)
{
    if(st>end)
    return 0;
    if(st==end)
    {
        if(isTrue==1)
        return (A[st]=='T');
        else
        return (A[st]=='F');
    }
    if(dp[st][end][isTrue]!=-1)
    return dp[st][end][isTrue];
    int ans=0;
    rep(i,st+1,end)
    {
        int leftrue=recur(st,i-1,1,A);
        int leftfalse=recur(st,i-1,0,A);
        int rightrue=recur(i+1,end,1,A);
        int rightfalse=recur(i+1,end,0,A);
        if(isTrue)
        {
            if(A[i]=='&')
            ans=(ans+(leftrue*rightrue)%M)%M;
            else if(A[i]=='^')
            ans=(ans+ ((leftrue*rightfalse)%M + (leftfalse*rightrue)%M)%M)%M;
            else
            ans=(ans+ (((leftrue*rightrue)%M + (leftrue*rightfalse)%M)%M + (leftfalse*rightrue)%M)%M)%M;
        }
        else
        {
            if(A[i]=='&')
            ans=(ans+ (((leftfalse*rightfalse)%M + (leftrue*rightfalse)%M)%M + (leftfalse*rightrue)%M)%M)%M;
            else if(A[i]=='^')
            ans=(ans+ ((leftrue*rightrue)%M + (leftfalse*rightfalse)%M)%M)%M;
            else
            ans=(ans+(leftfalse*rightfalse)%M)%M;
        }
    }
    return dp[st][end][isTrue]=ans;
}
int solve(string A)
{
    int n=A.length();
    memset(dp,-1,sizeof(dp));
    return recur(0,n-1,1,A);
}
int main()
{
    cout<<solve("T^T^T^F|F");
}   