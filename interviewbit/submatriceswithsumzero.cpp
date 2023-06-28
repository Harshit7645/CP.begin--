#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;

int count(vector<int>&A)
{
    int n=A.size();
    unordered_map<int,int>m;
    int ans=0,sum=0;
    rep(i,0,n)
    {   
        sum+=A[i];
        if(sum==0)
        ans++;
        if(m.find(sum)!=m.end())
        ans+=m[sum];
        m[sum]++;
    }
    return ans;
}
int solve(vector<vector<int>>&A)
{
    int n=A.size();
    int m=A[0].size();
    int ans=0;
    rep(i,0,n)
    {
        vector<int>curr(m,0);
        rep(j,i,n)
        {
            rep(k,0,m)
            {
                curr[k]+=A[j][k];
            }
        }
        ans+=count(curr);
    }
    return ans;
}
int main()
{
    cout<<solve({0,0});
}   