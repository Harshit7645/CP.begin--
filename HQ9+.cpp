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
    string s;
    cin>>s;
    ll n=s.length();
    ll flag=0;
    rep(i,0,n)
    {
        if(s[i]=='H'|| s[i]=='Q' || s[i]=='9')
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
    cout<<"NO\n";
    else
    cout<<"YES\n";
}