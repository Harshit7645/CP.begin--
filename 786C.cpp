#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        ll n=s.length(),l0=-1,r1=-1,c=0;
        rep(i,0,n)
        {
            if(s[i]=='0')
            {
                l0=i;
                break;
            }
        }
        rep(i,0,n)
        {
            if(s[i]=='1')
            r1=i;
        }
        if(l0==-1)
        l0=n-1;
        if(r1==-1)
        r1=0;
        cout<<abs(r1-l0)+1<<endl;
    }
}