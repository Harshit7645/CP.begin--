#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int M=1e9+7;

int solve(vector<int>&nums)
{
    int n=nums.size();
    queue<int>q;
    int ans=0,cnt=0,cnt1=0,start=0;
    rep(i,0,n)
    {
        if(nums[i]==0)
        cnt++;
        while(cnt>1)
        {
            cnt-=(nums[start]==0);
            start++;
        }
        ans=max(ans,i-start);
    }
    return ans;
}

int main()
{
    vector<int>A={1,1,0,0,1,1,1,0,1};   
    cout<<solve(A);
}   