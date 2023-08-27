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

bool solve(string A,vector<string>B)
{
    int n=A.length();
    int sz=B.size();
    map<string,ll>m;
    rep(i,0,sz)
    m[B[i]]++;
    if (n == 0) 
    return true;
    for (int i=1; i<=n; i++)
    {
        if (m[A.substr(0, i)] && solve(A.substr(i,n-i),B))
        return true;
    }
    return false;
}
int main()
{
    cout<<solve("khack",{"h","k","hack"});
}   