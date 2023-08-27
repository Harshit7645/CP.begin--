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
int dp[155][155][155];
int recur(string A,string B,string C,int ind1,int ind2,int cnt)
{
    if(dp[ind1][ind2][cnt]!=-1)
    return dp[ind1][ind2][cnt];
    if(ind1==A.length() && ind2==B.length() && cnt==C.length())
    {
        return 1;
    }
    int ans1=0,ans2=0;
    if(ind1<A.length() && A[ind1]==C[cnt])
    {
        ans1=recur(A,B,C,ind1+1,ind2,cnt+1);
    }
    if(ind2<B.length() && B[ind2]==C[cnt])
    {
        ans2=recur(A,B,C,ind1,ind2+1,cnt+1);
    }
    return dp[ind1][ind2][cnt]=ans1|ans2;
}
int solve(string A,string B,string C)
{
    memset(dp,-1,sizeof(dp));
    return recur(A,B,C,0,0,0);
}
int main()
{
    string A = "aabcc";
    string B = "dbbca";
    string C = "aadbbcbcac";
    cout<<solve(A,B,C);
}   