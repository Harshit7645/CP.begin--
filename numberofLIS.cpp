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

int solve(vector<int>nums)
{
    int n=nums.size();
    vector<int>dp(n,1),cnt(n,1);
    int maxm=0;
    rep(i,0,n)
    {
        rep(j,0,i)
        {
            if(nums[j]<nums[i])
            {
                if(dp[j]+1>dp[i])
                {
                    dp[i]=dp[j]+1;
                    cnt[i]=0;
                }
                if(dp[j]+1==dp[i])
                cnt[i]+=cnt[j];
            }   
        }
        maxm=max(maxm,dp[i]);
    }
    // rep(i,0,n)
    // {
    //     cout<<dp[i]<<" ";
    // }
    // cout<<"\n";
    // rep(i,0,n)
    // {
    //     cout<<cnt[i]<<" ";
    // }
    // cout<<"\n";
    int ans=0;
    rep(i,0,n)
    {
        if(maxm==dp[i])
        ans+=cnt[i];
    }
    return ans;
}
int main()
{
    cout<<solve({1,2,4,3,5,4,7,2});
}   