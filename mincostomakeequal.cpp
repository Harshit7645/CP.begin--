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
long long minCost(vector<int>&nums,vector<int>&cost)
{
    ll n=nums.size();
    vector<pair<ll,ll>>v;
    rep(i,0,n)
    {
        v.push_back({nums[i],cost[i]});
    }
    sort(v.begin(),v.end());
    vector<ll>precost(n);
    precost[0]=v[0].second;
    rep(i,1,n)
    {
        precost[i]=precost[i-1]+v[i].second;
    }
    vector<ll>dp(n,0);
    rep(i,0,n)
    {
        dp[0]=dp[0]+abs(v[i].first-v[0].first)*v[i].second;
    }
    ll ans=dp[0];
    rep(i,1,n)
    {
        ll gap=v[i].first-v[i-1].first;
        dp[i]=dp[i-1]+gap*(precost[i-1]-precost[n-1]+precost[i-1]);
        ans=min(ans,dp[i]);
    }
    return ans;
}

int main()
{
    vector<int>A={1,3,5,2};
    vector<int>B={2,3,1,14};
    cout<<minCost(A,B);
}   