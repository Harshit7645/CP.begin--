#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
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
        ll noz=0;
        rep(i,0,n)
        {
            if(s[i]=='0')
            noz++;
        }
        ll m1=0,m2=0,m3=0;
        m1=noz*(n-noz);
        ll c=0;
        rep(i,0,n)
        {
            if(s[i]=='0')
            c++;
            else
            {
                m2=max(m2,c);
                //cout<<c<<" ";
                c=0;
            }
        }
        m2=max(m2,c)*max(m2,c);
        c=0;
        //cout<<"\n";
        rep(i,0,n)
        {
            if(s[i]=='1')
            c++;
            else
            {
                m3=max(m3,c);
                //cout<<c<<" ";
                c=0;
            }
        }
        m3=max(m3,c)*max(m3,c);
        m1=max(m1,m2);
        //cout<<"\n";
        cout<<max(m1,m3)<<endl;
    }
}