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
        string s;
        cin>>s;
        ll sum1=0,sum2=0;
        rep(i,0,3)
        {
            sum1+=s[i]-'0';
        }
        rep(i,3,6)
        {
            sum2+=s[i]-'0';
        }
        if(sum1==sum2)
        PYES;
        else
        PNO;
    } 
}