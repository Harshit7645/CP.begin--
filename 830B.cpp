#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=b;i>=a;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
typedef vector<ll> vll;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        string s;
        cin>>s;
        ll parts=0;
        rep(i,0,n-1)
        {
            if(s[i]!=s[i+1])
            parts++;
        }
        if(n==1)
        {
            cout<<"0\n";
            continue;
        }
        if(s[0]=='0' && s[n-1]=='0' && parts>=1)
        cout<<parts-1<<"\n";
        else if(s[0]=='0' && s[n-1]=='1' && parts>=1)
        cout<<parts-1<<"\n";
        else
        cout<<parts<<"\n";
    } 
}