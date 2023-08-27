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
map<pair<int,int>,int>dp;

int recur(int prev,int ind,vector<int>arr1,vector<int>arr2)
{
    if(ind==arr1.size())
    return 0;
    if(dp.find({ind,prev})!=dp.end())
    return dp[{ind,prev}];
    int ans=INT_MAX/2;
    int val=upper_bound(arr2.begin(),arr2.end(),prev)-arr2.begin();
    int ans1=INT_MAX,ans2=INT_MAX;
    if(arr1[ind]>prev)
    ans1=recur(arr1[ind],ind+1,arr1,arr2);
    if(val<arr2.size())
    ans2=recur(arr2[val],ind+1,arr1,arr2)+1;
    ans=min(ans1,ans2);
    return dp[{ind,prev}]=ans;
}
int solve(vector<int>arr1,vector<int>arr2)
{
    int n1=arr1.size();
    int n2=arr2.size();
    sort(arr2.begin(),arr2.end());
    //memset(dp,-1,sizeof(dp));
    dp.clear();
    int ans=recur(INT_MIN,0,arr1,arr2);
    return ans>=INT_MAX/2?-1:ans;
}

int main()
{
    vector<int>arr1 = {1,5,3,6,7};
    vector<int>arr2 = {4,3,1};
    cout<<solve(arr1,arr2);
}   