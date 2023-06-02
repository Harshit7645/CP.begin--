#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
ll fact(ll n)
{
    if(n>12)
    return INT_MAX;
    ll ans=1;
    rep(i,1,n+1)
    {
        ans*=i;
    }
    return ans;
}
vector<int>ans;
vector<int>backtrack(vector<int>&A,ll B)
{
    int n=A.size();
    if(n==0 || B>fact(n))
    {
        return ans;
    }
    int pos=B/fact(n-1);
    ans.push_back(A[pos]);
    B=B%(fact(n-1));
    A.erase(A.begin()+pos);
    backtrack(A,B);
    return ans;
}
vector<int>solve(int A,ll B)
{
    ans.clear();
    vector<int>req;
    rep(i,1,A+1)
    {
        req.push_back(i);
    }
    backtrack(req,B-1);
    return ans;
}
int main()
{
    vector<int>asn=solve(100000,603828039791327040);
    rep(i,0,asn.size())
    cout<<asn[i]<<" ";
}   