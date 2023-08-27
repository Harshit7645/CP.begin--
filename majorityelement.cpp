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
    map<ll,ll>m;
    rep(i,0,n)
    {
        m[A[i]]++;
    }
    for(auto x:m)
    {
        if(x.second>n/2)
        return x.first;
    }
    return -1;
}
int main()
{
    cout<<solve({2,1,2});
}   