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

vector<int> solve(vector<int>nums,int k)
{
    int n=nums.size();
    priority_queue<pair<int,int>>pq;
    vector<int>ans;
    int maxm=INT_MIN;
    rep(i,0,n)
    {   
        if(i<k-1)
        {
            pq.push({nums[i],i});
        }
        else if(i==k-1)
        {
            pq.push({nums[i],i});
            ans.push_back(pq.top().first);
        }
        else
        {   
            pq.push({nums[i],i});
            while(!pq.empty())
            {
                ll val=pq.top().first;
                ll ind=pq.top().second;
                if(i-k>=ind)
                pq.pop();
                else
                break;
            }
            ans.push_back(pq.top().first);
        }
    }
    return ans;
}

int main()
{
    vector<int>ans=solve({1,3,-1,-3,5,3,6,7},3);
    rep(i,0,ans.size())
    cout<<ans[i]<<" ";  
}   