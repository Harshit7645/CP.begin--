#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define PNO cout<<"No\n"
#define PYES cout<<"Yes\n"
#define vll vector<ll>;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //ll s;
    string s;
    cin>>s;
    map<char,ll>m;
    ll n=s.length();
    rep(i,0,n)
    {
        if(m[s[i]]==0)
        m[s[i]]++;
    }
    ll ans=0;
    for(auto x:m)
    {
        ans+=x.second;
    }
    //cout<<ans<<endl;
    if(ans%2==0)
    cout<<"CHAT WITH HER!\n";
    else
    cout<<"IGNORE HIM!\n";
}