#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    cin>>s;
    ll n=s.length();
    ll c=1,f=0;
    vector<ll>v;
    rep(i,0,n-1)
    {
        if(s[i]==s[i+1])
        c++;
        else
        {
            v.push_back(c);
            c=1;
        }
        if(i==n-2)
        v.push_back(c);
    }
    sort(v.begin(),v.end());
    if(v[v.size()-1]>=7)
    PYES;
    else
    PNO;
    // for(auto x:v)
    // cout<<x<<" ";
}