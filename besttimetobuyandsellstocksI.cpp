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

int solve(vector<int>A)
{
    int n=A.size();
    vector<int>premin(n),postmax(n);
    premin[0]=A[0];
    rep(i,1,n)
    {   
        premin[i]=min(premin[i-1],A[i]);
    }
    postmax[n-1]=A[n-1];
    repr(i,n-2,0)
    {
        postmax[i]=max(postmax[i+1],A[i]);
    }
    int ans=0;
    rep(i,0,n)
    {
        ans=max(ans,postmax[i]-premin[i]);
    }
    return ans;
}

int main()
{
    cout<<solve({1, 4, 5, 2, 4});
}   